/*
    ChibiOS - Copyright (C) 2022 Radiolink
    Driver by Radiolink Wu, March 2022
*/

/**
 * @file    HC32F4xx/hc32_isr.h
 * @brief   HC32F4xx ISR handler header
 *
 * @addtogroup HC32F4xx_ISR
 * @{
 */

#ifndef HC32_ISR_H
#define HC32_ISR_H

/*
 * TIM unit.
 */
#define HC32_TMR6_1_GCMA_NUMBER                     Int002_IRQn
#define HC32_TMR6_1_GCMA_HANDLER                    Vector48

#if HC32_ICU_USE_TIM6_2
#define HC32_TMR6_2_GCMA_NUMBER                     Int003_IRQn
#define HC32_TMR6_2_GCMB_NUMBER                     Int057_IRQn
#define HC32_TMR6_2_GOVF_NUMBER                     Int061_IRQn

#define HC32_TMR6_2_GCMA_HANDLER                    Vector4C
#define HC32_TMR6_2_GCMB_HANDLER                    Vector124
#define HC32_TMR6_2_GOVF_HANDLER                    Vector134
#endif

#if HC32_ICU_USE_TIM6_3
#define HC32_TMR6_3_GCMA_NUMBER                     Int062_IRQn
#define HC32_TMR6_3_GCMB_NUMBER                     Int063_IRQn
#define HC32_TMR6_3_GOVF_NUMBER                     Int064_IRQn

#define HC32_TMR6_3_GCMA_HANDLER                    Vector138
#define HC32_TMR6_3_GCMB_HANDLER                    Vector13C
#define HC32_TMR6_3_GOVF_HANDLER                    Vector140
#endif

#if HC32_ICU_USE_TIM6_4
#define HC32_TMR6_4_GCMA_NUMBER                     Int068_IRQn
#define HC32_TMR6_4_GCMB_NUMBER                     Int069_IRQn
#define HC32_TMR6_4_GOVF_NUMBER                     Int070_IRQn

#define HC32_TMR6_4_GCMA_HANDLER                    Vector150
#define HC32_TMR6_4_GCMB_HANDLER                    Vector154
#define HC32_TMR6_4_GOVF_HANDLER                    Vector158
#endif

#if HC32_ICU_USE_TIM6_5
#define HC32_TMR6_5_GCMA_NUMBER                     Int074_IRQn
#define HC32_TMR6_5_GCMB_NUMBER                     Int075_IRQn
#define HC32_TMR6_5_GOVF_NUMBER                     Int076_IRQn

#define HC32_TMR6_5_GCMA_HANDLER                    Vector168
#define HC32_TMR6_5_GCMB_HANDLER                    Vector16C
#define HC32_TMR6_5_GOVF_HANDLER                    Vector170
#endif

#if  HC32_ICU_USE_TIM6_6
#define HC32_TMR6_6_GCMA_NUMBER                     Int077_IRQn
#define HC32_TMR6_6_GCMB_NUMBER                     Int078_IRQn
#define HC32_TMR6_6_GOVF_NUMBER                     Int079_IRQn

#define HC32_TMR6_6_GCMA_HANDLER                    Vector174
#define HC32_TMR6_6_GCMB_HANDLER                    Vector178
#define HC32_TMR6_6_GOVF_HANDLER                    Vector17C
#endif

#if HC32_ICU_USE_TIM6_7
#define HC32_TMR6_7_GCMA_NUMBER                     Int083_IRQn
#define HC32_TMR6_7_GCMB_NUMBER                     Int084_IRQn
#define HC32_TMR6_7_GOVF_NUMBER                     Int085_IRQn

#define HC32_TMR6_7_GCMA_HANDLER                    Vector18C
#define HC32_TMR6_7_GCMB_HANDLER                    Vector190
#define HC32_TMR6_7_GOVF_HANDLER                    Vector194
#endif

#if HC32_ICU_USE_TIM6_8
#define HC32_TMR6_8_GCMA_NUMBER                     Int023_IRQn
#define HC32_TMR6_8_GCMB_NUMBER                     Int024_IRQn
#define HC32_TMR6_8_GOVF_NUMBER                     Int025_IRQn

