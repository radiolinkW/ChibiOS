/*
    ChibiOS - Copyright (C) 2022 Radiolink
    Driver by Radiolink Wu, March 2022
*/

/*
 * @file        HC32F4Axx/hc32_rcc.h
 * @brief       RCC helper driver header.
 * @note        This file requires definitions from the HC header file
 *              @p hc32f4a0.h.
 * @addtogroup   HC32F4xx_RCC
 * @{
 */
#ifndef HC32_RCC_H
#define HC32_RCC_H

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @defgroup CLK_Local_Macros CLK Local Macros
 * @brief Be able to modify TIMEOUT according to board condition.
 * @{
 */
#define CLK_XTAL_TIMEOUT                    ((uint32_t)0x1000UL)
#define CLK_XTAL32_TIMEOUT                  ((uint32_t)0x1000UL)
#define CLK_HRC_TIMEOUT                     ((uint32_t)0x1000UL)
#define CLK_MRC_TIMEOUT                     ((uint32_t)0x1000UL)
#define CLK_LRC_TIMEOUT                     ((uint32_t)0x1000UL)
#define CLK_PLLH_TIMEOUT                    ((uint32_t)0x1000UL)
#define CLK_PLLA_TIMEOUT                    ((uint32_t)0x1000UL)

/**
 * @brief Stable waiting time while switching system clock.
 * @note Approx. 30us based on 240M frequency.
 */
#define CLK_SYSCLK_SW_STABLE               (0x200UL)

/**
 * @brief FCGx default value.
 */
#define CLK_FCG0_DEFAULT            (0xFFFFFA0EUL)
#define CLK_FCG1_DEFAULT            (0xFFFFFFFFUL)
#define CLK_FCG2_DEFAULT            (0xFFFFFFFFUL)
#define CLK_FCG3_DEFAULT            (0xFFFFFFFFUL)
/**
 * @}
 */

/**
 * @brief PLLH/A source clock selction.
 */
#define CLK_PLLSRC_XTAL             (0x00UL)
#define CLK_PLLSRC_HRC              (0x01UL)
/**
 * @}
 */

/**
 * @brief XTAL function config.
 */
#define CLK_XTAL_OFF                (CMU_XTALCR_XTALSTP)
#define CLK_XTAL_ON                 (0x00U)

/**
 * @brief XTAL driver ability
 * @note  High: 20 ~ 24MHz, Mid: 16~20MHz, Low: 8~16MHz, ULow 4 ~ 8MHz.
 */
#define CLK_XTALDRV_HIGH            (0x00U << CMU_XTALCFGR_XTALDRV_POS)
#define CLK_XTALDRV_MID             (0x01U << CMU_XTALCFGR_XTALDRV_POS)
#define CLK_XTALDRV_LOW             (0x02U << CMU_XTALCFGR_XTALDRV_POS)
#define CLK_XTALDRV_ULOW            (0x03U << CMU_XTALCFGR_XTALDRV_POS)

/**
 * @brief XTAL mode selection osc or exclk
 */
#define CLK_XTALMODE_OSC            (0x00U)
#define CLK_XTALMODE_EXCLK          (CMU_XTALCFGR_XTALMS)

/**
 * @brief XTAL stable time selection.
 * @note  a cycle of stable counter = a cycle of LRC divide by 8
 */
#define CLK_XTALSTB_133US           (0x01U)       /*!< 35 stable count cycle, approx. 133us */
#define CLK_XTALSTB_255US           (0x02U)       /*!< 67 stable count cycle, approx. 255us */
#define CLK_XTALSTB_499US           (0x03U)       /*!< 131 stable count cycle, approx. 499us */
#define CLK_XTALSTB_988US           (0x04U)       /*!< 259 stable count cycle, approx. 988us */
#define CLK_XTALSTB_2MS             (0x05U)       /*!< 547 stable count cycle, approx. 2ms  */
#define CLK_XTALSTB_4MS             (0x06U)       /*!< 1059 stable count cycle, approx. 4ms */
#define CLK_XTALSTB_8MS             (0x07U)       /*!< 2147 stable count cycle, approx. 8ms */
#define CLK_XTALSTB_16MS            (0x08U)       /*!< 4291 stable count cycle, approx. 16ms */
#define CLK_XTALSTB_31MS            (0x09U)       /*!< 8163 stable count cycle, approx. 32ms */
/**
 * @}
 */

/**
 * @defgroup CLK_System_Clock_Source System Clock Source
 * @{
 */
#define CLK_SYSCLKSOURCE_HRC        (0x00U)
#define CLK_SYSCLKSOURCE_MRC        (0x01U)
#define CLK_SYSCLKSOURCE_LRC        (0x02U)
#define CLK_SYSCLKSOURCE_XTAL       (0x03U)
#define CLK_SYSCLKSOURCE_XTAL32     (0x04U)
#define CLK_SYSCLKSOURCE_PLLH       (0x05U)
/**
 * @}
 */

/**
 * @defgroup CLK_CATE_Sel Clock category selection
 * @{
 */
#define CLK_CATE_PCLK0              (0x01U)
#define CLK_CATE_PCLK1              (0x02U)
#define CLK_CATE_PCLK2              (0x04U)
#define CLK_CATE_PCLK3              (0x08U)
#define CLK_CATE_PCLK4              (0x10U)
#define CLK_CATE_EXCLK              (0x20U)
#define CLK_CATE_HCLK               (0x40U)
#define CLK_CATE_ALL                (CLK_CATE_PCLK0 | CLK_CATE_PCLK1 |  \
                                     CLK_CATE_PCLK2 | CLK_CATE_PCLK3 |  \
                                     CLK_CATE_PCLK4 | CLK_CATE_EXCLK |  \
                                     CLK_CATE_HCLK)
