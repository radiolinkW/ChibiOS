/*
    ChibiOS - Copyright (C) 2022 Radiolink
    Driver by Radiolink Wu, March 2022
*/

/**
 * @file    HC32/HC32F4xx
 * @brief   HC32F4xx HAL subsystem low level driver header.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef HAL_LLD_H
#define HAL_LLD_H

/* Various helpers.*/
#include "nvic.h"
#include "cache.h"
#include "mpu_v7m.h"
#include "hc32_isr.h"
#include "hc32_dma.h"
#include "hc32_registry.h"
#include "hc32_rcc.h"

#define GPIO_READ_WAIT_4                    ((uint16_t)(0x04UL << GPIO_PCCR_RDWT_POS))

#define PWC_UNLOCK_CODE_0                   (0xA501U)
#define PWC_UNLOCK_CODE_1                   (0xA502U)
#define PWC_UNLOCK_CODE_2                   (0xA508U)

#define SRAM_LOCK_CMD                       (0x76U)
#define SRAM_UNLOCK_CMD                     (0x77U)

/**
 * @defgroup SRAM_Configuration_Bits_Mask SRAM Configuration Bits Mask
 * @{
 */
#define SRAM_ECC_MODE_MSK                   (SRAMC_CKCR_ECCMOD)
#define SRAM_CYCLE_MSK                      (SRAMC_WTCR_SRAM123RWT)
/**
 * @}
 */

/**
 * @defgroup SRAM_Index_Bit_Mask SRAM Index Bit Mask
 * @{
 */
#define SRAM_SRAMH              (1UL << 2U)                 /*!< 0x1FFE0000~0x1FFFFFFF, 128KB */
#define SRAM_SRAM123            (1UL << 0U)                 /*!< SRAM1: 0x20000000~0x2001FFFF, 128KB \
                                                                 SRAM2: 0x20020000~0x2003FFFF, 128KB \
                                                                 SRAM3: 0x20040000~0x20057FFF, 96KB */
#define SRAM_SRAM4              (1UL << 1U)                 /*!< 0x20058000~0x2005FFFF, 32KB */
#define SRAM_SRAMB              (1UL << 3U)                 /*!< 0x200F0000~0x200F0FFF, 4KB */
#define SRAM_SRAM_ALL           (SRAM_SRAMH | SRAM_SRAM123 | SRAM_SRAM4 | SRAM_SRAMB)
/**
 * @}
 */

/**
 * @defgroup SRAM_Access_Wait_Cycle SRAM Access Wait Cycle
 * @{
 */
#define SRAM_WAIT_CYCLE_0       (0U)                        /*!< Wait 0 CPU cycle. */
#define SRAM_WAIT_CYCLE_1       (1U)                        /*!< Wait 1 CPU cycle. */
#define SRAM_WAIT_CYCLE_2       (2U)                        /*!< Wait 2 CPU cycles. */
#define SRAM_WAIT_CYCLE_3       (3U)                        /*!< Wait 3 CPU cycles. */
#define SRAM_WAIT_CYCLE_4       (4U)                        /*!< Wait 4 CPU cycles. */
#define SRAM_WAIT_CYCLE_5       (5U)                        /*!< Wait 5 CPU cycles. */
#define SRAM_WAIT_CYCLE_6       (6U)                        /*!< Wait 6 CPU cycles. */
#define SRAM_WAIT_CYCLE_7       (7U)                        /*!< Wait 7 CPU cycles. */
/**
 * @}
 */

#define EFM_SECRET_KEY1                     (0x0123U)
#define EFM_SECRET_KEY2                     (0x3210U)
#define EFM_WAIT_CYCLE_5                    (5U)      /*!< Insert 5 read wait cycles    */

#define HC32_PLLSRC_XTAL                    (0 << 7)
#define HC32_PLLSRC_HRC                     (1 << 7)

/**
 * @brief   HC32_PLLH_M field.
 */
#if ((HC32_PLLH_M_VALUE >= 1) && (HC32_PLLH_M_VALUE <= 4)) ||                \
    defined(__DOXYGEN__)
#define HC32_PLLH_M                  ((HC32_PLLH_M_VALUE -1)<< 0)
#else
#error "invalid HC32_PLLH_M_VALUE value specified"
#endif

/**
 * @brief   HC32_PLLH_N field.
 */
#if ((HC32_PLLH_N_VALUE >= 25) && (HC32_PLLH_N_VALUE <= 150)) ||              \
    defined(__DOXYGEN__)
#define HC32_PLLH_N                  ((HC32_PLLH_N_VALUE -1)<< 8)
#else
#error "invalid HC32_PLLH_N_VALUE value specified"
#endif

/**
 * @brief   HC32_PLLH_P field.
 */
#if ((HC32_PLLH_P_VALUE >= 1) && (HC32_PLLH_P_VALUE <= 16)) ||              \
    defined(__DOXYGEN__)
#define HC32_PLLH_P                  ((HC32_PLLH_P_VALUE -1) << 28)
#else
#error "invalid HC32_PLLH_P_VALUE value specified"
#endif

/**
 * @brief   HC32_PLLH_Q field.
 */
#if ((HC32_PLLH_Q_VALUE >= 1) && (HC32_PLLH_Q_VALUE <= 16)) ||              \
    defined(__DOXYGEN__)
#define HC32_PLLH_Q                  ((HC32_PLLH_Q_VALUE -1) << 24)
#else
#error "invalid HC32_PLLH_Q_VALUE value specified"
#endif

/**
 * @brief   HC32_PLLH_R field.
 */
#if ((HC32_PLLH_R_VALUE >= 1) && (HC32_PLLH_R_VALUE <= 16)) ||              \
    defined(__DOXYGEN__)
#define HC32_PLLH_R                  ((HC32_PLLH_R_VALUE-1) << 20)
#else
#error "invalid HC32_PLLH_R_VALUE value specified"
#endif

/*=========================================================*/
/* External declarations                                   */
/*=========================================================*/

#ifdef _cplusplus
extern "C" {
#endif
  void hal_lld_init(void);
  void hc32_clock_init(void);
#ifdef _cplusplus
}
#endif

#endif  /* HAL_LLD_H */

/** @} */