#define HC32_TMR6_8_GCMA_HANDLER                    Vector9C
#define HC32_TMR6_8_GCMB_HANDLER                    VectorA0
#define HC32_TMR6_8_GOVF_HANDLER                    VectorA4
#endif

#if (HC32_PWM_USE_TIMA_1) || (HC32_ICU_USE_TIMA_1)
#define HC32_TMRA_1_CMP_NUMBER                      Int026_IRQn
#define HC32_TMRA_1_OVF_NUMBER                      Int027_IRQn

#define HC32_TMRA_1_CMP_HANDLER                     VectorA8
#define HC32_TMRA_1_OVF_HANDLER                     VectorAC
#endif

#if (HC32_PWM_USE_TIMA_4) || (HC32_ICU_USE_TIMA_4)
#define HC32_TMRA_4_CMP_NUMBER                      Int081_IRQn
#define HC32_TMRA_4_OVF_NUMBER                      Int082_IRQn

#define HC32_TMRA_4_CMP_HANDLER                     Vector184
#define HC32_TMRA_4_OVF_HANDLER                     Vector188
#endif

#if (HC32_PWM_USE_TIMA_9) || (HC32_ICU_USE_TIMA_9)
#define HC32_TMRA_9_CMP_NUMBER                      Int098_IRQn
#define HC32_TMRA_9_OVF_NUMBER                      Int099_IRQn

#define HC32_TMRA_9_CMP_HANDLER                     Vector1C8
#define HC32_TMRA_9_OVF_HANDLER                     Vector1CC
#endif


/*
 * OTG units.
 */
#define HC32_OTG1_HANDLER                           Vector1E0
#define HC32_OTG1_NUMBER                            Int104_IRQn


/*
 * USART unit.
 */
#if (HC32_SERIAL_USE_USART1)

#define HC32_USART1_EI_NUMBER                          Int086_IRQn
#define HC32_USART1_EI_HANDLER                         Vector198

#define HC32_USART1_RI_NUMBER                          Int087_IRQn
#define HC32_USART1_RI_HANDLER                         Vector19C

#define HC32_USART1_TI_NUMBER                          Int088_IRQn
#define HC32_USART1_TI_HANDLER                         Vector1A0

#define HC32_USART1_RTO_NUMBER                         Int089_IRQn
#define HC32_USART1_RTO_HANDLER                        Vector1A4

#endif

#if (HC32_SERIAL_USE_USART2)

#define HC32_USART2_EI_NUMBER                          Int090_IRQn
#define HC32_USART2_EI_HANDLER                         Vector1A8

#define HC32_USART2_RI_NUMBER                          Int091_IRQn
#define HC32_USART2_RI_HANDLER                         Vector1AC

#define HC32_USART2_TI_NUMBER                          Int028_IRQn
#define HC32_USART2_TI_HANDLER                         VectorB0

#define HC32_USART2_RTO_NUMBER                         Int029_IRQn
#define HC32_USART2_RTO_HANDLER                        VectorB4

#endif

#if (HC32_SERIAL_USE_USART3)

#define HC32_USART3_EI_NUMBER                          Int023_IRQn
#define HC32_USART3_EI_HANDLER                         Vector9C

#define HC32_USART3_RI_NUMBER                          Int092_IRQn
#define HC32_USART3_RI_HANDLER                         Vector1B0

#define HC32_USART3_TI_NUMBER                          Int093_IRQn
#define HC32_USART3_TI_HANDLER                         Vector1B4

#define HC32_USART3_TCI_NUMBER                         Int094_IRQn
#define HC32_USART3_TCI_HANDLER                        Vector1B8

#endif

#if (HC32_SERIAL_USE_USART4)

#define HC32_USART4_EI_NUMBER                          Int095_IRQn
#define HC32_USART4_EI_HANDLER                         Vector1BC

#define HC32_USART4_RI_NUMBER                          Int096_IRQn
#define HC32_USART4_RI_HANDLER                         Vector1C0

#define HC32_USART4_TI_NUMBER                          Int097_IRQn
#define HC32_USART4_TI_HANDLER                         Vector1C4

