/*
    ChibiOS - Copyright (C) 2022 Radiolink
    Driver by Radiolink Wu, March 2022
*/

/**
 * @file    HC32F4xx/hc32_registry.h
 * @brief   HC32F4xx capabilities registry
 *
 * @addtogroup HAL
 * @{
 */
#ifndef HC32_REGISTRY_H
#define HC32_REGISTRY_H

/* GPIO attributes.*/
#define HC32_HAS_GPIOA                     TRUE
#define HC32_HAS_GPIOB                     TRUE
#define HC32_HAS_GPIOC                     TRUE
#define HC32_HAS_GPIOD                     TRUE
#define HC32_HAS_GPIOE                     TRUE
#if !defined(HC32F4A0Px)
#define HC32_HAS_GPIOF                     TRUE
#define HC32_HAS_GPIOG                     TRUE
#define HC32_HAS_GPIOH                     TRUE
#define HC32_HAS_GPIOI                     TRUE
#define HC32_HAS_GPIOJ                     TRUE
#else
#define HC32_HAS_GPIOF                     FALSE
#define HC32_HAS_GPIOG                     FALSE
#define HC32_HAS_GPIOH                     FALSE
#define HC32_HAS_GPIOI                     FALSE
#define HC32_HAS_GPIOJ                     FALSE
#endif

/* TIM attributes.*/
#define HC32_HAS_TIM6_1                        TRUE
#define HC32_HAS_TIM6_2                        TRUE
#define HC32_HAS_TIM6_3                        TRUE
#define HC32_HAS_TIM6_4                        TRUE
#define HC32_HAS_TIM6_5                        TRUE
#define HC32_HAS_TIM6_6                        TRUE
#define HC32_HAS_TIM6_7                        TRUE
#define HC32_HAS_TIM6_8                        TRUE
#define HC32_HAS_TIMA_1                        TRUE
#define HC32_HAS_TIMA_2                        TRUE
#define HC32_HAS_TIMA_3                        TRUE
#define HC32_HAS_TIMA_4                        TRUE
#define HC32_HAS_TIMA_5                        TRUE
#define HC32_HAS_TIMA_6                        TRUE
#define HC32_HAS_TIMA_7                        TRUE
#define HC32_HAS_TIMA_8                        TRUE
#define HC32_HAS_TIMA_9                        TRUE
#define HC32_HAS_TIMA_10                       TRUE
#define HC32_HAS_TIMA_11                       TRUE
#define HC32_HAS_TIMA_12                       TRUE
#define HC32_HAS_TIM4_1                        TRUE
#define HC32_HAS_TIM4_2                        TRUE
#define HC32_HAS_TIM4_3                        TRUE
#define HC32_HAS_TIM2_1                        TRUE
#define HC32_HAS_TIM2_2                        TRUE
#define HC32_HAS_TIM2_3                        TRUE
#define HC32_HAS_TIM2_4                        TRUE
#define HC32_HAS_TIM0_1                        TRUE
#define HC32_HAS_TIM0_2                        TRUE

#define HC32_TIM6_1_IS_32BITS                 TRUE

/*USART attributes*/
#define HC32_HAS_USART1                      TRUE
#define HC32_HAS_USART2                      TRUE
#define HC32_HAS_USART3                      TRUE
#define HC32_HAS_USART4                      TRUE
#define HC32_HAS_USART5                      TRUE
#define HC32_HAS_USART6                      TRUE
#define HC32_HAS_USART7                      TRUE
#define HC32_HAS_USART8                      TRUE
#define HC32_HAS_USART9                      TRUE
#define HC32_HAS_USART10                     TRUE

/*I2C attributes.*/

#define HC32_HAS_I2C1                       TRUE
#define HC32_HAS_I2C2                       TRUE
#define HC32_HAS_I2C3                       TRUE
#define HC32_HAS_I2C4                       TRUE
#define HC32_HAS_I2C5                       TRUE
#define HC32_HAS_I2C6                       TRUE

/*===========================================================================*/
/* STM32F4A0xx.                                                              */
/*===========================================================================*/
#if defined(HC32F4A0xx)

