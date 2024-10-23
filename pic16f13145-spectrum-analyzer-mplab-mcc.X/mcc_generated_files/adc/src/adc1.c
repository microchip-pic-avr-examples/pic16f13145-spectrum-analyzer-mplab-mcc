/**
 * ADC1 Generated Driver File
 * 
 * @file adc1.c
 * 
 * @ingroup  adc1
 * 
 * @brief This file contains the API implementations for the ADC1 driver.
 *
 * @version ADC1 Driver Version 3.0.0
 * 
 * @version ADC1 Package Version 2.0.0
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

// Section: Included Files

#include <xc.h>
#include "../adc1.h"
#include "../adc_types.h"
  

static void (*ADC1_ConversionDoneCallback)(void);
static void (*ADC1_ThresholdCallback)(void);
static bool adc1_busy_status;

// Section: ADC Module APIs

void ADC1_Initialize(void)
{
    // Disable ADC Module
    ADCON0bits.ADON = ADC_BIT_DISABLE;
    ADCON0 = (1 << _ADCON0_ADON_POSITION)	/* ADON enabled(1) */
			|(0 << _ADCON0_ADCONT_POSITION)	/* ADCONT disabled(0) */
			|(0 << _ADCON0_ADCS_POSITION)	/* ADCS FOSC(0) */
			|(1 << _ADCON0_ADFM_POSITION)	/* ADFM right(1) */
			|(0 << _ADCON0_GO_nDONE_POSITION);	/* GO_nDONE stop(0) */;
    ADCON1 = (0 << _ADCON1_ADDSEN_POSITION)	/* ADDSEN disabled(0) */
			|(0 << _ADCON1_PCSC_POSITION)	/* PCSC internal sampling capacitor and external i/o pin(0) */
			|(0 << _ADCON1_ADGPOL_POSITION)	/* ADGPOL digital_low(0) */
			|(0 << _ADCON1_ADIPEN_POSITION)	/* ADIPEN disabled(0) */
			|(0 << _ADCON1_ADPPOL_POSITION);	/* ADPPOL VSS(0) */;
    ADCON2 = (0 << _ADCON2_ADMD_POSITION)	/* ADMD Basic_mode(0) */
			|(1 << _ADCON2_ADACLR_POSITION)	/* ADACLR enabled(1) */
			|(1 << _ADCON2_ADCRS_POSITION)	/* ADCRS 0x1(1) */
			|(0 << _ADCON2_ADPSIS_POSITION);	/* ADPSIS ADRES(0) */;
    ADCON3 = (0 << _ADCON3_ADTMD_POSITION)	/* ADTMD disabled(0) */
			|(0 << _ADCON3_ADSOI_POSITION)	/* ADSOI ADGO not cleared(0) */
			|(1 << _ADCON3_ADCALC_POSITION);	/* ADCALC Actual result vs setpoint(1) */;
    ADCLK = (15 << _ADCLK_ADCS_POSITION);	/* ADCS FOSC/32(15) */;
    ADCG1A = (0 << _ADCG1A_CGA0_POSITION)	/* CGA0 disabled(0) */
			|(0 << _ADCG1A_CGA1_POSITION)	/* CGA1 disabled(0) */
			|(0 << _ADCG1A_CGA2_POSITION)	/* CGA2 disabled(0) */
			|(0 << _ADCG1A_CGA4_POSITION)	/* CGA4 disabled(0) */
			|(0 << _ADCG1A_CGA5_POSITION);	/* CGA5 disabled(0) */;
    ADCG1B = (0 << _ADCG1B_CGB4_POSITION)	/* CGB4 disabled(0) */
			|(0 << _ADCG1B_CGB5_POSITION)	/* CGB5 disabled(0) */
			|(0 << _ADCG1B_CGB6_POSITION)	/* CGB6 disabled(0) */
			|(0 << _ADCG1B_CGB7_POSITION);	/* CGB7 disabled(0) */;
    ADCG1C = (0 << _ADCG1C_CGC0_POSITION)	/* CGC0 disabled(0) */
			|(0 << _ADCG1C_CGC1_POSITION)	/* CGC1 disabled(0) */
			|(0 << _ADCG1C_CGC2_POSITION)	/* CGC2 disabled(0) */
			|(0 << _ADCG1C_CGC3_POSITION)	/* CGC3 disabled(0) */
			|(0 << _ADCG1C_CGC4_POSITION)	/* CGC4 disabled(0) */
			|(0 << _ADCG1C_CGC5_POSITION)	/* CGC5 disabled(0) */
			|(0 << _ADCG1C_CGC6_POSITION);	/* CGC6 disabled(0) */;
    ADLTHL = (0 << _ADLTHL_LTH_POSITION);	/* LTH 0x0(0) */;
    ADLTHH = (0 << _ADLTHH_LTH_POSITION);	/* LTH 0x0(0) */;
    ADUTHL = (0 << _ADUTHL_UTH_POSITION);	/* UTH 0x0(0) */;
    ADUTHH = (0 << _ADUTHH_UTH_POSITION);	/* UTH 0x0(0) */;
    ADSTPTL = (0 << _ADSTPTL_STPT_POSITION);	/* STPT 0x0(0) */;
    ADSTPTH = (0 << _ADSTPTH_STPT_POSITION);	/* STPT 0x0(0) */;
    ADACCU = (0 << _ADACCU_ACC_POSITION);	/* ACC 0x0(0) */;
    ADACCH = (0 << _ADACCH_ACC_POSITION);	/* ACC 0x0(0) */;
    ADACCL = (0 << _ADACCL_ACC_POSITION);	/* ACC 0x0(0) */;
    ADRESH = (0 << _ADRESH_ADRES_POSITION);	/* ADRES 0x0(0) */;
    ADRESL = (0 << _ADRESL_ADRES_POSITION);	/* ADRES 0x0(0) */;
    ADCNT = (0 << _ADCNT_ADCNT_POSITION);	/* ADCNT 0x0(0) */; 
    ADRPT = (0 << _ADRPT_ADRPT_POSITION);	/* ADRPT 0x0(0) */;       
    ADCAP = (0 << _ADCAP_CAP_POSITION);	/* CAP Additional uC disabled(0) */;
    ADPCH = (1 << _ADPCH_PCH_POSITION);	/* PCH ANA1(1) */; 
    ADACQL = (0 << _ADACQL_ACQ_POSITION);	/* ACQ 0x0(0) */;  
    ADACQH = (0 << _ADACQH_ACQ_POSITION);	/* ACQ 0x0(0) */; 
    ADPREL = (0 << _ADPREL_PRE_POSITION);	/* PRE 0x0(0) */; 
    ADPREH = (0 << _ADPREH_PRE_POSITION);	/* PRE 0x0(0) */;
    ADREF = (0 << _ADREF_ADPREF_POSITION);	/* ADPREF VDD(0) */;    
    ADACT = (3 << _ADACT_ADACT_POSITION);	/* ADACT TMR1(3) */; 
    ADSTAT =(0 << _ADSTAT_ADMATH_POSITION);	/* ADMATH registers not updated(0) */;   
    
    // Configure interrupt handlers    
    ADC1_ConversionDoneCallback = NULL;
    // Configure threshold interrupt handlers
    ADC1_ThresholdCallback = NULL;
    // Clear busy status
    adc1_busy_status = false;
    
    // Clear the ADC interrupt flag
    PIR6bits.ADIF = ADC_BIT_DISABLE;
    // Conversion done interrupt enable/disable.
    PIE6bits.ADIE = ADC_BIT_ENABLE;
    // Clear the ADC Threshold interrupt flag
    PIR6bits.ADTIF = ADC_BIT_DISABLE;
    // Threshold interrupt enable/disable.
    PIE6bits.ADTIE = ADC_BIT_DISABLE;
    ADCON0 = (1 << _ADCON0_ADON_POSITION)	/* ADON enabled(1) */
			|(0 << _ADCON0_ADCONT_POSITION)	/* ADCONT disabled(0) */
			|(0 << _ADCON0_ADCS_POSITION)	/* ADCS FOSC(0) */
			|(1 << _ADCON0_ADFM_POSITION)	/* ADFM right(1) */
			|(0 << _ADCON0_GO_nDONE_POSITION);	/* GO_nDONE stop(0) */;
}