#define HC32_USART4_TCI_NUMBER                         Int004_IRQn
#define HC32_USART4_TCI_HANDLER                        Vector50

#endif

#if (HC32_SERIAL_USE_USART5)

#define HC32_USART5_EI_NUMBER                          Int020_IRQn
#define HC32_USART5_EI_HANDLER                         Vector90

#define HC32_USART5_RI_NUMBER                          Int021_IRQn
#define HC32_USART5_RI_HANDLER                         Vector94

#define HC32_USART5_TI_NUMBER                          Int022_IRQn
#define HC32_USART5_TI_HANDLER                         Vector98

#define HC32_USART5_TCI_NUMBER                         Int006_IRQn
#define HC32_USART5_TCI_HANDLER                        Vector58

#endif

#if (HC32_SERIAL_USE_USART6)

#define HC32_USART6_EI_NUMBER                          Int020_IRQn
#define HC32_USART6_EI_HANDLER                         Vector90

#define HC32_USART6_RI_NUMBER                          Int021_IRQn
#define HC32_USART6_RI_HANDLER                         Vector94

#define HC32_USART6_TI_NUMBER                          Int022_IRQn
#define HC32_USART6_TI_HANDLER                         Vector98

#define HC32_USART6_RTO_NUMBER                         Int006_IRQn
#define HC32_USART6_RTO_HANDLER                        Vector58

#endif

#if (HC32_SERIAL_USE_USART7)

#define HC32_USART7_EI_NUMBER                          Int105_IRQn
#define HC32_USART7_EI_HANDLER                         Vector1E4

#define HC32_USART7_RI_NUMBER                          Int109_IRQn
#define HC32_USART7_RI_HANDLER                         Vector1F4

#define HC32_USART7_TI_NUMBER                          Int107_IRQn
#define HC32_USART7_TI_HANDLER                         Vector1EC

#define HC32_USART7_TCI_NUMBER                         Int108_IRQn
#define HC32_USART7_TCI_HANDLER                        Vector1F0

#endif

#if (HC32_SERIAL_USE_USART8)

#define HC32_USART8_EI_NUMBER                          Int105_IRQn
#define HC32_USART8_EI_HANDLER                         Vector1E4

#define HC32_USART8_RI_NUMBER                          Int109_IRQn
#define HC32_USART8_RI_HANDLER                         Vector1F4

#define HC32_USART8_TI_NUMBER                          Int107_IRQn
#define HC32_USART8_TI_HANDLER                         Vector1EC

#define HC32_USART8_TCI_NUMBER                         Int108_IRQn
#define HC32_USART8_TCI_HANDLER                        Vector1F0

#endif

//#if (HC32_SERIAL_USE_USART9)
//
//#define HC32_USART9_EI_NUMBER                          Int110_IRQn
//#define HC32_USART9_EI_HANDLER                         Vector1F8
//
//#define HC32_USART9_RI_NUMBER                          Int111_IRQn
//#define HC32_USART9_RI_HANDLER                         Vector1FC
//
//#define HC32_USART9_TI_NUMBER                          Int112_IRQn
//#define HC32_USART9_TI_HANDLER                         Vector200
//
//#define HC32_USART9_TCI_NUMBER                         Int113_IRQn
//#define HC32_USART9_TCI_HANDLER                        Vector204
//
//#endif
//
//#if (HC32_SERIAL_USE_USART10)
//
//#define HC32_USART10_EI_NUMBER                          Int110_IRQn
//#define HC32_USART10_EI_HANDLER                         Vector1F8
//
//#define HC32_USART10_RI_NUMBER                          Int111_IRQn
//#define HC32_USART10_RI_HANDLER                         Vector1FC
//
//#define HC32_USART10_TI_NUMBER                          Int112_IRQn
//#define HC32_USART10_TI_HANDLER                         Vector200
//
//#define HC32_USART10_TCI_NUMBER                         Int113_IRQn
//#define HC32_USART10_TCI_HANDLER                        Vector204
//
//#endif

#if(HC32_I2C_USE_I2C1)