/* DMA attributes.*/
#define HC32_DMA1_TC_CH0_HANDLER            Vector44
#define HC32_DMA1_TC_CH1_HANDLER            Vector68
#define HC32_DMA1_TC_CH2_HANDLER            VectorD8
#define HC32_DMA1_TC_CH3_HANDLER            VectorDC
#define HC32_DMA1_TC_CH4_HANDLER            VectorE0
#define HC32_DMA1_TC_CH5_HANDLER            VectorE4
#define HC32_DMA1_TC_CH6_HANDLER            VectorE8
#define HC32_DMA1_TC_CH7_HANDLER            VectorEC
#define HC32_DMA1_TC_CH0_IRQn               Int001_IRQn
#define HC32_DMA1_TC_CH1_IRQn               Int010_IRQn
#define HC32_DMA1_TC_CH2_IRQn               Int038_IRQn
#define HC32_DMA1_TC_CH3_IRQn               Int039_IRQn
#define HC32_DMA1_TC_CH4_IRQn               Int040_IRQn
#define HC32_DMA1_TC_CH5_IRQn               Int041_IRQn
#define HC32_DMA1_TC_CH6_IRQn               Int042_IRQn
#define HC32_DMA1_TC_CH7_IRQn               Int043_IRQn
#define HC32_DMA1_TC_CH0_SRC                INT_DMA1_TC0
#define HC32_DMA1_TC_CH1_SRC                INT_DMA1_TC1
#define HC32_DMA1_TC_CH2_SRC                INT_DMA1_TC2
#define HC32_DMA1_TC_CH3_SRC                INT_DMA1_TC3
#define HC32_DMA1_TC_CH4_SRC                INT_DMA1_TC4
#define HC32_DMA1_TC_CH5_SRC                INT_DMA1_TC5
#define HC32_DMA1_TC_CH6_SRC                INT_DMA1_TC6
#define HC32_DMA1_TC_CH7_SRC                INT_DMA1_TC7
#define HC32_DMA1_BTC_CH0_SRC               INT_DMA1_BTC0
#define HC32_DMA1_BTC_CH1_SRC               INT_DMA1_BTC1
#define HC32_DMA1_BTC_CH2_SRC               INT_DMA1_BTC2
#define HC32_DMA1_BTC_CH3_SRC               INT_DMA1_BTC3
#define HC32_DMA1_BTC_CH4_SRC               INT_DAM1_BTC4
#define HC32_DMA1_BTC_CH5_SRC               INT_DMA1_BTC5
#define HC32_DMA1_BTC_CH6_SRC               INT_DMA1_BTC6
#define HC32_DMA1_BTC_CH7_SRC               INT_DMA1_BTC7

#define HC32_DMA2_TC_CH0_HANDLER            VectorB8
#define HC32_DMA2_TC_CH1_HANDLER            VectorBC
#define HC32_DMA2_TC_CH2_HANDLER            VectorF0
#define HC32_DMA2_TC_CH3_HANDLER            VectorF4
#define HC32_DMA2_TC_CH4_HANDLER            VectorF8
#define HC32_DMA2_TC_CH5_HANDLER            VectorFC
#define HC32_DMA2_TC_CH6_HANDLER            Vector100
#define HC32_DMA2_TC_CH7_HANDLER            Vector104
#define HC32_DMA2_TC_CH0_IRQn               Int030_IRQn
#define HC32_DMA2_TC_CH1_IRQn               Int031_IRQn
#define HC32_DMA2_TC_CH2_IRQn               Int044_IRQn
#define HC32_DMA2_TC_CH3_IRQn               Int045_IRQn
#define HC32_DMA2_TC_CH4_IRQn               Int046_IRQn
#define HC32_DMA2_TC_CH5_IRQn               Int047_IRQn
#define HC32_DMA2_TC_CH6_IRQn               Int048_IRQn
#define HC32_DMA2_TC_CH7_IRQn               Int049_IRQn
#define HC32_DMA2_TC_CH0_SRC                INT_DMA2_TC0
#define HC32_DMA2_TC_CH1_SRC                INT_DMA2_TC1
#define HC32_DMA2_TC_CH2_SRC                INT_DMA2_TC2
#define HC32_DMA2_TC_CH3_SRC                INT_DMA2_TC3
#define HC32_DMA2_TC_CH4_SRC                INT_DMA2_TC4
#define HC32_DMA2_TC_CH5_SRC                INT_DMA2_TC5
#define HC32_DMA2_TC_CH6_SRC                INT_DMA2_TC6
#define HC32_DMA2_TC_CH7_SRC                INT_DMA2_TC7
#define HC32_DMA2_BTC_CH0_SRC               INT_DMA2_BTC0
#define HC32_DMA2_BTC_CH1_SRC               INT_DMA2_BTC1
#define HC32_DMA2_BTC_CH2_SRC               INT_DMA2_BTC2
#define HC32_DMA2_BTC_CH3_SRC               INT_DMA2_BTC3
#define HC32_DMA2_BTC_CH4_SRC               INT_DMA2_BTC4
#define HC32_DMA2_BTC_CH5_SRC               INT_DMA2_BTC5
#define HC32_DMA2_BTC_CH6_SRC               INT_DMA2_BTC6
#define HC32_DMA2_BTC_CH7_SRC               INT_DMA2_BTC7

/* USB attributes. */
#define HC32_OTG1_ENDPOINTS                 15

#endif  /* HC32F4A0xx*/

#define HC32_HAS_EXTI                      TRUE

/*
 * GPIO unit.
 */
