/*
    ChibiOS - Copyright (C) 2022 Radiolink
    Driver by Radiolink Wu, March 2022
*/

/**
 * @file    RCCv1/hc32_hse.inc
 * @brief   Shared HSE clock handler
 *
 * @addtogoup HC32_HSE_HANDER
 * @{
 */

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/* Config Xtal and enable Xtal */
__STATIC_INLINE void hse_init(void){

  __IO uint32_t timeout = 0UL;

  WRITE_REG8(M4_CMU->XTALSTBCR, CLK_XTALSTB_2MS);
  WRITE_REG8(M4_CMU->XTALCFGR, (0x80U | CLK_XTALDRV_LOW | CLK_XTALMODE_OSC));
  WRITE_REG32(bM4_CMU->XTALCR_b.XTALSTP, CLK_XTAL_ON);

  while (timeout <= CLK_XTAL_TIMEOUT)
  {
    if (Set == (READ_REG8_BIT(M4_CMU->OSCSTBSR, CMU_OSCSTBSR_XTALSTBF)))
    {
        break;
    }
    timeout++;
  }
}
