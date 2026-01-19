/*
 * port.h
 *
 *  Created on: 2022年6月6日
 *      Author: dingchao
 *      描述:adc模式配置文件
 */

#ifndef PORTAB_H
#define PORTAB_H

#include "hal.h"
/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

#define PORTAB_LINE_LED1            LINE_LED_GREEN
//#define PORTAB_LINE_LED2            LINE_LED2
#define PORTAB_LED_OFF              PAL_LOW
#define PORTAB_LED_ON               PAL_HIGH
#define PORTAB_LINE_BUTTON          LINE_BUTTON
#define PORTAB_BUTTON_PRESSED       PAL_LOW

#define PORTAB_SD1                  LPSD1

//#define PORTAB_GPT1                 GPTD7
#define PORTAB_ADC1                 ADCD1

#define ADC_GRP1_NUM_CHANNELS       1
#define ADC_GRP2_NUM_CHANNELS       4



/**
 * @defgroup ADC_Channel_Number ADC Channel Number
 * @{
 */
#define ADC_CH_NUM_0                (0U)
#define ADC_CH_NUM_1                (1U)
#define ADC_CH_NUM_2                (2U)
#define ADC_CH_NUM_3                (3U)
#define ADC_CH_NUM_4                (4U)
#define ADC_CH_NUM_5                (5U)
#define ADC_CH_NUM_6                (6U)
#define ADC_CH_NUM_7                (7U)
#define ADC_CH_NUM_8                (8U)
#define ADC_CH_NUM_9                (9U)
#define ADC_CH_NUM_10               (10U)
#define ADC_CH_NUM_11               (11U)
#define ADC_CH_NUM_12               (12U)
#define ADC_CH_NUM_13               (13U)
#define ADC_CH_NUM_14               (14U)
#define ADC_CH_NUM_15               (15U)
#define ADC_CH_NUM_16               (16U)
#define ADC_CH_NUM_17               (17U)
#define ADC_CH_NUM_18               (18U)
#define ADC_CH_NUM_19               (19U)
/**
 * @}
 */

/**
 * @defgroup ADC_Channel ADC Channel
 * @{
 */
#define ADC_CH0                     (0x1UL << ADC_CH_NUM_0)
#define ADC_CH1                     (0x1UL << ADC_CH_NUM_1)
#define ADC_CH2                     (0x1UL << ADC_CH_NUM_2)
#define ADC_CH3                     (0x1UL << ADC_CH_NUM_3)
#define ADC_CH4                     (0x1UL << ADC_CH_NUM_4)
#define ADC_CH5                     (0x1UL << ADC_CH_NUM_5)
#define ADC_CH6                     (0x1UL << ADC_CH_NUM_6)
#define ADC_CH7                     (0x1UL << ADC_CH_NUM_7)
#define ADC_CH8                     (0x1UL << ADC_CH_NUM_8)
#define ADC_CH9                     (0x1UL << ADC_CH_NUM_9)
#define ADC_CH10                    (0x1UL << ADC_CH_NUM_10)
#define ADC_CH11                    (0x1UL << ADC_CH_NUM_11)
#define ADC_CH12                    (0x1UL << ADC_CH_NUM_12)
#define ADC_CH13                    (0x1UL << ADC_CH_NUM_13)
#define ADC_CH14                    (0x1UL << ADC_CH_NUM_14)
#define ADC_CH15                    (0x1UL << ADC_CH_NUM_15)
#define ADC_CH16                    (0x1UL << ADC_CH_NUM_16)
#define ADC_CH17                    (0x1UL << ADC_CH_NUM_17)
#define ADC_CH18                    (0x1UL << ADC_CH_NUM_18)
#define ADC_CH19                    (0x1UL << ADC_CH_NUM_19)
#define ADC_EXT_CH                  (ADC_CH15)


/*===========================================================================*/
/* Module pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Module data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

extern const GPTConfig portab_gptcfg1;
extern const ADCConfig portab_adccfg1;
extern const ADCConversionGroup portab_adcgrpcfg1;
extern const ADCConversionGroup portab_adcgrpcfg2;
extern const ADCConversionGroup portab_adcgrpcfg3;

#ifdef __cplusplus
extern "C" {
#endif
  void portab_setup(void);
#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

#endif /* PORTAB_H */

/** @} */
