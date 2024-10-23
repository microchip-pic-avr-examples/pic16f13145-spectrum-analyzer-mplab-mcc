/**
 * ADC1 Generated Driver API Header File
 * 
 * @file adc1.h
 * 
 * @defgroup  adc1 ADC1
 * 
 * @brief This file provides API prototypes for the ADC1 driver.
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

#ifndef ADC1_H
#define ADC1_H

// Section: Included Files

#include <stdint.h>
#include <stdbool.h>
#include "./adc_types.h"

// Section: Macros


// Section: Module APIs

/**
 * @ingroup adc1
 * @brief Initializes the registers for the Analog-to-Digital (A/D) conversion depending on the configurable options in the MPLABÂ® Code Configurator (MCC) Melody UI for the Analog-to-Digital Converter (ADC) operation.
 * @param None.
 * @return None.
*/
void ADC1_Initialize(void);

/**
 * @ingroup adc1
 * @brief Deinitializes the registers to power on reset values for the ADC.
 * @param None.
 * @return None.
*/
void ADC1_Deinitialize(void);

/**
 * @ingroup adc1
 * @brief Sets the ADC ON bit to 1.
 * @param None.
 * @return None.
*/
void ADC1_Enable(void);

/**
 * @ingroup adc1
 * @brief Sets the ADC ON bit to 0.
 * @param None.
 * @return None.
*/
void ADC1_Disable(void);

/**
 * @ingroup adc1
 * @brief Sets the channel to use for the A/D conversion.
 * @param channel - Desired analog channel. Refer to the adc_channel_t enum for the list of available analog channels.
 * @return None.
*/
void ADC1_ChannelSelect(adc_channel_t channel);

/**
 * @ingroup adc1
 * @brief Starts the A/D conversion on a selected channel. 
 * @pre Select the channel(s) before calling this API using ADC1_ChannelSelect
 *  and call ADC1_Initialize(void) before using this API to initialize ADC module.
 * @param None.
 * @return None.
*/
void ADC1_ConversionStart(void);

/**
 * @ingroup adc1
 * @brief Checks if the ongoing A/D conversion is complete.
 * @pre ADC1_ConversionStart(void) is called before using this API.
 * @param None.
 * @retval True - A/D conversion is complete
 * @retval False - A/D conversion is ongoing
*/
bool ADC1_IsConversionDone(void);

/**
 * @ingroup adc1
 * @brief Stops the ongoing A/D conversion.
 * @param None.
 * @return None.
*/
void ADC1_ConversionStop(void);

/**
 * @ingroup adc1
 * @brief Retrieves the result of the latest A/D conversion.
 * @pre Call ADC1_ConversionStart(void) before using this API.
 * @param None.
 * @return The result of A/D conversion. Refer to the adc_result_t.
*/
adc_result_t ADC1_ConversionResultGet(void);

/**
 * @ingroup adc1
 * @brief Sets the A/D conversion computation mode. 
 * @param computationMode - Desired computation mode. Refer to the adc_computation_mode_t enum for the list of available computation modes.
 * @return None.
*/
void ADC1_ComputationModeSet(adc_computation_mode_t computationMode);

/**
 * @ingroup adc1
 * @brief Sets the A/D conversion threshold mode.
 * @param thresholdMode - Desired threshold mode. Refer to the adc_threshold_mode_t enum for the list of available threshold modes.
 * @return None.
*/
void ADC1_ThresholdModeSet(adc_threshold_mode_t  thresholdMode);

/**
 * @ingroup adc1
 * @brief Loads the repeat counter with the specified value.
 * @param repeatCount - Repeat count value of the adc_repeat_count_t type to be loaded to repeat counter
 * @return None.
*/

void ADC1_SampleRepeatCountSet(adc_repeat_count_t repeatCount);
/**
 * @ingroup adc1
 * @brief Sets the value of ADC Upper Threshold (ADUTH) register.
 * @param upperThreshold - Upper threshold value of the adc_threshold_t type for the ADUTH register
 * @return None.
*/
void ADC1_UpperThresholdSet(adc_threshold_t upperThreshold); 

/**
 * @ingroup adc1
 * @brief Sets the value of ADC Lower Threshold (ADLTH) register.
 * @param lowerThreshold - Lower threshold value of the adc_threshold_t type for the ADLTH register
 * @return None.
*/
void ADC1_LowerThresholdSet(adc_threshold_t lowerThreshold);

/**
 * @ingroup adc1
 * @brief Retrieves an accumulated value of the A/D conversion.
 * @param None.
 * @return adc_accumulate_t value of ADC accumulator register
*/
adc_accumulate_t ADC1_AccumulatedResultGet(void);

/**
 * @ingroup adc1
 * @brief Starts the conversion and retrieves the result of the single A/D conversion on the selected channel. 
 * @pre Enable ADC using the ADC1_Initialize API.
 * @param channel - Desired analog channel. Refer to the adc_channel_t enum for the list of available analog channels.
 * @return The adc_result_t type result value of a single A/D conversion
*/
adc_result_t ADC1_ChannelSelectAndConvert(adc_channel_t channel); 

