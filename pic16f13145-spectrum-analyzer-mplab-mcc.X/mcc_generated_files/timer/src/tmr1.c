/**
  * TMR1 Generated Driver File
  *
  * @file tmr1.c
  *
  * @ingroup tmr1
  *
  * @brief Driver implementation for the TMR1 driver
  *
  * @version TMR1 Driver Version 4.1.0
  * 
  * @version Package Version 5.2.1
  */
/*
© [2026] Microchip Technology Inc. and its subsidiaries.

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

/**
 * Section: Included Files
*/

#include <xc.h>
#include "../tmr1.h"

static volatile uint16_t timer1ReloadVal;
static void (*TMR1_OverflowCallback)(void);
static void TMR1_DefaultOverflowCallback(void);
static void (*TMR1_GateCallback)(void);
static void TMR1_DefaultGateCallback(void);

void TMR1_Initialize(void)
{
    T1CONbits.TMR1ON = 0U;             // TMRON disabled

    T1GCON = (uint8_t)((0 << _T1GCON_T1GGO_POSN)   // T1GGO done
        | (0 << _T1GCON_T1GSPM_POSN)   // T1GSPM disabled
        | (0 << _T1GCON_T1GTM_POSN)   // T1GTM disabled
        | (0 << _T1GCON_T1GPOL_POSN)   // T1GPOL low
        | (0 << _T1GCON_T1GE_POSN));  // T1GE disabled

    T1GATE = (uint8_t)((0 << _T1GATE_GSS_POSN));  // GSS T1GPPS

    T1CLK = (uint8_t)((2 << _T1CLK_CS_POSN));  // CS FOSC

    TMR1H = (uint8_t)0xFC;              // Period 25.03125us; Timer clock 32000000 Hz;
    TMR1L = (uint8_t)0xDF;

    
    uint16_t readValLow = (uint16_t)TMR1L;
    uint16_t readValHigh = (uint16_t)((uint16_t)TMR1H << 8U);
    
    timer1ReloadVal = (uint16_t)(readValHigh | readValLow);
	
    TMR1_OverflowCallback = TMR1_DefaultOverflowCallback;
    TMR1_GateCallback = TMR1_DefaultGateCallback;

	PIR1bits.TMR1IF = 0U;
	PIE1bits.TMR1IE = 1U;
	PIR1bits.TMR1GIF = 0U;
	
    T1CON = (uint8_t)((1 << _T1CON_TMR1ON_POSN)   // TMR1ON enabled
        | (0 << _T1CON_T1RD16_POSN)   // T1RD16 disabled
        | (1 << _T1CON_nT1SYNC_POSN)   // nT1SYNC do_not_synchronize
        | (0 << _T1CON_CKPS_POSN));  // CKPS 1:1
}

void TMR1_Deinitialize(void)
{
    T1CONbits.TMR1ON = 0U;             // TMRON disabled
    
    T1CON = (uint8_t)0x0;
    T1GCON = (uint8_t)0x0;
    T1GATE = (uint8_t)0x0;
    T1CLK = (uint8_t)0x0;
    TMR1H = (uint8_t)0x0;
    TMR1L = (uint8_t)0x0;

    PIR1bits.TMR1IF = 0U;
    PIE1bits.TMR1IE = 0U;
    PIR1bits.TMR1GIF = 0U;
    PIE1bits.TMR1GIE = 0U;
}

void TMR1_Start(void)
{   
    T1CONbits.TMR1ON = 1U;
}

void TMR1_Stop(void)
{ 
    T1CONbits.TMR1ON = 0U;
}

uint16_t TMR1_CounterGet(void)
{
    uint16_t readVal;
    uint16_t readValHigh;
    uint16_t readValLow;
    	
    readValLow = (uint16_t)TMR1L;
    readValHigh = (uint16_t)((uint16_t)TMR1H << 8);
    
    readVal = (uint16_t)(readValHigh | readValLow);

    return readVal;
}

/* cppcheck-suppress misra-c2012-8.7 */
void TMR1_CounterSet(uint16_t timerVal)
{
    if (1U == T1CONbits.nT1SYNC)
    {
        bool onState = T1CONbits.TMR1ON;
      
        TMR1H = (uint8_t)(timerVal >> 8U);
        TMR1L = (uint8_t)timerVal;
       
        T1CONbits.TMR1ON = (uint8_t)onState;
    }
    else
    {      
        TMR1H = (uint8_t)(timerVal >> 8U);
        TMR1L = (uint8_t)timerVal;
    }
}

void TMR1_PeriodSet(uint16_t periodVal)
{
    timer1ReloadVal = periodVal;
}

uint16_t TMR1_PeriodGet(void)
{
    return timer1ReloadVal;
}

void TMR1_Reload(void)
{
    /* cppcheck-suppress misra-c2012-8.7 */
    TMR1_CounterSet(timer1ReloadVal);
}

uint16_t TMR1_MaxCountGet(void)
{
    return TMR1_MAX_COUNT;
}

void TMR1_SinglePulseAcquisitionStart(void)
{
    T1GCONbits.T1GGO = 1U;
}

uint8_t TMR1_GateStateGet(void)
{
    return (uint8_t)(T1GCONbits.T1GVAL);
}

void TMR1_OverflowInterruptEnable(void)
{
    PIE1bits.TMR1IE = 1U;
}

void TMR1_OverflowInterruptDisable(void)
{
    PIE1bits.TMR1IE = 0U;
}

bool TMR1_GateEventStatusGet(void)
{
    return (PIR1bits.TMR1GIF);
}

void TMR1_GateEventStatusClear(void)
{
    PIR1bits.TMR1GIF = 0U;
}

void TMR1_OverflowISR(void)
{
    /* cppcheck-suppress misra-c2012-8.7 */
    TMR1_CounterSet(timer1ReloadVal);

    // The ticker is set to 1 -> The callback function gets called every time this ISR executes.
    if(NULL != TMR1_OverflowCallback)
    {
        TMR1_OverflowCallback();
    }
    PIR1bits.TMR1IF = 0U;
}

void TMR1_Tasks(void)
{
    if(1U == PIR1bits.TMR1GIF)
    { 
        if(NULL != TMR1_GateCallback)
        {
            TMR1_GateCallback();
        }
        PIR1bits.TMR1GIF = 0U;        
    }   
}
void TMR1_OverflowCallbackRegister(void (*CallbackHandler)(void))
{
    TMR1_OverflowCallback = CallbackHandler;
}


void TMR1_GateCallbackRegister(void (*CallbackHandler)(void))
{
    TMR1_GateCallback = CallbackHandler;
}

static void TMR1_DefaultOverflowCallback(void)
{
    // Default overflow callback
}

static void TMR1_DefaultGateCallback(void)
{
    // Default Gate callback
}
/**
  End of File
*/