/**
 * @}
 */

/**
 * @defgroup CLK_HCLK_Divider HCLK divider
 * @{
 */
#define CLK_HCLK_DIV1               (0x00U << CMU_SCFGR_HCLKS_POS)
#define CLK_HCLK_DIV2               (0x01U << CMU_SCFGR_HCLKS_POS)
#define CLK_HCLK_DIV4               (0x02U << CMU_SCFGR_HCLKS_POS)
#define CLK_HCLK_DIV8               (0x03U << CMU_SCFGR_HCLKS_POS)
#define CLK_HCLK_DIV16              (0x04U << CMU_SCFGR_HCLKS_POS)
#define CLK_HCLK_DIV32              (0x05U << CMU_SCFGR_HCLKS_POS)
#define CLK_HCLK_DIV64              (0x06U << CMU_SCFGR_HCLKS_POS)
/**
 * @}
 */

/**
 * @defgroup CLK_EXCLK_Divider EXCLK divider
 * @{
 */
#define CLK_EXCLK_DIV1              (0x00U << CMU_SCFGR_EXCKS_POS)
#define CLK_EXCLK_DIV2              (0x01U << CMU_SCFGR_EXCKS_POS)
#define CLK_EXCLK_DIV4              (0x02U << CMU_SCFGR_EXCKS_POS)
#define CLK_EXCLK_DIV8              (0x03U << CMU_SCFGR_EXCKS_POS)
#define CLK_EXCLK_DIV16             (0x04U << CMU_SCFGR_EXCKS_POS)
#define CLK_EXCLK_DIV32             (0x05U << CMU_SCFGR_EXCKS_POS)
#define CLK_EXCLK_DIV64             (0x06U << CMU_SCFGR_EXCKS_POS)
/**
 * @}
 */

/**
 * @defgroup CLK_PCLK4_Divider PCLK4 divider
 * @{
 */
#define CLK_PCLK4_DIV1              (0x00U << CMU_SCFGR_PCLK4S_POS)
#define CLK_PCLK4_DIV2              (0x01U << CMU_SCFGR_PCLK4S_POS)
#define CLK_PCLK4_DIV4              (0x02U << CMU_SCFGR_PCLK4S_POS)
#define CLK_PCLK4_DIV8              (0x03U << CMU_SCFGR_PCLK4S_POS)
#define CLK_PCLK4_DIV16             (0x04U << CMU_SCFGR_PCLK4S_POS)
#define CLK_PCLK4_DIV32             (0x05U << CMU_SCFGR_PCLK4S_POS)
#define CLK_PCLK4_DIV64             (0x06U << CMU_SCFGR_PCLK4S_POS)
/**
 * @}
 */

