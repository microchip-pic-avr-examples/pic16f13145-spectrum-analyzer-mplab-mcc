/**
 * ADC Generated Driver File
 * 
 * @file adc.c
 * 
 * @ingroup  adc
 * 
 * @brief This file contains the API implementations for the ADC driver.
 *
 * @version ADC Driver Version 3.0.0
 * 
 * @version ADC Package Version 2.0.0
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

#include <xc.h>
#include "../adc.h"
#include "../adc_types.h"


static bool adc_busy_status;
static void (*ADC_ConversionDoneCallback)(void);
static void (*ADC_ThresholdCallback)(void);

void ADC_Initialize(void)
{
    ADCON0bits.ADON = ADC_BIT_CLEAR;    
    ADCON0 = (1 << _ADCON0_ADON_POSITION)	/* ADON enabled(1) */
			|(0 << _ADCON0_ADCONT_POSITION)	/* ADCONT disabled(0) */
			|(0 << _ADCON0_ADCS_POSITION)	/* ADCS FOSC(0) */
			|(1 << _ADCON0_ADFM_POSITION)	/* ADFM right(1) */
			|(0 << _ADCON0_GO_nDONE_POSITION);	/* GO_nDONE stop(0) */
    ADCON1 = (0 << _ADCON1_ADDSEN_POSITION)	/* ADDSEN disabled(0) */
			|(0 << _ADCON1_PCSC_POSITION)	/* PCSC internal sampling capacitor and external i/o pin(0) */
			|(0 << _ADCON1_ADGPOL_POSITION)	/* ADGPOL digital_low(0) */
			|(0 << _ADCON1_ADIPEN_POSITION)	/* ADIPEN disabled(0) */
			|(0 << _ADCON1_ADPPOL_POSITION);	/* ADPPOL VSS(0) */
    ADCON2 = (0 << _ADCON2_ADMD_POSITION)	/* ADMD Basic_mode(0) */
			|(1 << _ADCON2_ADACLR_POSITION)	/* ADACLR enabled(1) */
			|(1 << _ADCON2_ADCRS_POSITION)	/* ADCRS 0x1(1) */
			|(0 << _ADCON2_ADPSIS_POSITION);	/* ADPSIS ADRES(0) */
    ADCON3 = (0 << _ADCON3_ADTMD_POSITION)	/* ADTMD disabled(0) */
			|(0 << _ADCON3_ADSOI_POSITION)	/* ADSOI ADGO not cleared(0) */
			|(1 << _ADCON3_ADCALC_POSITION);	/* ADCALC Actual result vs setpoint(1) */
    ADCLK = (15 << _ADCLK_ADCS_POSITION);	/* ADCS FOSC/32(15) */
    ADCG1A = (0 << _ADCG1A_CGA0_POSITION)	/* CGA0 disabled(0) */
			|(0 << _ADCG1A_CGA1_POSITION)	/* CGA1 disabled(0) */
			|(0 << _ADCG1A_CGA2_POSITION)	/* CGA2 disabled(0) */
			|(0 << _ADCG1A_CGA4_POSITION)	/* CGA4 disabled(0) */
			|(0 << _ADCG1A_CGA5_POSITION);	/* CGA5 disabled(0) */
    ADCG1B = (0 << _ADCG1B_CGB4_POSITION)	/* CGB4 disabled(0) */
			|(0 << _ADCG1B_CGB5_POSITION)	/* CGB5 disabled(0) */
			|(0 << _ADCG1B_CGB6_POSITION)	/* CGB6 disabled(0) */
			|(0 << _ADCG1B_CGB7_POSITION);	/* CGB7 disabled(0) */
    ADCG1C = (0 << _ADCG1C_CGC0_POSITION)	/* CGC0 disabled(0) */
			|(0 << _ADCG1C_CGC1_POSITION)	/* CGC1 disabled(0) */
			|(0 << _ADCG1C_CGC2_POSITION)	/* CGC2 disabled(0) */
			|(0 << _ADCG1C_CGC3_POSITION)	/* CGC3 disabled(0) */
			|(0 << _ADCG1C_CGC4_POSITION)	/* CGC4 disabled(0) */
			|(0 << _ADCG1C_CGC5_POSITION)	/* CGC5 disabled(0) */
			|(0 << _ADCG1C_CGC6_POSITION);	/* CGC6 disabled(0) */
    ADLTHL = (0 << _ADLTHL_LTH_POSITION);	/* LTH 0x0(0) */
    ADLTHH = (0 << _ADLTHH_LTH_POSITION);	/* LTH 0x0(0) */
    ADUTHL = (0 << _ADUTHL_UTH_POSITION);	/* UTH 0x0(0) */
    ADUTHH = (0 << _ADUTHH_UTH_POSITION);	/* UTH 0x0(0) */
    ADSTPTL = (0 << _ADSTPTL_STPT_POSITION);	/* STPT 0x0(0) */
    ADSTPTH = (0 << _ADSTPTH_STPT_POSITION);	/* STPT 0x0(0) */
    ADACCU = (0 << _ADACCU_ACC_POSITION);	/* ACC 0x0(0) */
    ADACCH = (0 << _ADACCH_ACC_POSITION);	/* ACC 0x0(0) */
    ADACCL = (0 << _ADACCL_ACC_POSITION);	/* ACC 0x0(0) */
    ADRESH = (0 << _ADRESH_ADRES_POSITION);	/* ADRES 0x0(0) */
    ADRESL = (0 << _ADRESL_ADRES_POSITION);	/* ADRES 0x0(0) */
    ADCNT = (0 << _ADCNT_ADCNT_POSITION);	/* ADCNT 0x0(0) */ 
    ADRPT = (0 << _ADRPT_ADRPT_POSITION);	/* ADRPT 0x0(0) */       
    ADCAP = (0 << _ADCAP_CAP_POSITION);	/* CAP Additional uC disabled(0) */
    ADPCH = (1 << _ADPCH_PCH_POSITION);	/* PCH ANA1(1) */ 
    ADACQL = (0 << _ADACQL_ACQ_POSITION);	/* ACQ 0x0(0) */  
    ADACQH = (0 << _ADACQH_ACQ_POSITION);	/* ACQ 0x0(0) */ 
    ADPREL = (0 << _ADPREL_PRE_POSITION);	/* PRE 0x0(0) */ 
    ADPREH = (0 << _ADPREH_PRE_POSITION);	/* PRE 0x0(0) */
    ADREF = (0 << _ADREF_ADPREF_POSITION);	/* ADPREF VDD(0) */    
    ADACT = (3 << _ADACT_ADACT_POSITION);	/* ADACT TMR1(3) */ 
    ADSTAT =(0 << _ADSTAT_ADMATH_POSITION);	/* ADMATH registers not updated(0) */   
    
    adc_busy_status = false;
    ADC_ConversionDoneCallback = NULL;
    ADC_ThresholdCallback = NULL;
    
    PIR6bits.ADIF = ADC_BIT_CLEAR;
    PIE6bits.ADIE = ADC_BIT_SET;
    PIR6bits.ADTIF = ADC_BIT_CLEAR;
    PIE6bits.ADTIE = ADC_BIT_CLEAR;
    ADCON0 = (1 << _ADCON0_ADON_POSITION)	/* ADON enabled(1) */
			|(0 << _ADCON0_ADCONT_POSITION)	/* ADCONT disabled(0) */
			|(0 << _ADCON0_ADCS_POSITION)	/* ADCS FOSC(0) */
			|(1 << _ADCON0_ADFM_POSITION)	/* ADFM right(1) */
			|(0 << _ADCON0_GO_nDONE_POSITION);	/* GO_nDONE stop(0) */
}

