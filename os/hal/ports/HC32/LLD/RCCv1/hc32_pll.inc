/*
    ChibiOS - Copyright (C) 2022 Radiolink
    Driver by Radiolink Wu, March 2022
*/

/**
 * @file    RCCv1/hc32_pll.inc
 * @brief   Shared PLL handler
 *
 * @addtogroup HC32_PLL_HANDLER
 * @{
 */

__STATIC_INLINE void pll_init(void) {

  __IO uint32_t timeout = 0UL;

  /* set PLL source in advance */
  WRITE_REG32(bM4_CMU->PLLHCFGR_b.PLLSRC, CLK_PLLSRC_XTAL);

  WRITE_REG32(M4_CMU->PLLHCFGR,                             \
              (HC32_PLLH_P | HC32_PLLH_Q | HC32_PLLH_R |    \
               HC32_PLLH_N | HC32_PLLSRC | HC32_PLLH_M));

  WRITE_REG32(bM4_CMU->PLLHCR_b.PLLHOFF, CLK_PLLH_ON);

  while (timeout <= CLK_PLLH_TIMEOUT)
  {
    if (Set == (READ_REG8_BIT(M4_CMU->OSCSTBSR, CMU_OSCSTBSR_PLLHSTBF)))
    {
        break;
    }
    timeout++;
  }
}
