/*
    ChibiOS - Copyright (C) 2022 Radiolink
    Driver by Radiolink Liang, March 2022
*/

/**
 * @file    EXTIv1/HC32_EXTI.h
 * @brief   ST Driver subsystem low level driver header.
 * @details This header is designed to be include-able without having to
 *          include other files from the HAL.
 *
 * @addtogroup ST
 * @{
 */


/**
 * @file    EXTIv1/hc32_exti.h
 * @brief   EXTI helper driver header.
 *
 * @addtogroup hc32_EXTI
 * @{
 */

#ifndef HC32_EXTI_H
#define HC32_EXTI_H

#include "hc32_common.h"

/**
 * @brief  EXINT initialize configuration structure definition
 */
typedef struct
{
    uint32_t    u32ExIntCh;     /*!< ExInt CH.0~15 @ref EXINT_Channel_Sel */
    uint32_t    u32ExIntFAE;    /*!< ExInt filter A function setting, @ref EXINT_FilterAClock_Sel for details */
    uint32_t    u32ExIntFAClk;  /*!< ExInt filter A clock division, @ref EXINT_FilterAClock_Div for details */
    uint32_t    u32ExIntFBE;    /*!< ExInt filter B function setting, @ref EXINT_FilterBClock_Sel for details*/
    uint32_t    u32ExIntFBTime; /*!< ExInt filter B time, @ref EXINT_FilterBTim_Sel for details*/
    uint32_t    u32ExIntLvl;    /*!< ExInt trigger edge, @ref EXINT_Trigger_Sel for details             */
}hc_exint_init_t;


/**
 * @defgroup NMI_TriggerSrc_Sel NMI trigger source selection
 * @{
 */
#define NMI_SRC_SWDT                (1UL << INTC_NMIFR_SWDTFR_POS)
#define NMI_SRC_PVD1                (1UL << INTC_NMIFR_PVD1FR_POS)
#define NMI_SRC_PVD2                (1UL << INTC_NMIFR_PVD2FR_POS)
#define NMI_SRC_XTAL                (1UL << INTC_NMIFR_XTALSTPFR_POS)
#define NMI_SRC_SRAM_PARITY         (1UL << INTC_NMIFR_REPFR_POS)
#define NMI_SRC_SRAM_ECC            (1UL << INTC_NMIFR_RECCFR_POS)
#define NMI_SRC_BUS_ERR             (1UL << INTC_NMIFR_BUSMFR_POS)
#define NMI_SRC_WDT                 (1UL << INTC_NMIFR_WDTFR_POS)
#define NMI_SRC_MASK                (NMI_SRC_SWDT   | NMI_SRC_PVD1          |   \
                                    NMI_SRC_PVD2    | NMI_SRC_XTAL          |   \
                                    NMI_SRC_BUS_ERR | NMI_SRC_SRAM_PARITY   |   \
                                    NMI_SRC_WDT     | NMI_SRC_SRAM_ECC)
/**
 * @}
 */

/**
 * @defgroup NOCCR_Register_Msk Noise cancel register mask
 * @{
 */
#define INTC_NOCCR_MASK     (INTC_NOCCR_NOCSEL)

/**
 * @}
 */


/**
 * @defgroup MNI_Register_Msk NMI register mask
 * @{
 */
#define INTC_NMIENR_MASK    (INTC_NMIENR_SWDTENR | INTC_NMIENR_PVD1ENR      |   \
                            INTC_NMIENR_PVD2ENR | INTC_NMIENR_XTALSTPENR    |   \
                            INTC_NMIENR_REPENR  | INTC_NMIENR_RECCENR       |   \
                            INTC_NMIENR_BUSMENR | INTC_NMIENR_WDTENR)

#define INTC_NMIFR_MASK     (INTC_NMIFR_SWDTFR | INTC_NMIFR_PVD1FR          |   \
                            INTC_NMIFR_PVD2FR   | INTC_NMIFR_XTALSTPFR      |   \
                            INTC_NMIFR_REPFR    | INTC_NMIFR_RECCFR         |   \
                            INTC_NMIFR_BUSMFR   | INTC_NMIFR_WDTFR)

#define INTC_NMICLR_MASK    (INTC_NMICFR_SWDTCFR  | INTC_NMICFR_PVD1CFR     |   \
                            INTC_NMICFR_PVD2CFR | INTC_NMICFR_XTALSTPCFR    |   \
                            INTC_NMICFR_REPCFR  | INTC_NMICFR_RECCCFR       |   \
                            INTC_NMICFR_BUSMCFR | INTC_NMICFR_WDTCFR)
/**
 * @}
 */
/**
 * @}
 */

/**
 * @defgroup EXINT_FilterAClock_Sel External interrupt filter A function selection
 * @{
 */
