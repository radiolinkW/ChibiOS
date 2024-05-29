/*
    ChibiOS - Copyright (C) 2022 Radiolink
    Driver by Radiolink Liang, March 2022
*/

/**
 * @file        EXTIv1
 * @brief      ST Driver subsystem low level driver code.
 *
 * @addtogoup ST
 * @{
 */
/**
 * @file    EXTIv1/hc32_port0.inc
 * @brief   Shared port0 handler.
 *
 * @addtogroup HC32_PORT0_HANDLER
 * @{
 */

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*==================== =======================================================*/

static inline void port8_irq_init(void) {
#if (HAL_USE_PAL && (PAL_USE_WAIT || PAL_USE_CALLBACKS))
  nvicEnableVector(HC32_PORT8_EIRQ_NUMBER, HC32_IRQ_PORT8_PRIORITY);
#endif
}

static inline void port8_irq_deinit(void) {
#if (HAL_USE_PAL && (PAL_USE_WAIT || PAL_USE_CALLBACKS))
  nvicDisableVector(HC32_PORT8_EIRQ_NUMBER);
#endif
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if (HAL_USE_PAL && (PAL_USE_WAIT || PAL_USE_CALLBACKS)) || defined(__DOXYGEN__)
#if !defined(HC32_DISABLE_PORT8_HANDLER)
/**
 * @brief   EXTI[0] interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(HC32_PORT8_EIRQ_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  SET_REG32_BIT(M4_INTC->EIFR, INTC_EIFR_EIFR8);

  SET_REG32_BIT(M4_INTC->EIFCR, INTC_EIFCR_EICFR8);

  exti_serve_irq(8);

  OSAL_IRQ_EPILOGUE();
}
#endif
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/** @} */
