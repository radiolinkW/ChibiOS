/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @file    hal_icu_lld.h
 * @brief   PLATFORM ICU subsystem low level driver header.
 *
 * @addtogroup ICU
 * @{
 */

#ifndef HAL_ICU_LLD_H
#define HAL_ICU_LLD_H

#if (HAL_USE_ICU == TRUE) || defined(__DOXYGEN__)

#include "hc32_tim.h"
/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    PLATFORM configuration options
 * @{
 */
/**
 * @brief   ICUD1 driver enable switch.
 * @details If set to @p TRUE the support for ICUD1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_ICU_USE_TIM6_1) || defined(__DOXYGEN__)
#define HC32_ICU_USE_TIM6_1                  FALSE
#endif

/**
 * @brief   ICUD2 driver enable switch.
 * @details If set to @p TRUE the support for ICUD1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_ICU_USE_TIM6_2) || defined(__DOXYGEN__)
#define HC32_ICU_USE_TIM6_2                  FALSE
#endif

/**
 * @brief   ICUD3 driver enable switch.
 * @details If set to @p TRUE the support for ICUD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_ICU_USE_TIM6_3) || defined(__DOXYGEN__)
#define HC32_ICU_USE_TIM6_3                  FALSE
#endif

/**
 * @brief   ICUD4 driver enable switch.
 * @details If set to @p TRUE the support for ICUD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_ICU_USE_TIM6_4) || defined(__DOXYGEN__)
#define HC32_ICU_USE_TIM6_4                  FALSE
#endif

/**
 * @brief   ICUD5 driver enable switch.
 * @details If set to @p TRUE the support for ICUD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_ICU_USE_TIM6_5) || defined(__DOXYGEN__)
#define HC32_ICU_USE_TIM6_5                  FALSE
#endif

/**
 * @brief   ICUD6 driver enable switch.
 * @details If set to @p TRUE the support for ICUD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_ICU_USE_TIM6_6) || defined(__DOXYGEN__)
#define HC32_ICU_USE_TIM6_6                  FALSE
#endif

/**
 * @brief   ICUD7 driver enable switch.
 * @details If set to @p TRUE the support for ICUD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_ICU_USE_TIM6_7) || defined(__DOXYGEN__)
#define HC32_ICU_USE_TIM6_7                  FALSE
#endif

/**
 * @brief   ICUD8 driver enable switch.
 * @details If set to @p TRUE the support for ICUD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_ICU_USE_TIM6_8) || defined(__DOXYGEN__)
#define HC32_ICU_USE_TIM6_8                  FALSE
#endif

/* Checks on allocation of TIMx units.*/
#if HC32_ICU_USE_TIM6_1
#if defined(HC32_TIM6_1_IS_USED)
#error "ICUD1 requires TIM6_1 but the timer is already used"
#else
#define HC32_TIM6_1_IS_USED
#endif
#endif

#if HC32_ICU_USE_TIM6_2
#if defined(HC32_TIM6_2_IS_USED)
#error "ICUD2 requires TIM6_2 but the timer is already used"
#else
#define HC32_TIM6_2_IS_USED
#endif
#endif

#if HC32_ICU_USE_TIM6_3
#if defined(HC32_TIM6_3_IS_USED)
#error "ICUD3 requires TIM6_3 but the timer is already used"
#else
#define HC32_TIM6_3_IS_USED
#endif
#endif

#if HC32_ICU_USE_TIM6_4
#if defined(HC32_TIM6_4_IS_USED)
#error "ICUD4 requires TIM6_4 but the timer is already used"
#else
#define HC32_TIM6_4_IS_USED
#endif
#endif

#if HC32_ICU_USE_TIM6_5
#if defined(HC32_TIM6_5_IS_USED)
#error "ICUD5 requires TIM6_5 but the timer is already used"
#else
#define HC32_TIM6_5_IS_USED
#endif
#endif

#if HC32_ICU_USE_TIM6_6
#if defined(HC32_TIM6_6_IS_USED)
#error "ICUD6 requires TIM6_6 but the timer is already used"
#else
#define HC32_TIM6_6_IS_USED
#endif
#endif

#if HC32_ICU_USE_TIM6_7
#if defined(HC32_TIM6_7_IS_USED)
#error "ICUD7 requires TIM6_7 but the timer is already used"
#else
#define HC32_TIM6_7_IS_USED
#endif
#endif

#if HC32_ICU_USE_TIM6_8
#if defined(HC32_TIM6_8_IS_USED)
#error "ICUD8 requires TIM6_8 but the timer is already used"
#else
#define HC32_TIM6_8_IS_USED
#endif
#endif

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   ICU driver mode.
 */
typedef enum {
  ICU_INPUT_ACTIVE_HIGH = 0,        /**< Trigger on rising edge.            */
  ICU_INPUT_ACTIVE_LOW = 1          /**< Trigger on falling edge.           */
} icumode_t;

/**
 * @brief   ICU frequency type.
 */
typedef uint32_t icufreq_t;

/**
 * @brief   ICU counter type.
 */
typedef uint32_t icucnt_t;

/**
 * @brief   ICU channel type.
 */
typedef enum {
  ICU_CHANNEL_1 = 0,              /**< Use TIMxCH1.      */
  ICU_CHANNEL_2 = 1,              /**< Use TIMxCH2.      */
} icuchannel_t;

/**
 * @brief   Driver configuration structure.
 * @note    It could be empty on some architectures.
 */
typedef struct {
  /**
   * @brief   Driver mode.
   */
  icumode_t                 mode;
  /**
   * @brief   Timer clock in Hz.
   * @note    The low level can use assertions in order to catch invalid
   *          frequency specifications.
   */
  icufreq_t                 frequency;
  /**
   * @brief   Callback for pulse width measurement.
   */
  icucallback_t             width_cb;
  /**
   * @brief   Callback for cycle period measurement.
   */
  icucallback_t             period_cb;
  /**
   * @brief   Callback for timer overflow.
   */
  icucallback_t             overflow_cb;

  icucallback_t             irq_cb;

  icuchannel_t              Channel;
  /* End of the mandatory fields.*/
} ICUConfig;

/**
 * @brief   Structure representing an ICU driver.
 */
struct ICUDriver {
  /**
   * @brief Driver state.
   */
  icustate_t                state;
  /**
   * @brief Current configuration data.
   */
  const ICUConfig           *config;
#if defined(ICU_DRIVER_EXT_FIELDS)
  ICU_DRIVER_EXT_FIELDS
#endif

  M4_TMR6_TypeDef               *tim6;
  uint32_t                      ovfnum;
  uint32_t                      cmpnum;
  uint32_t                      cmpbnum;
  en_int_src_t                  ovfsrc;
  en_int_src_t                  intsrc;
  en_int_src_t                  cmpbsrc;
  uint32_t                      irq_status;
  uint32_t                      irq_priority;
  uint32_t                      times;


  /**
   * @brief TMR6_GCMmR register and TMRA__CMPARm register used for width capture.
   */
   uint32_t         wcmp;
  /**
   * @brief TMR6_PERmR register and TMRA_PERAR used for period capture.
   */
   uint32_t         perp;

};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Returns the width of the latest pulse.
 * @details The pulse width is defined as number of ticks between the start
 *          edge and the stop edge.
 *
 * @param[in] icup      pointer to the @p ICUDriver object
 * @return              The number of ticks.
 *
 * @notapi
 */
#define icu_lld_get_width(icup) ((icup->wcmp) + 1)

/**
 * @brief   Returns the width of the latest cycle.
 * @details The cycle width is defined as number of ticks between a start
 *          edge and the next start edge.
 *
 * @param[in] icup      pointer to the @p ICUDriver object
 * @return              The number of ticks.
 *
 * @notapi
 */
#define icu_lld_get_period(icup) ((icup->perp) + 1)

/**
 * @brief   Check on notifications status.
 *
 * @param[in] icup      pointer to the @p ICUDriver object
 * @return              The notifications status.
 * @retval false        if notifications are not enabled.
 * @retval true         if notifications are enabled.
 *
 * @notapi
 */
#define icu_lld_are_notifications_enabled(icup) false

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if (HC32_ICU_USE_TIM6_1 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD1;
#endif

#if (HC32_ICU_USE_TIM6_2 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD2;
#endif

#if (HC32_ICU_USE_TIM6_3 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD3;
#endif

#if (HC32_ICU_USE_TIM6_4 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD4;
#endif

#if (HC32_ICU_USE_TIM6_5 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD5;
#endif

#if (HC32_ICU_USE_TIM6_6 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD6;
#endif

#if (HC32_ICU_USE_TIM6_7 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD7;
#endif

#if (HC32_ICU_USE_TIM6_8 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD8;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void icu_lld_init(void);
  void icu_lld_start(ICUDriver *icup);
  void icu_lld_stop(ICUDriver *icup);
  void icu_lld_start_capture(ICUDriver *icup);
  bool icu_lld_wait_capture(ICUDriver *icup);
  void icu_lld_stop_capture(ICUDriver *icup);
  void icu_lld_enable_notifications(ICUDriver *icup);
  void icu_lld_disable_notifications(ICUDriver *icup);
  void icu_lld_Cmpaserve_interrupt(ICUDriver *icup);
  void icu_lld_Cmpbserve_interrupt(ICUDriver *icup);
  void icu_lld_Ovfserve_interrupt(ICUDriver *icup);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_ICU == TRUE */

#endif /* HAL_ICU_LLD_H */

/** @} */