void ADC1_Deinitialize(void)
{
    // Set all the ADC registers to power-on reset values
    ADCON0 = 0x0;
    PIR6bits.ADIF = ADC_BIT_DISABLE;
    // Disabling ADC1 interrupt.
    PIE6bits.ADIE = ADC_BIT_DISABLE;
    //Clear the ADC Threshold interrupt flag
    PIR6bits.ADTIF = ADC_BIT_DISABLE;
    // Disabling ADC1 threshold interrupt.
    PIE6bits.ADTIE = ADC_BIT_DISABLE;
    ADCON1 = 0x0;
    ADCON2 = 0x0;
    ADCON3 = 0x0;
    ADCLK = 0x0;
    ADCG1A = 0x0;
    ADCG1B = 0x0;    
    ADCG1C = 0x0;
    ADLTHL = 0x0;
    ADLTHH = 0x0;
    ADUTHL = 0x0;
    ADUTHH = 0x0;
    ADSTPTL = 0x0;
    ADSTPTH = 0x0;
    ADACCU = 0x0;
    ADACCH = 0x0;
    ADACCL = 0x0;
    ADRESH = 0x0;
    ADRESL = 0x0;
    ADCNT = 0x0;
    ADRPT = 0x0;
    ADCAP = 0x0;
    ADPCH = 0x0;
    ADACQL = 0x0;
    ADACQH = 0x0;
    ADPREL = 0x0;
    ADPREH = 0x0;
    ADREF = 0x0;
    ADACT = 0x0;
    ADSTAT = 0x0;
}

