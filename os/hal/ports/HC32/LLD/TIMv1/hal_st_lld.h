/*
    ChibiOS - Copyright (C) 2022 Radiolink
    Driver by Radiolink Wu, March 2022
*/

/**
 * @file    TIMv1/hal_st_lld.h
 * @brief   ST Driver subsystem low level driver header.
 * @details This header is designed to be include-able without having to
 *          include other files from the HAL.
 *
 * @addtogroup ST
 * @{
 */

#ifndef HAL_ST_LLD_H
#define HAL_ST_LLD_H

#include "hc32_tim.h"

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/**
 * @brief   Number of supported alarms.
 */
#define ST_LLD_NUM_ALARMS                   1U

/* This has to go after transition to shared handlers is complete for all
   platforms.*/
#define HC32_ST_USE_TIM6_1                   TRUE

#define HC32_TIM6_1_IS_USED
/*===========================================================================*/
/* External declarations.                                                     */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif
  void st_lld_init(void);
  void st_lld_serve_interrupt(void);
#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Driver inline functions.                                                  */
/*===========================================================================*/


#if (OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING) || defined(__DOXYGEN__)

/**
 * @brief   Return the time counter value.
 *
 * @return             The counter value.
 *
 * @notapi
 */
static inline systime_t st_lld_get_counter(void){

  return (systime_t)READ_REG32(M4_TMR6_1->CNTER);
}

/**
 * @brief   Starts the alarm.
 * @note    Makes sure that no spurious alarms are triggered after
 *          this call.
 *
 * @param[in] abstime   the time to be set for the first alarm
 *
 * @notapi
 */
static inline void st_lld_start_alarm(systime_t abstime) {

  /* Timer6 set general compare register A */
  __IO uint32_t *TMR6_GCMxR = (__IO uint32_t *)((uint32_t)&M4_TMR6_1->GCMAR);
  WRITE_REG32(*TMR6_GCMxR ,(uint32_t)abstime);

  /* Enable the TMR6_MATCH_A interrupt */
  SET_REG32_BIT(M4_TMR6_1->ICONR, TMR6_IRQ_EN_CNT_MATCH_A);
}

/**
 * @brief   Stops the alarm interrupt.
 *
 * @notapi
 */
static inline void st_lld_stop_alarm(void) {

  /* Disable the TMR6_MATCH_A interrupt */
  CLEAR_REG32_BIT(M4_TMR6_1->ICONR, TMR6_IRQ_EN_CNT_MATCH_A);
}

/**
 * @brief   Sets the alarm time.
 *
 * @param[in] abstime   the time to be set for the next alarm
 *
 * @notapi
 */
static inline void st_lld_set_alarm(systime_t abstime) {

  /* Timer6 set general compare register A */
  __IO uint32_t *TMR6_GCMxR = (__IO uint32_t *)((uint32_t)&M4_TMR6_1->GCMAR);
  WRITE_REG32(*TMR6_GCMxR ,(uint32_t)abstime);
}

/**
 * @brief   Returns the current alarm time.
 *
 * @return              The currently set alarm time.
 *
 * @notapi
 */
static inline systime_t st_lld_get_alarm(void) {

  __IO uint32_t *TMR6_GCMxR = (uint32_t *)((uint32_t)&M4_TMR6_1->GCMAR);
  return (systime_t)READ_REG32(*TMR6_GCMxR);
}

/**
 * @brief   Determines if the alarm is active.
 *
 * @return              The alarm status.
 * @retval false        if the alarm is not active.
 * @retval true         is the alarm is active
 *
 * @notapi
 */
static inline bool st_lld_is_alarm_active(void) {

  return (bool)(READ_REG32_BIT(M4_TMR6_1->ICONR,TMR6_IRQ_EN_CNT_MATCH_A) != 0);
}
#endif /* OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING */

#endif /* HAL_ST_LLD_H */

/** @} */