void ADC_Deinitialize(void)
{
    ADCON0 = 0x0;
    PIR6bits.ADIF = ADC_BIT_CLEAR;
    PIE6bits.ADIE = ADC_BIT_CLEAR;
    PIR6bits.ADTIF = ADC_BIT_CLEAR;
    PIE6bits.ADTIE = ADC_BIT_CLEAR;
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

void ADC_Enable(void)
{
    ADCON0bits.ADON = ADC_BIT_SET;
}

void ADC_Disable(void)
{
    ADCON0bits.ADON = ADC_BIT_CLEAR;
}

void ADC_ChannelSelect(adc_channel_t channel)
{
   ADPCH = channel;  
}

void ADC_ConversionStart(void)
{
    ADCON0bits.GO_nDONE = ADC_BIT_SET;
}

bool ADC_IsConversionDone(void)
{
    return ((bool)(!ADCON0bits.GO_nDONE));
}

void ADC_ConversionStop(void)
{
    ADCON0bits.GO_nDONE = ADC_BIT_CLEAR;
}

adc_result_t ADC_ConversionResultGet(void)
{
    return ((adc_result_t)((ADRESH << 8U) | ADRESL));
}

void ADC_ComputationModeSet(adc_computation_mode_t computationMode)
{
    ADCON2bits.ADMD |= computationMode;
}

void ADC_ThresholdModeSet(adc_threshold_mode_t thresholdMode)
{
    ADCON3bits.ADTMD |= thresholdMode;
}

void ADC_SampleRepeatCountSet(adc_repeat_count_t repeatCount)
{
    ADRPT = repeatCount;
}

void ADC_UpperThresholdSet(adc_threshold_t upperThreshold)
{
    ADUTHH = (uint8_t) ((uint16_t)upperThreshold >> 8U);
    ADUTHL = (uint8_t) upperThreshold;
}

void ADC_LowerThresholdSet(adc_threshold_t lowerThreshold)
{
    ADLTHH = (uint8_t) ((uint16_t)lowerThreshold >> 8U);
    ADLTHL = (uint8_t) lowerThreshold;
}

adc_accumulate_t ADC_AccumulatedResultGet(void)
{
    return (adc_accumulate_t)(((uint32_t)ADACCU << 16U)+((uint32_t)ADACCH << 8U) + ADACCL);
}

adc_result_t ADC_ChannelSelectAndConvert(adc_channel_t channel)
{
    ADPCH = channel;  
    ADCON0bits.ADCONT = ADC_BIT_CLEAR;

    ADCON0bits.GO_nDONE = ADC_BIT_SET;

    while (true == ADCON0bits.GO_nDONE)
    {
    }
    
    return ((adc_result_t)((ADRESH << 8U) | ADRESL));
}

void ADC_StopOnInterruptEnable(void)
{
    ADCON3bits.ADSOI = ADC_BIT_SET;
}

void ADC_StopOnInterruptDisable(void)
{
    ADCON3bits.ADSOI = ADC_BIT_CLEAR;
}

void ADC_SampleCapacitorDischarge(void)
{
     ADPCH = ADC_CHANNEL_VSS;
}

void ADC_AcquisitionTimeSet(uint16_t acquisitionValue)
{
    ADACQH = (uint8_t)(acquisitionValue >> 8U);
    ADACQL = (uint8_t)(acquisitionValue);
}

void ADC_PrechargeTimeSet(uint16_t prechargeTime)
{
    ADPREH = (uint8_t)(prechargeTime >> 8U);
    ADPREL = (uint8_t)(prechargeTime);
}

adc_repeat_count_t ADC_CurrentConversionCountGet(void)
{
    return ((adc_repeat_count_t)ADCNT);
}

void ADC_AccumulatorClear(void)
{
    ADCON2bits.ADACLR = ADC_BIT_SET;
}

bool ADC_IsAccumulatorClearComplete(void)
{
    return ((bool)(!ADCON2bits.ADACLR));
}

bool ADC_HasAccumulatorOverflowed(void)
{
    return ADSTATbits.ADAOV;
}

adc_result_t ADC_FilterValueGet(void)
{
    return ((adc_result_t)((ADFLTRH << 8U) | ADFLTRL));
}

adc_result_t ADC_PreviousResultGet(void)
{
    return ((adc_result_t)((ADPREVH << 8U) | ADPREVL));
}

void ADC_SetPointDefine(adc_threshold_t setPoint)
{
    ADSTPTH = (uint8_t) ((uint16_t)setPoint >> 8U);
    ADSTPTL = (uint8_t) setPoint;
}

adc_result_t ADC_ErrorCalculationGet(void)
{
    return (adc_result_t)((ADERRH << 8U) | ADERRL);
}

void ADC_DoubleSamplingEnable(void)
{
    ADCON1bits.ADDSEN = ADC_BIT_SET;
}

void ADC_DoubleSamplingDisable(void)
{
    ADCON1bits.ADDSEN = ADC_BIT_CLEAR;
}

void ADC_ContinuousConversionEnable(void)
{
    ADCON0bits.ADCONT = ADC_BIT_SET;
}

void ADC_ContinuousConversionDisable(void)
{
    ADCON0bits.ADCONT = ADC_BIT_CLEAR;
}

bool ADC_IsErrorGreaterThanUpperThreshold(void)
{
    return ADSTATbits.ADUTHR;
}

bool ADC_IsErrorLesserThanLowerThreshold(void)
{
    return ADSTATbits.ADLTHR;
}

adc_conversion_stage_t ADC_ConversionStageStatusGet(void)
{
    return (adc_conversion_stage_t)ADSTATbits.ADSTAT;
}

void ADC_ErrorCalculationModeSet(adc_calculation_mode_t errorCalculationMode)
{
    ADCON3bits.ADCALC = errorCalculationMode;    
}  

void ADC_CalculationRightShiftSet(uint8_t rightShiftValue)
{
    ADCON2bits.ADCRS = rightShiftValue;
}

void ADC_ThresholdInterruptFlagClear(void)
{
    PIR6bits.ADTIF = ADC_BIT_CLEAR;
}

bool ADC_IsThresholdInterruptFlagSet(void)
{
    return PIR6bits.ADTIF;
}

void ADC_AutoTriggerSourceSet(adc_trigger_source_t triggerSource)
{
    ADACT = triggerSource;
}

uint8_t ADC_ResolutionGet(void)
{
    return ADC_RESOLUTION;
}

bool ADC_IsBusy(void)
{
    return adc_busy_status;
}

void ADC_BusyStatusSet(bool status)
{
    adc_busy_status = status;
}

void ADC_ConversionDoneInterruptFlagClear(void)
{
    PIR6bits.ADIF = ADC_BIT_CLEAR;
}

bool ADC_IsConversionDoneInterruptFlagSet(void)
{
    return PIR6bits.ADIF; 
}

void ADC_ConversionDoneCallbackRegister(void (*callback)(void))
{
    ADC_ConversionDoneCallback = callback;
}

void ADC_ThresholdCallbackRegister(void (*callback)(void))
{
    ADC_ThresholdCallback = callback;
}

void ADC_ConversionDoneInterruptEnable(void)
{
    PIE6bits.ADIE = ADC_BIT_SET;
}

void ADC_ConversionDoneInterruptDisable(void)
{
    PIE6bits.ADIE = ADC_BIT_CLEAR;
}

void ADC_ThresholdInterruptEnable(void)
{
    PIE6bits.ADTIE = ADC_BIT_SET;    
}

void ADC_ThresholdInterruptDisable(void)
{
    PIE6bits.ADTIE = ADC_BIT_CLEAR;    
}

void ADC_ISR(void)
{
    PIR6bits.ADIF = ADC_BIT_CLEAR;

    if (NULL != ADC_ConversionDoneCallback)
    {
        ADC_ConversionDoneCallback();
    }
    else
    {
        // Do nothing
    }
}
void ADC_ThresholdISR(void)
{
    PIR6bits.ADTIF = ADC_BIT_CLEAR;

    if (NULL != ADC_ThresholdCallback)
    {
        ADC_ThresholdCallback();
    }
    else
    {
        // Do nothing
    }
}
