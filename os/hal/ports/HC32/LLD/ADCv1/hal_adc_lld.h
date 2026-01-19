/*
    ChibiOS - Copyright (C) 2022 Radiolink
    Driver by Radiolink dingchao, April 2022
*/

/**
 * @file    ADCv1/hal_adc_lld.h
 * @brief   ADC driver header
 *
 * @addtogroup HC32_ADC
 * @{
 */

#ifndef HAL_ADC_LLD_H
#define HAL_ADC_LLD_H

#if HAL_USE_ADC || defined(__DOXYGEN__)

/**
 * @name    Possible ADC errors mask bits.
 * @{
 */
#define ADC_ERR_DMAFAILURE      1U  /**< DMA operations failure.            */
#define ADC_ERR_OVERFLOW        2U  /**< ADC overflow condition.            */
#define ADC_ERR_AWD             4U  /**< Watchdog triggered.                */
/** @} */

/**
 * @defgroup ADC_Unit_Number ADC Unit Number //硬件触发寄存器地址计算
 * @{
 */
#define ADC1_BASE                           (0x40040000UL)
#define __ADC_BASE                          (ADC1_BASE)
#define __ADC_UNIT_SIZE                     (0x400UL)
#define ADC_IDX(__ADCx__)                   ((uint8_t)(((uint32_t)&(__ADCx__)->STR - __ADC_BASE) / __ADC_UNIT_SIZE))

/**
 * @name    Triggers selection
 * @{
 */
#define APP_ADC_SA_TRIG_SRC_EVENT          (EVT_TMR2_1_CMPA)//设置硬件触发源
/** @} */

/**
 * @brief   ADC1 driver enable switch.
 * @details If set to @p TRUE the support for ADC1 is included.
 * @note    The default is @p TRUE.
 */
#if !defined(HC32_ADC_USE_ADC1) || defined(__DOXYGEN__)
#define HC32_ADC_USE_ADC1                  FALSE
#endif

/**
 * @brief   ADC2 driver enable switch.
 * @details If set to @p TRUE the support for ADC2 is included.
 * @note    The default is @p TRUE.
 */
#if !defined(HC32_ADC_USE_ADC2) || defined(__DOXYGEN__)
#define HC32_ADC_USE_ADC2                  FALSE
#endif

/**
 * @brief   ADC3 driver enable switch.
 * @details If set to @p TRUE the support for ADC3 is included.
 * @note    The default is @p TRUE.
 */
#if !defined(HC32_ADC_USE_ADC3) || defined(__DOXYGEN__)
#define HC32_ADC_USE_ADC3                  FALSE
#endif

//打开dma宏定义
#if !defined(HC32_DMA_REQUIRED)
#define HC32_DMA_REQUIRED
#endif

/**
 * @brief   ADC sample data type.
 */
typedef uint16_t adcsample_t;

/**
 * @brief   Channels number in a conversion group.
 */
typedef uint16_t adc_channels_num_t;

/**
 * @brief   Type of an ADC error mask.
 */
typedef uint32_t adcerror_t;

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Low level fields of the ADC driver structure.
 */
#define adc_lld_driver_fields                                               \
  /* Pointer to the ADCx registers block.*/                                 \
  M4_ADC_TypeDef               *adc;                                        \
  /* Pointer to associated DMA channel.*/                                   \
  const hc32_dma_channel_t  *dmastp;                                        \
  /* DMA mode bit mask.*/                                                   \
  dma_channel_mode_t         dmamode

/**
 * @brief   Low level fields of the ADC configuration structure.
 */
#define adc_lld_config_fields                                               \
  /* Dummy configuration, it is not needed.*/                               \
  uint32_t                  dummy

/**
 * @brief   Low level fields of the ADC configuration structure.
 */
#define adc_lld_configuration_group_fields                                  \
  /* ADC CR1 register initialization data.                                  \
     NOTE: All the required bits must be defined into this field except     \
           @p ADC_CR1_SCAN that is enforced inside the driver.*/            \
  uint16_t                  cr0;                                            \
  /* ADC CR2 register initialization data.                                  \
     NOTE: All the required bits must be defined into this field except     \
           @p ADC_CR2_DMA, @p ADC_CR2_CONT and @p ADC_CR2_ADON that are     \
           enforced inside the driver.*/                                    \
  uint16_t                  cr1;                                            \
  /*AD  转换开始触发寄存器 ADC_TRGSR*/                                        \
  uint16_t                  trgsr;                                          \
 /*序列A通道选择寄存器*/                                                     \
  uint32_t                  chselra;                                        \
  /*序列B通道选择寄存器*/                                                    \
  uint32_t                  chselrb;                                        \
  /*平均通道 平均通道 选择 寄存器*/                                          \
  uint32_t                  avchselr;                                       \
  /*扩展通道寄存器*/                                                         \
  uint8_t                   exchselr


#if HC32_ADC_USE_ADC1 && !defined(__DOXYGEN__)
extern ADCDriver ADCD1;
#endif

#if HC32_ADC_USE_ADC2 && !defined(__DOXYGEN__)
extern ADCDriver ADCD2;
#endif

#if HC32_ADC_USE_ADC3 && !defined(__DOXYGEN__)
extern ADCDriver ADCD3;
#endif


#ifdef __cplusplus
extern "C" {
#endif
  void adc_lld_init(void);
  void adc_lld_start(ADCDriver *adcp);
  void adc_lld_stop(ADCDriver *adcp);
  void adc_lld_start_conversion(ADCDriver *adcp);
  void adc_lld_stop_conversion(ADCDriver *adcp);
  void adcHC32EnableVBATE(ADCDriver *adcp);
  void adcHC32DisableVBATE(ADCDriver *adcp);
  void adcHC32EnableTSVREFE(ADCDriver *adcp);
  void adcHC32DisableTSVREFE(ADCDriver *adcp);
  void adc_deInit(M4_ADC_TypeDef *adc);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_ADC */

#endif /* HAL_ADC_LLD_H */




