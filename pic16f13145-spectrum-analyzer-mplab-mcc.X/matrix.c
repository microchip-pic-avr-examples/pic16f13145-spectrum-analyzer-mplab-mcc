/*
    (c) 2024 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                                  Includes                                  //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include "matrix.h"



////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                        Private (static) definitions                        //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////  


static void Write_LED_Pixel(const color_t *frame) 
{
    SPI1_Open(Custom_SPI); 
    SPI1_BufferWrite((uint8_t*)frame, 3);
    SPI1_Close(); 
}


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                             Public definitions                             //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////
//


void Draw_Matrix(int16_t *realNumbers)
{
    uint8_t counter = 0;
    uint8_t barIndex = 0;

    for(uint16_t i = 0; i < NUMBER_OF_LEDS; i++)
    {
        if(i % 16 == 0) // one bar complete
        {
            
            counter = 0;
            barIndex = i / 16;
            
        }
        if((i/16 )% 2) // odd bar
        {
            if(counter < realNumbers[(i  / 16) + 1]) // write from down to up LEDs
            {
                Write_LED_Pixel(&barColors[barIndex]);
            }
            else
            {
                Write_LED_Pixel(&barColors[BLACK]);
            }
            counter++;
        }
        else // even bar
        {
            if(counter < 16 - realNumbers[(i / 16) + 1]) // write from up to down LEDs
            {
                Write_LED_Pixel(&barColors[BLACK]);
            }
            else
            {
                Write_LED_Pixel(&barColors[barIndex]);
            }
            counter++;   
        }

    }
}



void LEDs_OFF(void)
{
    for(uint16_t i = 0; i < NUMBER_OF_LEDS; i++)
    {
        Write_LED_Pixel(&barColors[BLACK]);
    }
}