void ADC1_Enable(void)
{
    ADCON0bits.ADON = ADC_BIT_ENABLE;
}

void ADC1_Disable(void)
{
    ADCON0bits.ADON = ADC_BIT_DISABLE;
}

void ADC1_ChannelSelect(adc_channel_t channel)
{
   ADPCH = channel;  
}

void ADC1_ConversionStart(void)
{
    ADCON0bits.GO_nDONE = ADC_BIT_ENABLE;
}

bool ADC1_IsConversionDone(void)
{
    return ((bool)(!ADCON0bits.GO_nDONE));
}

void ADC1_ConversionStop(void)
{
    ADCON0bits.GO_nDONE = ADC_BIT_DISABLE;
}


adc_result_t ADC1_ConversionResultGet(void)
{
    return ((adc_result_t)((ADRESH << 8U) + ADRESL));
}

void ADC1_ComputationModeSet(adc_computation_mode_t computationMode)
{
    ADCON2bits.ADMD = computationMode;
}

void ADC1_ThresholdModeSet(adc_threshold_mode_t thresholdMode)
{
    ADCON3bits.ADTMD = thresholdMode;
}

void ADC1_SampleRepeatCountSet(adc_repeat_count_t repeatCount)
{
    ADRPT = repeatCount;
}
void ADC1_UpperThresholdSet(adc_threshold_t upperThreshold)
{
    ADUTHH = (uint8_t) ((uint16_t)upperThreshold >> 8U);
    ADUTHL = (uint8_t) upperThreshold;
}

void ADC1_LowerThresholdSet(adc_threshold_t lowerThreshold)
{
    ADLTHH = (uint8_t) ((uint16_t)lowerThreshold >> 8U);
    ADLTHL = (uint8_t) lowerThreshold;
}

adc_accumulate_t ADC1_AccumulatedResultGet(void)
{
    return (adc_accumulate_t)((ADACCU << 16U)+(ADACCH << 8U) + ADACCL);
}

adc_result_t ADC1_ChannelSelectAndConvert(adc_channel_t channel)
{
    // Selects the A/D channel
    ADPCH = channel;  
    // Disables the continuous mode
    ADCON0bits.ADCONT = ADC_BIT_DISABLE;

    // Starts the conversion
    ADCON0bits.GO_nDONE = ADC_BIT_ENABLE;

    // Waits for the conversion to finish
    while (true == ADCON0bits.GO_nDONE)
    {
    }
    
    // Conversion finished, returns the result
    return ((adc_result_t)((ADRESH << 8U) + ADRESL));
}

void ADC1_StopOnInterruptEnable(void)
{
    ADCON3bits.ADSOI = ADC_BIT_ENABLE;
}

void ADC1_StopOnInterruptDisable(void)
{
    ADCON3bits.ADSOI = ADC_BIT_DISABLE;
}

void ADC1_SampleCapacitorDischarge(void)
{
     ADPCH = ADC_CHANNEL_VSS;
}

void ADC1_AcquisitionTimeSet(uint16_t acquisitionValue)
{
    ADACQH = (uint8_t)(acquisitionValue >> 8U);
    ADACQL = (uint8_t)(acquisitionValue);
}

void ADC1_PrechargeTimeSet(uint16_t prechargeTime)
{
    ADPREH = (uint8_t)(prechargeTime >> 8U);
    ADPREL = (uint8_t)(prechargeTime);
}

adc_repeat_count_t ADC1_CurrentConversionCountGet(void)
{
    return ((adc_repeat_count_t)ADCNT);
}

void ADC1_AccumulatorClear(void)
{
    ADCON2bits.ADACLR = ADC_BIT_ENABLE;
}