#define HC32_I2C1_TXI_NUMBER                            Int110_IRQn
#define HC32_I2C1_TXI_HANDLER                           Vector1F8

#define HC32_I2C1_RXI_NUMBER                            Int111_IRQn
#define HC32_I2C1_RXI_HANDLER                           Vector1FC

#define HC32_I2C1_TEI_NUMBER                            Int112_IRQn
#define HC32_I2C1_TEI_HANDLER                           Vector200

#define HC32_I2C1_EEI_NUMBER                            Int113_IRQn
#define HC32_I2C1_EEI_HANDLER                           Vector204
#endif

#if(HC32_I2C_USE_I2C2)

#define HC32_I2C2_TXI_NUMBER                            Int007_IRQn
#define HC32_I2C2_TXI_HANDLER                           Vector5C

#define HC32_I2C2_RXI_NUMBER                            Int114_IRQn
#define HC32_I2C2_RXI_HANDLER                           Vector208

#define HC32_I2C2_TEI_NUMBER                            Int008_IRQn
#define HC32_I2C2_TEI_HANDLER                           Vector60

#define HC32_I2C2_EEI_NUMBER                            Int115_IRQn
#define HC32_I2C2_EEI_HANDLER                           Vector20C
#endif

#if(HC32_I2C_USE_I2C3)
#define HC32_I2C3_TEI_NUMBER                            Int112_IRQn
#define HC32_I2C3_TEI_HANDLER                           Vector200

#define HC32_I2C3_EEI_NUMBER                            Int113_IRQn
#define HC32_I2C3_EEI_HANDLER                           Vector204
#endif

#if(HC32_I2C_USE_I2C4)
#define HC32_I2C4_EEI_NUMBER                            Int116_IRQn
#define HC32_I2C4_EEI_HANDLER                           Vector210
#endif

#if(HC32_I2C_USE_I2C5)
#define HC32_I2C5_EEI_NUMBER                            Int117_IRQn
#define HC32_I2C5_EEI_HANDLER                           Vector214
#endif

#if(HC32_I2C_USE_I2C6)
#define HC32_I2C6_EEI_NUMBER                            Int118_IRQn
#define HC32_I2C6_EEI_HANDLER                           Vector218
#endif

/*
 * SDIO unit.
 */
#if (HAL_USE_SDC)
#define HC32_SDIO_HANDLER          Vector1E8
#define HC32_SDIO_NUMBER           Int106_IRQn
#endif

/*
 * CAN unit.
 */
#ifdef HAL_CAN_IFACE1_ENABLE
#define HC32_CAN1_HANDLER          Vector40
#define HC32_CAN1_NUMBER           Int000_IRQn
#endif

#ifdef HAL_CAN_IFACE2_ENABLE
#define HC32_CAN2_HANDLER          Vector54
#define HC32_CAN2_NUMBER           Int005_IRQn

#endif

/**
 * @defgroup INTC_Priority_Sel Interrupt priority level 00 ~ 15
 * @{
 */
#define DDL_IRQ_PRIORITY_00         (0U)
#define DDL_IRQ_PRIORITY_01         (1U)
#define DDL_IRQ_PRIORITY_02         (2U)
#define DDL_IRQ_PRIORITY_03         (3U)
#define DDL_IRQ_PRIORITY_04         (4U)
#define DDL_IRQ_PRIORITY_05         (5U)
#define DDL_IRQ_PRIORITY_06         (6U)
#define DDL_IRQ_PRIORITY_07         (7U)
#define DDL_IRQ_PRIORITY_08         (8U)
#define DDL_IRQ_PRIORITY_09         (9U)
#define DDL_IRQ_PRIORITY_10         (10U)
#define DDL_IRQ_PRIORITY_11         (11U)
#define DDL_IRQ_PRIORITY_12         (12U)
#define DDL_IRQ_PRIORITY_13         (13U)
#define DDL_IRQ_PRIORITY_14         (14U)
#define DDL_IRQ_PRIORITY_15         (15U)
/**
 * @}
 */
/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   PORT0 interrupt priority level setting.
 */
