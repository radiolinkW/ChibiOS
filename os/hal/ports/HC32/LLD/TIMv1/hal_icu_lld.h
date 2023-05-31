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

/**
 * @brief   ICUD9 driver enable switch.
 * @details If set to @p TRUE the support for ICUD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_ICU_USE_TIMA_1) || defined(__DOXYGEN__)
#define HC32_ICU_USE_TIMA_1                  FALSE
#endif

/**
 * @brief   ICUD10 driver enable switch.
 * @details If set to @p TRUE the support for ICUD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_ICU_USE_TIMA_2) || defined(__DOXYGEN__)
#define HC32_ICU_USE_TIMA_2                  FALSE
#endif

/**
 * @brief   ICUD11 driver enable switch.
 * @details If set to @p TRUE the support for ICUD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_ICU_USE_TIMA_3) || defined(__DOXYGEN__)
#define HC32_ICU_USE_TIMA_3                  FALSE
#endif

/**
 * @brief   ICUD12 driver enable switch.
 * @details If set to @p TRUE the support for ICUD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_ICU_USE_TIMA_4) || defined(__DOXYGEN__)
#define HC32_ICU_USE_TIMA_4                  FALSE
#endif

/**
 * @brief   ICUD13 driver enable switch.
 * @details If set to @p TRUE the support for ICUD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_ICU_USE_TIMA_5) || defined(__DOXYGEN__)
#define HC32_ICU_USE_TIMA_5                  FALSE
#endif

/**
 * @brief   ICUD14 driver enable switch.
 * @details If set to @p TRUE the support for ICUD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_ICU_USE_TIMA_6) || defined(__DOXYGEN__)
#define HC32_ICU_USE_TIMA_6                  FALSE
#endif

/**
 * @brief   ICUD15 driver enable switch.
 * @details If set to @p TRUE the support for ICUD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_ICU_USE_TIMA_7) || defined(__DOXYGEN__)
#define HC32_ICU_USE_TIMA_7                  FALSE
#endif

/**
 * @brief   ICUD16 driver enable switch.
 * @details If set to @p TRUE the support for ICUD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_ICU_USE_TIMA_8) || defined(__DOXYGEN__)
#define HC32_ICU_USE_TIMA_8                  FALSE
#endif

/**
 * @brief   ICUD17 driver enable switch.
 * @details If set to @p TRUE the support for ICUD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_ICU_USE_TIMA_9) || defined(__DOXYGEN__)
#define HC32_ICU_USE_TIMA_9                  FALSE
#endif

/**
 * @brief   ICUD18 driver enable switch.
 * @details If set to @p TRUE the support for ICUD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_ICU_USE_TIMA_10) || defined(__DOXYGEN__)
#define HC32_ICU_USE_TIMA_10                  FALSE
#endif

/**
 * @brief   ICUD19 driver enable switch.
 * @details If set to @p TRUE the support for ICUD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_ICU_USE_TIMA_11) || defined(__DOXYGEN__)
#define HC32_ICU_USE_TIMA_11                  FALSE
#endif

/**
 * @brief   ICUD20 driver enable switch.
 * @details If set to @p TRUE the support for ICUD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_ICU_USE_TIMA_12) || defined(__DOXYGEN__)
#define HC32_ICU_USE_TIMA_12                  FALSE
#endif
/** @} */

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

#if HC32_ICU_USE_TIMA_1
#if defined(HC32_TIMA_1_IS_USED)
#error "ICUD9 requires TIMA_1 but the timer is already used"
#else
#define HC32_TIMA_1_IS_USED
#endif
#endif

#if HC32_ICU_USE_TIMA_2
#if defined(HC32_TIMA_2_IS_USED)
#error "ICUD10 requires TIMA_2 but the timer is already used"
#else
#define HC32_TIMA_2_IS_USED
#endif
#endif

#if HC32_ICU_USE_TIMA_3
#if defined(HC32_TIMA_3_IS_USED)
#error "ICUD11 requires TIMA_3 but the timer is already used"
#else
#define HC32_TIMA_3_IS_USED
#endif
#endif

#if HC32_ICU_USE_TIMA_4
#if defined(HC32_TIMA_4_IS_USED)
#error "ICUD12 requires TIMA_4 but the timer is already used"
#else
#define HC32_TIMA_4_IS_USED
#endif
#endif

#if HC32_ICU_USE_TIMA_5
#if defined(HC32_TIMA_5_IS_USED)
#error "ICUD13 requires TIMA_5 but the timer is already used"
#else
#define HC32_TIMA_5_IS_USED
#endif
#endif

#if HC32_ICU_USE_TIMA_6
#if defined(HC32_TIMA_6_IS_USED)
#error "ICUD14 requires TIMA_6 but the timer is already used"
#else
#define HC32_TIMA_6_IS_USED
#endif
#endif

#if HC32_ICU_USE_TIMA_7
#if defined(HC32_TIMA_7_IS_USED)
#error "ICUD15 requires TIMA_7 but the timer is already used"
#else
#define HC32_TIMA_7_IS_USED
#endif
#endif

#if HC32_ICU_USE_TIMA_8
#if defined(HC32_TIMA_8_IS_USED)
#error "ICUD16 requires TIMA_8 but the timer is already used"
#else
#define HC32_TIMA_81_IS_USED
#endif
#endif

#if HC32_ICU_USE_TIMA_9
#if defined(HC32_TIMA_9_IS_USED)
#error "ICUD17 requires TIMA_9 but the timer is already used"
#else
#define HC32_TIMA_9_IS_USED
#endif
#endif

#if HC32_ICU_USE_TIMA_10
#if defined(HC32_TIMA_10_IS_USED)
#error "ICUD18 requires TIMA_10 but the timer is already used"
#else
#define HC32_TIMA_10_IS_USED
#endif
#endif

#if HC32_ICU_USE_TIMA_11
#if defined(HC32_TIMA_11_IS_USED)
#error "ICUD19 requires TIMA_11 but the timer is already used"
#else
#define HC32_TIMA_11_IS_USED
#endif
#endif

#if HC32_ICU_USE_TIMA_12
#if defined(HC32_TIMA_12_IS_USED)
#error "ICUD20 requires TIMA_12 but the timer is already used"
#else
#define HC32_TIMA_12_IS_USED
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

  M4_TMRA_TypeDef               *tima;
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

#if (HC32_ICU_USE_TIMA_1 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD9;
#endif

#if (HC32_ICU_USE_TIMA_1 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD9;
#endif

#if (HC32_ICU_USE_TIMA_2 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD10;
#endif

#if (HC32_ICU_USE_TIMA_3 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD11;
#endif

#if (HC32_ICU_USE_TIMA_4 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD12;
#endif

#if (HC32_ICU_USE_TIMA_5 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD13;
#endif

#if (HC32_ICU_USE_TIMA_6 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD14;
#endif

#if (HC32_ICU_USE_TIMA_7 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD15;
#endif

#if (HC32_ICU_USE_TIMA_8 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD16;
#endif

#if (HC32_ICU_USE_TIMA_9 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD17;
#endif

#if (HC32_ICU_USE_TIMA_10 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD18;
#endif

#if (HC32_ICU_USE_TIMA_11 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD19;
#endif

#if (HC32_ICU_USE_TIMA_12 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD20;
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
  void icu_lld_Cmpserve_interrupt(ICUDriver *icup);
  void icu_lld_Ovfserve_interrupt(ICUDriver *icup);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_ICU == TRUE */

#endif /* HAL_ICU_LLD_H */

/** @} */