#define HC32_PORT0_EIRQ_HANDLER            Vector64
#define HC32_PORT1_EIRQ_HANDLER            Vector6C
#define HC32_PORT2_EIRQ_HANDLER            Vector70
#define HC32_PORT3_EIRQ_HANDLER            Vector74
#define HC32_PORT4_EIRQ_HANDLER            Vector78
#define HC32_PORT5_EIRQ_HANDLER            Vector7C
#define HC32_PORT6_EIRQ_HANDLER            Vector80
#define HC32_PORT7_EIRQ_HANDLER            Vector84
#define HC32_PORT8_EIRQ_HANDLER            Vector88
#define HC32_PORT9_EIRQ_HANDLER            Vector8C
#define HC32_PORT10_EIRQ_HANDLER           VectorC0
#define HC32_PORT11_EIRQ_HANDLER           VectorC4
#define HC32_PORT12_EIRQ_HANDLER           VectorC8
#define HC32_PORT13_EIRQ_HANDLER           VectorCC
#define HC32_PORT14_EIRQ_HANDLER           VectorD0
#define HC32_PORT15_EIRQ_HANDLER           VectorD4

#define HC32_PORT0_EIRQ_IRQn               Int009_IRQn
#define HC32_PORT1_EIRQ_IRQn               Int011_IRQn
#define HC32_PORT2_EIRQ_IRQn               Int012_IRQn
#define HC32_PORT3_EIRQ_IRQn               Int013_IRQn
#define HC32_PORT4_EIRQ_IRQn               Int014_IRQn
#define HC32_PORT5_EIRQ_IRQn               Int015_IRQn
#define HC32_PORT6_EIRQ_IRQn               Int016_IRQn
#define HC32_PORT7_EIRQ_IRQn               Int017_IRQn
#define HC32_PORT8_EIRQ_IRQn               Int018_IRQn
#define HC32_PORT9_EIRQ_IRQn               Int019_IRQn
#define HC32_PORT10_EIRQ_IRQn              Int032_IRQn
#define HC32_PORT11_EIRQ_IRQn              Int033_IRQn
#define HC32_PORT12_EIRQ_IRQn              Int034_IRQn
#define HC32_PORT13_EIRQ_IRQn              Int035_IRQn
#define HC32_PORT14_EIRQ_IRQn              Int036_IRQn
#define HC32_PORT15_EIRQ_IRQn              Int037_IRQn

#define HC32_PORT0_EIRQ_SRC                INT_PORT_EIRQ0
#define HC32_PORT1_EIRQ_SRC                INT_PORT_EIRQ1
#define HC32_PORT2_EIRQ_SRC                INT_PORT_EIRQ2
#define HC32_PORT3_EIRQ_SRC                INT_PORT_EIRQ3
#define HC32_PORT4_EIRQ_SRC                INT_PORT_EIRQ4
#define HC32_PORT5_EIRQ_SRC                INT_PORT_EIRQ5
#define HC32_PORT6_EIRQ_SRC                INT_PORT_EIRQ6
#define HC32_PORT7_EIRQ_SRC                INT_PORT_EIRQ7
#define HC32_PORT8_EIRQ_SRC                INT_PORT_EIRQ8
#define HC32_PORT9_EIRQ_SRC                INT_PORT_EIRQ9
#define HC32_PORT10_EIRQ_SRC               INT_PORT_EIRQ10
#define HC32_PORT11_EIRQ_SRC               INT_PORT_EIRQ11
#define HC32_PORT12_EIRQ_SRC               INT_PORT_EIRQ12
#define HC32_PORT13_EIRQ_SRC               INT_PORT_EIRQ13
#define HC32_PORT14_EIRQ_SRC               INT_PORT_EIRQ14
#define HC32_PORT15_EIRQ_SRC               INT_PORT_EIRQ15


#define HC32_PORT0_EIRQ_NUMBER             9
#define HC32_PORT1_EIRQ_NUMBER             11
#define HC32_PORT2_EIRQ_NUMBER             12
#define HC32_PORT3_EIRQ_NUMBER             13
#define HC32_PORT4_EIRQ_NUMBER             14
#define HC32_PORT5_EIRQ_NUMBER             15
#define HC32_PORT6_EIRQ_NUMBER             16
#define HC32_PORT7_EIRQ_NUMBER             17
#define HC32_PORT8_EIRQ_NUMBER             18
#define HC32_PORT9_EIRQ_NUMBER             19
#define HC32_PORT10_EIRQ_NUMBER            32
#define HC32_PORT11_EIRQ_NUMBER            33
#define HC32_PORT12_EIRQ_NUMBER            34
#define HC32_PORT13_EIRQ_NUMBER            35
#define HC32_PORT14_EIRQ_NUMBER            36
#define HC32_PORT15_EIRQ_NUMBER            37


#endif  /* HC32_REGISTRY_H */

/** @} */