/**
 * @defgroup CLK_PCLK3_Divider PCLK3 divider
 * @{
 */
#define CLK_PCLK3_DIV1              (0x00U << CMU_SCFGR_PCLK3S_POS)
#define CLK_PCLK3_DIV2              (0x01U << CMU_SCFGR_PCLK3S_POS)
#define CLK_PCLK3_DIV4              (0x02U << CMU_SCFGR_PCLK3S_POS)
#define CLK_PCLK3_DIV8              (0x03U << CMU_SCFGR_PCLK3S_POS)
#define CLK_PCLK3_DIV16             (0x04U << CMU_SCFGR_PCLK3S_POS)
#define CLK_PCLK3_DIV32             (0x05U << CMU_SCFGR_PCLK3S_POS)
#define CLK_PCLK3_DIV64             (0x06U << CMU_SCFGR_PCLK3S_POS)
/**
 * @}
 */

/**
 * @defgroup CLK_PCLK2_Divider PCLK2 divider
 * @{
 */
#define CLK_PCLK2_DIV1              (0x00U << CMU_SCFGR_PCLK2S_POS)
#define CLK_PCLK2_DIV2              (0x01U << CMU_SCFGR_PCLK2S_POS)
#define CLK_PCLK2_DIV4              (0x02U << CMU_SCFGR_PCLK2S_POS)
#define CLK_PCLK2_DIV8              (0x03U << CMU_SCFGR_PCLK2S_POS)
#define CLK_PCLK2_DIV16             (0x04U << CMU_SCFGR_PCLK2S_POS)
#define CLK_PCLK2_DIV32             (0x05U << CMU_SCFGR_PCLK2S_POS)
#define CLK_PCLK2_DIV64             (0x06U << CMU_SCFGR_PCLK2S_POS)
/**
 * @}
 */

/**
 * @defgroup CLK_PCLK1_Divider PCLK1 divider
 * @{
 */
#define CLK_PCLK1_DIV1              (0x00U << CMU_SCFGR_PCLK1S_POS)
#define CLK_PCLK1_DIV2              (0x01U << CMU_SCFGR_PCLK1S_POS)
#define CLK_PCLK1_DIV4              (0x02U << CMU_SCFGR_PCLK1S_POS)
#define CLK_PCLK1_DIV8              (0x03U << CMU_SCFGR_PCLK1S_POS)
#define CLK_PCLK1_DIV16             (0x04U << CMU_SCFGR_PCLK1S_POS)
#define CLK_PCLK1_DIV32             (0x05U << CMU_SCFGR_PCLK1S_POS)
#define CLK_PCLK1_DIV64             (0x06U << CMU_SCFGR_PCLK1S_POS)
/**
 * @}
 */

/**
 * @defgroup CLK_PCLK0_Divider PCLK0 divider
 * @{
 */
#define CLK_PCLK0_DIV1              (0x00U << CMU_SCFGR_PCLK0S_POS)
#define CLK_PCLK0_DIV2              (0x01U << CMU_SCFGR_PCLK0S_POS)
#define CLK_PCLK0_DIV4              (0x02U << CMU_SCFGR_PCLK0S_POS)
#define CLK_PCLK0_DIV8              (0x03U << CMU_SCFGR_PCLK0S_POS)
#define CLK_PCLK0_DIV16             (0x04U << CMU_SCFGR_PCLK0S_POS)
#define CLK_PCLK0_DIV32             (0x05U << CMU_SCFGR_PCLK0S_POS)
#define CLK_PCLK0_DIV64             (0x06U << CMU_SCFGR_PCLK0S_POS)
/**
 * @}
 */

/**
 * @brief PLLH function config.
 */
#define CLK_PLLH_OFF                (CMU_PLLHCR_PLLHOFF)
#define CLK_PLLH_ON                 (0x00U)

#endif /* CHC32_RCC_H */

/** @} */