/**
 * @ingroup adc1
 * @brief Enables the Stop-on-Interrupt bit.
 * @pre Call ADC1_ContinuousConversionEnable API before using this API.
 * @param None.
 * @return None.
*/
void ADC1_StopOnInterruptEnable(void);

/**
 * @ingroup adc1
 * @brief Disables the Stop-on-Interrupt bit.
 * @param None.
 * @return None.
*/
void ADC1_StopOnInterruptDisable(void);

/**
 * @ingroup adc1
 * @brief Discharges the input sample capacitor by setting the channel to AVss.
 * @param None.
 * @return None.
*/
void ADC1_SampleCapacitorDischarge(void);

/**
 * @ingroup adc1
 * @brief Sets the specified value for the ADC Acquisition Time Control (ADACQ) register.
 * @param acquisitionValue - Value to be loaded in the ADACQ register
 * @return None.
*/
void ADC1_AcquisitionTimeSet(uint16_t acquisitionValue); 

/**
 * @ingroup adc1
 * @brief Sets the specified value for the ADC Precharge Time Control (ADPRE) register.
 * @param prechargeTime - Value to be loaded in the ADPRE register
 * @return None.
*/
void ADC1_PrechargeTimeSet(uint16_t prechargeTime);

/**
 * @ingroup adc1
 * @brief Retrieves the current value of the ADC Repeat Counter (ADCNT) register.
 * @param None.
 * @return Current value of the ADCNT register
*/
adc_repeat_count_t ADC1_CurrentConversionCountGet(void);

/**
 * @ingroup adc1
 * @brief Clears the accumulator.
 * @param None.
 * @return None.
*/
void ADC1_AccumulatorClear(void);

/**
 * @ingroup adc1
 * @brief Status of Accumulator Clear operation
 * @param None.
 * @retval True - ADC accumulator clear operation complete
 * @retval False - ADC accumulator clear operation not complete
*/
bool ADC1_IsAccumulatorClearComplete(void);

/**
 * @ingroup adc1
 * @brief Determines whether the ADC accumulator has overflowed.
 * @param None.
 * @retval True - ADC accumulator has overflowed
 * @retval False - ADC accumulator has not overflowed
*/
bool ADC1_HasAccumulatorOverflowed(void);

/**
 * @ingroup adc1
 * @brief Returns busy status of ADC1 module.
 * @param None.
 * @retval True - ADC1 is in use
 * @retval False - ADC1 is not in use
*/
bool ADC1_IsBusy(void);

/**
 * @ingroup adc1
 * @brief Sets the busy status of ADC1 module.
 * @param bool True to set the ADC1 status as busy, false otherwise.
 * @return None.
*/
void ADC1_BusyStatusSet(bool status);

/**
 * @ingroup adc1
 * @brief Retrieves the value of the ADC Filter (ADFLTR) register.
 * @param None.
 * @return adc_result_t value obtained from the high byte ADFLTR (ADFLTRH) and low byte ADFLTR (ADFLTRL) registers
*/
adc_result_t ADC1_FilterValueGet(void);

/**
 * @ingroup adc1
 * @brief Retrieves the value of the ADC Previous(ADPREV) register.
 * @param None.
 * @return adc_result_t value obtained from the high byte ADPREV (ADPREVH) and low byte ADPREV (ADPREVL) registers
*/
adc_result_t ADC1_PreviousResultGet(void);

/**
 * @ingroup adc1
 * @brief Sets the value of the ADC Threshold Setpoint (ADSTPT) register.
 * @param setPoint - adc_threshold_t value for the ADSTPT register
 * @return None.
*/
void ADC1_SetPointDefine(adc_threshold_t setPoint);  

/**
 * @ingroup adc1
 * @brief Retrieves the value of ADC Setpoint Error (ADERR) register.
 * @param None.
 * @return adc_result_t value obtained from the high byte ADERR (ADERRH) and low byte ADERR (ADERRL) registers
*/
adc_result_t ADC1_ErrorCalculationGet(void); 

/**
 * @ingroup adc1
 * @brief Enables the Double-Sample Enable (DSEN) bit.
 * @param None.
 * @return None.
*/
void ADC1_DoubleSamplingEnable(void); 

/**
 * @ingroup adc1
 * @brief Disables the Double-Sample Enable (DSEN) bit.
 * @param None.
 * @return None.
*/
void ADC1_DoubleSamplingDisable(void); 

/**
 * @ingroup adc1
 * @brief Enables continuous conversion.
 * @param None.
 * @return None.
*/
void ADC1_ContinuousConversionEnable(void); 

/**
 * @ingroup adc1
 * @brief Disables continuous conversion.
 * @param None.
 * @return None.
*/
void ADC1_ContinuousConversionDisable(void);  