bool ADC1_IsAccumulatorClearComplete(void)
{
    return ((bool)(!ADCON2bits.ADACLR));
}

bool ADC1_HasAccumulatorOverflowed(void)
{
    return ADSTATbits.ADAOV;
}

bool ADC1_IsBusy(void)
{
    return adc1_busy_status;
}

void ADC1_BusyStatusSet(bool status)
{
    adc1_busy_status = status;
}

adc_result_t ADC1_FilterValueGet(void)
{
    return ((adc_result_t)((ADFLTRH << 8U) + ADFLTRL));
}

adc_result_t ADC1_PreviousResultGet(void)
{
    return ((adc_result_t)((ADPREVH << 8U) + ADPREVL));
}

void ADC1_SetPointDefine(adc_threshold_t setPoint)
{
    ADSTPTH = (uint8_t) ((uint16_t)setPoint >> 8U);
    ADSTPTL = (uint8_t) setPoint;
}

adc_result_t ADC1_ErrorCalculationGet(void)
{
    return (adc_result_t)((ADERRH << 8U) + ADERRL);
}

void ADC1_DoubleSamplingEnable(void)
{
    ADCON1bits.ADDSEN = ADC_BIT_ENABLE;
}

void ADC1_DoubleSamplingDisable(void)
{
    ADCON1bits.ADDSEN = ADC_BIT_DISABLE;
}

void ADC1_ContinuousConversionEnable(void)
{
    ADCON0bits.ADCONT = ADC_BIT_ENABLE;
}

void ADC1_ContinuousConversionDisable(void)
{
    ADCON0bits.ADCONT = ADC_BIT_DISABLE;
}

bool ADC1_IsErrorGreaterThanUpperThreshold(void)
{
    return ADSTATbits.ADUTHR;
}

bool ADC1_IsErrorLesserThanLowerThreshold(void)
{
    return ADSTATbits.ADLTHR;
}

adc_conversion_stage_t ADC1_ConversionStageStatusGet(void)
{
    return (adc_conversion_stage_t)ADSTATbits.ADSTAT;
}

void ADC1_AutoTriggerSourceSet(adc_trigger_source_t triggerSource)
{
    ADACT = triggerSource;
}

void ADC1_ErrorCalculationModeSet(adc_calculation_mode_t errorCalculationMode)
{
    ADCON3bits.ADCALC = errorCalculationMode;    
}    

void ADC1_CalculationRightShiftSet(uint8_t rightShiftValue)
{
    ADCON2bits.ADCRS = rightShiftValue;
}

uint8_t ADC1_ResolutionGet(void)
{
    return ADC_RESOLUTION;
}

void ADC1_ConversionDoneInterruptFlagClear(void)
{
    PIR6bits.ADIF = ADC_BIT_DISABLE;
}

void ADC1_ThresholdInterruptFlagClear(void)
{
    PIR6bits.ADTIF = ADC_BIT_DISABLE;
}

bool ADC1_IsConversionDoneInterruptFlagSet(void)
{
    return PIR6bits.ADIF;
}

bool ADC1_IsThresholdInterruptFlagSet(void)
{
    return PIR6bits.ADTIF;
}

void ADC1_ConversionDoneCallbackRegister(void (*callback)(void))
{
    ADC1_ConversionDoneCallback = callback;
}

void ADC1_ThresholdCallbackRegister(void (*callback)(void))
{
    ADC1_ThresholdCallback = callback;
}

void ADC1_ConversionDoneInterruptEnable(void)
{
    PIE6bits.ADIE = ADC_BIT_ENABLE;
}

void ADC1_ConversionDoneInterruptDisable(void)
{
    PIE6bits.ADIE = ADC_BIT_DISABLE;
}

void ADC1_ThresholdInterruptEnable(void)
{
    PIE6bits.ADTIE = ADC_BIT_ENABLE;    
}

void ADC1_ThresholdInterruptDisable(void)
{
    PIE6bits.ADTIE = ADC_BIT_DISABLE;    
}

void ADC1_ISR(void)
{
    PIR6bits.ADIF = ADC_BIT_DISABLE;

    if (NULL != ADC1_ConversionDoneCallback)
    {
        ADC1_ConversionDoneCallback();
    }
    else
    {
        // Do nothing
    }
}
void ADC1_ThresholdISR(void)
{
    PIR6bits.ADTIF = ADC_BIT_DISABLE;

    if (NULL != ADC1_ThresholdCallback)
    {
        ADC1_ThresholdCallback();
    }
    else
    {
        // Do nothing
    }
}
