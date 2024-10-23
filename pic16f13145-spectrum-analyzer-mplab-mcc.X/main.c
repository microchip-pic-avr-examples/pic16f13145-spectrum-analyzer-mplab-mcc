 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.2
 *
 * @version Package Version: 3.1.2
*/

/*
© [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"
#include "matrix.h"
#include "fft.h"

#define NO_SAMPLES      64


volatile adc_result_t adcVal;
volatile uint16_t indexData = 0; 
bool bufferFull = false;

int16_t imaginaryNumbers[NO_SAMPLES];
int16_t realNumbers[NO_SAMPLES];
int16_t realNumbersFilt[NO_SAMPLES/4 + 1] = {0};


const uint8_t normalizedValues[162] = 
{
    0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	2,	2,	2,
    2,	2,	2,	2,	2,	2,	2,	3,	3,	3,	3,	3,	3,	3,	3,	3,	3,	4,	4,	4,	4,	4,  4,
    4,	4,	4,	4,	5,	5,	5,	5,	5,	5,	5,	5,	5,	5,	6,	6,	6,	6,	6,	6,   6,	6,	6,
    6,	7,	7,	7,	7,	7,	7,	7,	7,	7,	7,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	9,	9,
    9,	9,	9,	9,	9,	9,	9,	9,	10,	10,	10,	10,	10,	10,	10,	10,	10,	10,	11,	11,	11,	11,	11,
    11,	11,	11,	11,	11,	12,	12,	12,	12,	12,	12,	12,	12,	12,	12,	13,	13,	13,	13,	13,	13,	13,	13,
    13,	13,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15, 16    
};


void CONVERSION_RESULT(void)
{   
    adcVal = ADC_ConversionResultGet(); 
    
    realNumbers[indexData] = 8 * (adcVal - 465);
    /*
     OPAMP power supply is 3.0V and the audio signal is centered to 3.0V / 2
     The 10-bit ADC is configured to use VDD = 3.3 V as reference. 
     To eliminate the DC offset introduced by OPAMP circuitry, the following formula is used: 1024 * 3 / (3.3 * 2) = 465
    */
    imaginaryNumbers[indexData++] = 0;

    if(indexData == NO_SAMPLES)
    {
       // Stop ADC data acquisition
       TMR1_Stop(); 
       bufferFull = true; 
       indexData = 0;
    } 
} 

void groupedValues(int16_t data[])
{
    data[10] = data[10] + data[11];
    data[11] = data[12] + data[13];
    data[12] = data[14] + data[15] + data[16];
    data[13] = data[17] + data[18] + data[19];
    data[14] = data[20] + data[21] + data[22] + data[23];
    data[15] = data[24] + data[25] + data[26] + data[27];
    data[16] = data[28] + data[29] + data[30] + data[31];
}

void Normalize_Values(int16_t data[], int16_t data_filt[])
{
    groupedValues(data);
    for(uint8_t i = 1; i <= 16; i++)
    {
        if(data[i] > 160)
            data[i] = 160;
        data[i] = normalizedValues[data[i]];
        data_filt[i] =  0.8 * data_filt[i] + 0.2 * data[i];
        
    }
}


void Square_Root(int16_t realNumbers[], int16_t imaginaryNumbers[])
{
    uint32_t place, root;
    for (uint8_t k=0; k < NO_SAMPLES >> 1; k++)
    {
        realNumbers[k] =    (realNumbers[k] * realNumbers[k] + 
                            imaginaryNumbers[k] * imaginaryNumbers[k]);
        // Now we find the square root of realNumbers[k] using a very
        // fast (but compiler dependent) integer approximation:
        // (adapted from: http://www.codecodex.com/wiki/Calculate_an_integer_square_root)
        place = 0x40000000;
        root = 0;

        if (realNumbers[k] >= 0) // Ensure we don't have a negative number
        {
            while (place > realNumbers[k])
                place = place >> 2; 

            while (place)  
            {  
                if (realNumbers[k] >= root + place)  
                {  
                    realNumbers[k] -= root + place;  
                    root += place * 2;  
                }  
                root = root >> 1;  
                place = place >> 2;  
            }
        } 
        realNumbers[k] = root;

    }
}

/*
    Main application
*/

int main(void)
{

    SYSTEM_Initialize();
    ADC_ConversionDoneCallbackRegister(CONVERSION_RESULT);

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts 
    // Use the following macros to: 

    // Enable the Global Interrupts 
    INTERRUPT_GlobalInterruptEnable(); 

    // Disable the Global Interrupts 
    //INTERRUPT_GlobalInterruptDisable(); 

    // Enable the Peripheral Interrupts 
    INTERRUPT_PeripheralInterruptEnable(); 

    // Disable the Peripheral Interrupts 
    //INTERRUPT_PeripheralInterruptDisable(); 
    
    CLBSWINLbits.CLBSWIN0 = 1; // SPI routed to SPI_to_WS2812 CLB circuit
    __delay_ms(100); 
    
    while (1)
    {     
        if(bufferFull == true) 
        {   
            fix_fft(realNumbers, imaginaryNumbers, 6);
            Square_Root(realNumbers, imaginaryNumbers);
            Normalize_Values(realNumbers,realNumbersFilt);

            Draw_Matrix(&realNumbersFilt[0]);
            
            bufferFull = false; // Start sampling process again
            TMR1_Start();
        }
      
    }
   
}