#if !defined(HC32_IRQ_PORT0_PRIORITY) || defined(__DOXYGEN__)
#define HC32_IRQ_PORT0_PRIORITY            6
#endif

/**
 * @brief   PORT1 interrupt priority level setting.
 */
#if !defined(HC32_IRQ_PORT1_PRIORITY) || defined(__DOXYGEN__)
#define HC32_IRQ_PORT1_PRIORITY            6
#endif

/**
 * @brief   PORT2 interrupt priority level setting.
 */
#if !defined(HC32_IRQ_PORT2_PRIORITY) || defined(__DOXYGEN__)
#define HC32_IRQ_PORT2_PRIORITY            6
#endif

/**
 * @brief   PORT3 interrupt priority level setting.
 */
#if !defined(HC32_IRQ_PORT3_PRIORITY) || defined(__DOXYGEN__)
#define HC32_IRQ_PORT3_PRIORITY            6
#endif

/**
 * @brief   PORT4 interrupt priority level setting.
 */
#if !defined(HC32_IRQ_PORT4_PRIORITY) || defined(__DOXYGEN__)
#define HC32_IRQ_PORT4_PRIORITY            6
#endif

/**
 * @brief   PORT5 interrupt priority level setting.
 */
#if !defined(HC32_IRQ_PORT5_PRIORITY) || defined(__DOXYGEN__)
#define HC32_IRQ_PORT5_PRIORITY          6
#endif

/**
 * @brief   PORT6 interrupt priority level setting.
 */
#if !defined(HC32_IRQ_PORT6_PRIORITY) || defined(__DOXYGEN__)
#define HC32_IRQ_PORT6_PRIORITY        6
#endif

/**
 * @brief   PORT7 interrupt priority level setting.
 */
#if !defined(HC32_IRQ_PORT7_PRIORITY) || defined(__DOXYGEN__)
#define HC32_IRQ_PORT7_PRIORITY           6
#endif

/**
 * @brief   PORT8 interrupt priority level setting.
 */
#if !defined(HC32_IRQ_PORT8_PRIORITY) || defined(__DOXYGEN__)
#define HC32_IRQ_PORT8_PRIORITY           6
#endif

/**
 * @brief   PORT9 interrupt priority level setting.
 */
#if !defined(HC32_IRQ_PORT9_PRIORITY) || defined(__DOXYGEN__)
#define HC32_IRQ_PORT9_PRIORITY           6
#endif

/**
 * @brief   PORT10 interrupt priority level setting.
 */
#if !defined(HC32_IRQ_PORT10_PRIORITY) || defined(__DOXYGEN__)
#define HC32_IRQ_PORT10_PRIORITY           6
#endif

/**
 * @brief   PORT11 interrupt priority level setting.
 */
#if !defined(HC32_IRQ_PORT11_PRIORITY) || defined(__DOXYGEN__)
#define HC32_IRQ_PORT11_PRIORITY           6
#endif

/**
 * @brief   PORT12 interrupt priority level setting.
 */
#if !defined(HC32_IRQ_PORT12_PRIORITY) || defined(__DOXYGEN__)
#define HC32_IRQ_PORT12_PRIORITY        6
#endif

/**
 * @brief   PORT13 interrupt priority level setting.
 */
#if !defined(HC32_IRQ_PORT13_PRIORITY) || defined(__DOXYGEN__)
#define HC32_IRQ_PORT13_PRIORITY        6
#endif

/**
 * @brief   PORT14 interrupt priority level setting.
 */
#if !defined(HC32_IRQ_PORT14_PRIORITY) || defined(__DOXYGEN__)
#define HC32_IRQ_PORT14_PRIORITY        6
#endif

/**
 * @brief   PORT15 interrupt priority level setting.
 */
#if !defined(HC32_IRQ_PORT15_PRIORITY) || defined(__DOXYGEN__)
#define HC32_IRQ_PORT15_PRIORITY        6
#endif
/** @} */
/*===========================================================================*/
/* Exteral declarations.                                                     */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif
  void irqInit(void);
  void irqDeinit(void);
#ifdef __cplusplus
}
#endif

#endif /* HC32_ISR_H */

/** @} */