/**
 * @ingroup adc1
 * @brief Determines if the ADC error is greater than the upper threshold.
 * @param None.
 * @retval True - ADC error is greater than the upper threshold
 * @retval False - ADC error is not greater than the upper threshold
*/
bool ADC1_IsErrorGreaterThanUpperThreshold(void); 

/**
 * @ingroup adc1
 * @brief Determines if the ADC error is less than the lower threshold.
 * @param None.
 * @retval True - ADC error is less than the lower threshold
 * @retval False - ADC error is not less the lower threshold
*/
bool ADC1_IsErrorLesserThanLowerThreshold(void);  

/**
 * @ingroup adc1
 * @brief Retrieves the multi-stage status.
 * @param None.
 * @return adc_conversion_stage_t enum value
*/
adc_conversion_stage_t ADC1_ConversionStageStatusGet(void); 

/**
 * @ingroup adc1
 * @brief Sets the auto-trigger source.
 * @param triggerSource - Desired auto-trigger source. Refer to the adc_trigger_source_t enum for the list of available trigger sources.
 * @return None.
*/
void ADC1_AutoTriggerSourceSet(adc_trigger_source_t triggerSource);

/**
 * @ingroup adc1
 * @brief Sets the ADC Error Calculation Mode Select (CALC).
 * @param errorCalculationMode - Desired errorCalculationMode value. Refer to the adc_calculation_mode_t enum for error calculation mode options.
 * @return None.
*/
void ADC1_ErrorCalculationModeSet(adc_calculation_mode_t errorCalculationMode);

/**
 * @ingroup adc1
 * @brief Sets the ADC Accumulated Calculation Right Shift Select (CRS) bit values.
 * @param rightShiftValue - 8-bit right shift value
 * @return None.
*/
void ADC1_CalculationRightShiftSet(uint8_t rightShiftValue);

/**
 * @ingroup adc1
 * @brief Returns resolution of ADC module.
 * @param None.
 * @return uint8_t Resolution value
*/
uint8_t ADC1_ResolutionGet(void);

/**
 * @ingroup adc1
 * @brief Clears the ADC Conversion Done Interrupt Flag bit to 0.
 * @param None.
 * @return None.
*/
void ADC1_ConversionDoneInterruptFlagClear(void);

/**
 * @ingroup adc1
 * @brief Clears the ADC Threshold Interrupt Flag bit to 0.
 * @param None.
 * @return None.
*/
void ADC1_ThresholdInterruptFlagClear(void);

/**
 * @ingroup adc1
 * @brief Checks the ADC Interrupt (ADI) flag status.
 * @param None.
 * @retval True -  ADI flag status is set
 * @retval False - ADI flag status is not set
*/
bool ADC1_IsConversionDoneInterruptFlagSet(void);

/**
 * @ingroup adc1
 * @brief Checks the  ADC Threshold Interrupt (ADTI) flag status.
 * @param None.
 * @retval True - ADTI flag status is set
 * @retval False - ADTI flag status is not set
*/
bool ADC1_IsThresholdInterruptFlagSet(void);

/**
 * @ingroup adc1
 * @brief Sets the callback function for ADC Interrupt.
 * @param Pointer to the function to be executed
 * @return None.
 */
void ADC1_ConversionDoneCallbackRegister(void (*callback)(void));

/**
 * @ingroup adc1
 * @brief Sets the callback function for ADC Threshold Interrupt.
 * @param Pointer to the function to be executed
 * @return None.
 */
void ADC1_ThresholdCallbackRegister(void (*callback)(void));

/**
 * @ingroup adc1
 * @brief Sets the ADC Interrupt Enable bit to 1.
 * @param None.
 * @return None.
*/
void ADC1_ConversionDoneInterruptEnable(void);

/**
 * @ingroup adc1
 * @brief Sets the ADC Interrupt Enable bit to 0.
 * @param None.
 * @return None.
*/
void ADC1_ConversionDoneInterruptDisable(void);

/**
 * @ingroup adc1
 * @brief Sets the ADC Threshold Interrupt Enable bit to 1.
 * @param None.
 * @return None.
*/
void ADC1_ThresholdInterruptEnable(void);

/**
 * @ingroup adc1
 * @brief Sets the ADC Threshold Interrupt Enable bit to 0.
 * @param None.
 * @return None.
*/
void ADC1_ThresholdInterruptDisable(void);

/**
 * @ingroup adc1
 * @brief Implements the ADC Interrupt (ADI) service routine for the interrupt-driven implementations.
 * @param None.
 * @return None.
*/
void ADC1_ISR(void);

/**
 * @ingroup adc1
 * @brief Implements the ADC Threshold Interrupt (ADTI) service routine for the interrupt-driven implementations.
 * @param None.
 * @return None.
*/
void ADC1_ThresholdISR(void);

#endif//ADC1_H