#define EXINT_FILTER_A_OFF          (0UL)
#define EXINT_FILTER_A_ON           (INTC_EIRQCR_EFEN)
/**
 * @}
 */

/**
 * @defgroup EXINT_FilterBClock_Sel External interrupt filter B function selection
 * @{
 */
#define EXINT_FILTER_B_OFF          (0UL)
#define EXINT_FILTER_B_ON           (INTC_EIRQCR_NOCEN)
/**
 * @}
 */

/**
 * @defgroup EXINT_FilterAClock_Div External interrupt filter A sampling clock division selection
 * @{
 */
#define EXINT_FACLK_HCLK_DIV1        (0UL)
#define EXINT_FACLK_HCLK_DIV8        (INTC_EIRQCR_EISMPCLK_0)
#define EXINT_FACLK_HCLK_DIV32       (INTC_EIRQCR_EISMPCLK_1)
#define EXINT_FACLK_HCLK_DIV64       (INTC_EIRQCR_EISMPCLK)
/**
 * @}
 */

/**
 * @defgroup EXINT_FilterBTim_Sel External interrupt filter B time selection
 * @{
 */
#define EXINT_FBTIM_500NS           (0UL << INTC_NOCCR_NOCSEL_POS)
#define EXINT_FBTIM_1US             (1UL << INTC_NOCCR_NOCSEL_POS)
#define EXINT_FBTIM_2US             (2UL << INTC_NOCCR_NOCSEL_POS)
#define EXINT_FBTIM_4US             (3UL << INTC_NOCCR_NOCSEL_POS)
/**
 * @}
 */

/**
 * @defgroup EXINT_Trigger_Sel External interrupt trigger method selection
 * @{
 */
#define EXINT_TRIGGER_FALLING       (0UL)
#define EXINT_TRIGGER_RISING        (INTC_EIRQCR_EIRQTRG_0)
#define EXINT_TRIGGER_BOTH          (INTC_EIRQCR_EIRQTRG_1)
#define EXINT_TRIGGER_LOW           (INTC_EIRQCR_EIRQTRG)

/**
 * @defgroup EXINT_Channel_Sel External interrupt channel selection
 * @{
 */
#define EXINT_CH00                  (1UL << 0U)
#define EXINT_CH01                  (1UL << 1U)
#define EXINT_CH02                  (1UL << 2U)
#define EXINT_CH03                  (1UL << 3U)
#define EXINT_CH04                  (1UL << 4U)
#define EXINT_CH05                  (1UL << 5U)
#define EXINT_CH06                  (1UL << 6U)
#define EXINT_CH07                  (1UL << 7U)
#define EXINT_CH08                  (1UL << 8U)
#define EXINT_CH09                  (1UL << 9U)
#define EXINT_CH10                  (1UL <<10U)
#define EXINT_CH11                  (1UL <<11U)
#define EXINT_CH12                  (1UL <<12U)
#define EXINT_CH13                  (1UL <<13U)
#define EXINT_CH14                  (1UL <<14U)
#define EXINT_CH15                  (1UL <<15U)
#define EXINT_CH_MASK   (EXINT_CH00 | EXINT_CH01 | EXINT_CH02 | EXINT_CH03 |    \
                         EXINT_CH04 | EXINT_CH05 | EXINT_CH06 | EXINT_CH07 |    \
                         EXINT_CH08 | EXINT_CH09 | EXINT_CH10 | EXINT_CH11 |    \
                         EXINT_CH12 | EXINT_CH13 | EXINT_CH14 | EXINT_CH15)
/**
 * @}
 */
/**
 * @brief  AOS software trigger.
 * @param  None
 * @retval None
 */
__STATIC_INLINE void AOS_SW_Trigger(void)
{
    WRITE_REG32(bM4_AOS->INTSFTTRG_b.STRG, Set);
}

/**
 * @brief  AOS common trigger source 1 config.
 * @param  [in] enTrig can be any value @ref en_event_src_t
 * @retval None
 */
__STATIC_INLINE void AOS_COM_Trigger1(en_event_src_t enTrig)
{
    WRITE_REG32(M4_AOS->COMTRG1, enTrig);
}

/**
 * @brief  AOS common trigger source 2 config.
 * @param  [in] enTrig can be any value @ref en_event_src_t
 * @retval None
 */
__STATIC_INLINE void AOS_COM_Trigger2(en_event_src_t enTrig)
{
    WRITE_REG32(M4_AOS->COMTRG2, enTrig);
}
/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif
  void extiEnablepad(ioportid_t port,
                     iopadid_t pad,hc_exint_init_t hcExIntInit);
  void extiDisablepad(ioportid_t port,
                      iopadid_t pad);
  #ifdef __cplusplus
}
#endif

#endif /* STM32_EXTI_H */

/** @} */
