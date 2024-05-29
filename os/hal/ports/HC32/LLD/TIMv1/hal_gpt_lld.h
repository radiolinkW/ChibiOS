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
 * @file    hal_gpt_lld.h
 * @brief   PLATFORM GPT subsystem low level driver header.
 *
 * @addtogroup GPT
 * @{
 */

#ifndef HAL_GPT_LLD_H
#define HAL_GPT_LLD_H

#include "hc32_tim.h"
#if (HAL_USE_GPT == TRUE) || defined(__DOXYGEN__)

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
 * @brief   GPTD1 driver enable switch.
 * @details If set to @p TRUE the support for GPTD1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_GPT_USE_TIM6_1) || defined(__DOXYGEN__)
#define HC32_GPT_USE_TIM6_1                  FALSE
#endif

/**
 * @brief   GPTD2 driver enable switch.
 * @details If set to @p TRUE the support for GPTD1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_GPT_USE_TIM6_2) || defined(__DOXYGEN__)
#define HC32_GPT_USE_TIM6_2                  FALSE
#endif

/**
 * @brief   GPTD3 driver enable switch.
 * @details If set to @p TRUE the support for GPTD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_GPT_USE_TIM6_3) || defined(__DOXYGEN__)
#define HC32_GPT_USE_TIM6_3                  FALSE
#endif

/**
 * @brief   GPTD4 driver enable switch.
 * @details If set to @p TRUE the support for GPTD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_GPT_USE_TIM6_4) || defined(__DOXYGEN__)
#define HC32_GPT_USE_TIM6_4                  FALSE
#endif

/**
 * @brief   GPTD5 driver enable switch.
 * @details If set to @p TRUE the support for GPTD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_GPT_USE_TIM6_5) || defined(__DOXYGEN__)
#define HC32_GPT_USE_TIM6_5                  FALSE
#endif

/**
 * @brief   GPTD6 driver enable switch.
 * @details If set to @p TRUE the support for GPTD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_GPT_USE_TIM6_6) || defined(__DOXYGEN__)
#define HC32_GPT_USE_TIM6_6                  FALSE
#endif

/**
 * @brief   GPTD7 driver enable switch.
 * @details If set to @p TRUE the support for GPTD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_GPT_USE_TIM6_7) || defined(__DOXYGEN__)
#define HC32_GPT_USE_TIM6_7                  FALSE
#endif

/**
 * @brief   GPTD8 driver enable switch.
 * @details If set to @p TRUE the support for GPTD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_GPT_USE_TIM6_8) || defined(__DOXYGEN__)
#define HC32_GPT_USE_TIM6_8                  FALSE
#endif

/**
 * @brief   GPTD9 driver enable switch.
 * @details If set to @p TRUE the support for GPTD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_GPT_USE_TIMA_1) || defined(__DOXYGEN__)
#define HC32_GPT_USE_TIMA_1                  FALSE
#endif

/**
 * @brief   GPTD10 driver enable switch.
 * @details If set to @p TRUE the support for GPTD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_GPT_USE_TIMA_2) || defined(__DOXYGEN__)
#define HC32_GPT_USE_TIMA_2                  FALSE
#endif

/**
 * @brief   GPTD11 driver enable switch.
 * @details If set to @p TRUE the support for GPTD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_GPT_USE_TIMA_3) || defined(__DOXYGEN__)
#define HC32_GPT_USE_TIMA_3                  FALSE
#endif

/**
 * @brief   GPTD12 driver enable switch.
 * @details If set to @p TRUE the support for GPTD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_GPT_USE_TIMA_4) || defined(__DOXYGEN__)
#define HC32_GPT_USE_TIMA_4                  FALSE
#endif

/**
 * @brief   GPTD13 driver enable switch.
 * @details If set to @p TRUE the support for GPTD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_GPT_USE_TIMA_5) || defined(__DOXYGEN__)
#define HC32_GPT_USE_TIMA_5                  FALSE
#endif

/**
 * @brief   GPTD14 driver enable switch.
 * @details If set to @p TRUE the support for GPTD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_GPT_USE_TIMA_6) || defined(__DOXYGEN__)
#define HC32_GPT_USE_TIMA_6                  FALSE
#endif

/**
 * @brief   GPTD15 driver enable switch.
 * @details If set to @p TRUE the support for GPTD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_GPT_USE_TIMA_7) || defined(__DOXYGEN__)
#define HC32_GPT_USE_TIMA_7                  FALSE
#endif

/**
 * @brief   GPTD16 driver enable switch.
 * @details If set to @p TRUE the support for GPTD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_GPT_USE_TIMA_8) || defined(__DOXYGEN__)
#define HC32_GPT_USE_TIMA_8                  FALSE
#endif

/**
 * @brief   GPTD17 driver enable switch.
 * @details If set to @p TRUE the support for GPTD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_GPT_USE_TIMA_9) || defined(__DOXYGEN__)
#define HC32_GPT_USE_TIMA_9                  FALSE
#endif

/**
 * @brief   GPTD18 driver enable switch.
 * @details If set to @p TRUE the support for GPTD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_GPT_USE_TIMA_10) || defined(__DOXYGEN__)
#define HC32_GPT_USE_TIMA_10                  FALSE
#endif

/**
 * @brief   GPTD19 driver enable switch.
 * @details If set to @p TRUE the support for GPTD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_GPT_USE_TIMA_11) || defined(__DOXYGEN__)
#define HC32_GPT_USE_TIMA_11                  FALSE
#endif

/**
 * @brief   GPTD20 driver enable switch.
 * @details If set to @p TRUE the support for GPTD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_GPT_USE_TIMA_12) || defined(__DOXYGEN__)
#define HC32_GPT_USE_TIMA_12                  FALSE
#endif
/** @} */

/* Checks on allocation of TIMx units.*/
#if HC32_GPT_USE_TIM6_1
#if defined(HC32_TIM6_1_IS_USED)
#error "GPTD1 requires TIM6_1 but the timer is already used"
#else
#define HC32_TIM6_1_IS_USED
#endif
#endif

#if HC32_GPT_USE_TIM6_2
#if defined(HC32_TIM6_2_IS_USED)
#error "GPTD2 requires TIM6_2 but the timer is already used"
#else
#define HC32_TIM6_2_IS_USED
#endif
#endif

#if HC32_GPT_USE_TIM6_3
#if defined(HC32_TIM6_3_IS_USED)
#error "GPTD3 requires TIM6_3 but the timer is already used"
#else
#define HC32_TIM6_3_IS_USED
#endif
#endif

#if HC32_GPT_USE_TIM6_4
#if defined(HC32_TIM6_4_IS_USED)
#error "GPTD4 requires TIM6_4 but the timer is already used"
#else
#define HC32_TIM6_4_IS_USED
#endif
#endif

#if HC32_GPT_USE_TIM6_5
#if defined(HC32_TIM6_5_IS_USED)
#error "GPTD5 requires TIM6_5 but the timer is already used"
#else
#define HC32_TIM6_5_IS_USED
#endif
#endif

#if HC32_GPT_USE_TIM6_6
#if defined(HC32_TIM6_6_IS_USED)
#error "GPTD6 requires TIM6_6 but the timer is already used"
#else
#define HC32_TIM6_6_IS_USED
#endif
#endif

#if HC32_GPT_USE_TIM6_7
#if defined(HC32_TIM6_7_IS_USED)
#error "GPTD7 requires TIM6_7 but the timer is already used"
#else
#define HC32_TIM6_7_IS_USED
#endif
#endif

#if HC32_GPT_USE_TIM6_8
#if defined(HC32_TIM6_8_IS_USED)
#error "GPTD8 requires TIM6_8 but the timer is already used"
#else
#define HC32_TIM6_8_IS_USED
#endif
#endif

#if HC32_GPT_USE_TIMA_1
#if defined(HC32_TIMA_1_IS_USED)
#error "GPTD9 requires TIMA_1 but the timer is already used"
#else
#define HC32_TIMA_1_IS_USED
#endif
#endif

#if HC32_GPT_USE_TIMA_2
#if defined(HC32_TIMA_2_IS_USED)
#error "GPTD10 requires TIMA_2 but the timer is already used"
#else
#define HC32_TIMA_2_IS_USED
#endif
#endif

#if HC32_GPT_USE_TIMA_3
#if defined(HC32_TIMA_3_IS_USED)
#error "GPTD11 requires TIMA_3 but the timer is already used"
#else
#define HC32_TIMA_3_IS_USED
#endif
#endif

#if HC32_GPT_USE_TIMA_4
#if defined(HC32_TIMA_4_IS_USED)
#error "GPTD12 requires TIMA_4 but the timer is already used"
#else
#define HC32_TIMA_4_IS_USED
#endif
#endif

#if HC32_GPT_USE_TIMA_5
#if defined(HC32_TIMA_5_IS_USED)
#error "GPTD13 requires TIMA_5 but the timer is already used"
#else
#define HC32_TIMA_5_IS_USED
#endif
#endif

#if HC32_GPT_USE_TIMA_6
#if defined(HC32_TIMA_6_IS_USED)
#error "GPTD14 requires TIMA_6 but the timer is already used"
#else
#define HC32_TIMA_6_IS_USED
#endif
#endif

#if HC32_GPT_USE_TIMA_7
#if defined(HC32_TIMA_7_IS_USED)
#error "GPTD15 requires TIMA_7 but the timer is already used"
#else
#define HC32_TIMA_7_IS_USED
#endif
#endif

#if HC32_GPT_USE_TIMA_8
#if defined(HC32_TIMA_8_IS_USED)
#error "GPTD16 requires TIMA_8 but the timer is already used"
#else
#define HC32_TIMA_81_IS_USED
#endif
#endif

#if HC32_GPT_USE_TIMA_9
#if defined(HC32_TIMA_9_IS_USED)
#error "GPTD17 requires TIMA_9 but the timer is already used"
#else
#define HC32_TIMA_9_IS_USED
#endif
#endif

#if HC32_GPT_USE_TIMA_10
#if defined(HC32_TIMA_10_IS_USED)
#error "GPTD18 requires TIMA_10 but the timer is already used"
#else
#define HC32_TIMA_10_IS_USED
#endif
#endif

#if HC32_GPT_USE_TIMA_11
#if defined(HC32_TIMA_11_IS_USED)
#error "GPTD19 requires TIMA_11 but the timer is already used"
#else
#define HC32_TIMA_11_IS_USED
#endif
#endif

#if HC32_GPT_USE_TIMA_12
#if defined(HC32_TIMA_12_IS_USED)
#error "GPTD20 requires TIMA_12 but the timer is already used"
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
 * @brief   GPT frequency type.
 */
typedef uint32_t gptfreq_t;

/**
 * @brief   GPT counter type.
 */
typedef uint16_t gptcnt_t;

/**
 * @brief   Driver configuration structure.
 * @note    It could be empty on some architectures.
 */
typedef struct {
  /**
   * @brief   Timer clock in Hz.
   * @note    The low level can use assertions in order to catch invalid
   *          frequency specifications.
   */
  gptfreq_t                 frequency;
  /**
   * @brief   Timer callback pointer.
   * @note    This callback is invoked on GPT counter events.
   */
  gptcallback_t             callback;
  /* End of the mandatory fields.*/
} GPTConfig;

/**
 * @brief   Structure representing a GPT driver.
 */
struct GPTDriver {
  /**
   * @brief Driver state.
   */
  gptstate_t                state;
  /**
   * @brief Current configuration data.
   */
  const GPTConfig           *config;
#if defined(GPT_DRIVER_EXT_FIELDS)
  GPT_DRIVER_EXT_FIELDS
#endif
  /* End of the mandatory fields.*/
  M4_TMRA_TypeDef               *tima ;
  M4_TMR6_TypeDef               *tim6 ;
  uint32_t                      irqnum;
  en_int_src_t                  intsrc;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/** @brief   Changes the interval of GPT peripheral.**/
static inline void gpt_change_interval(GPTDriver *gptp, gptcnt_t interval){

  if(gptp->tim6 != 0){

    WRITE_REG32(gptp->tim6->PERAR, (uint32_t)(interval - 1U));
  }
  else if(gptp->tima != 0){

    WRITE_REG32(gptp->tima->PERAR, (uint32_t)(interval - 1U));
  }
}

/** @brief   Returns the interval of GPT peripheral **/
static inline gptcnt_t gpt_get_interval(GPTDriver *gptp){

  if(gptp->tim6 != 0){

   return (gptcnt_t)(READ_REG32(gptp->tim6->PERAR) + 1);
  }
  else if(gptp->tima != 0){

    return (gptcnt_t)(READ_REG32(gptp->tima->PERAR) + 1);
  }

}


/** @brief   Returns the counter value of GPT peripheral.**/
static inline gptcnt_t gpt_get_counter(GPTDriver *gptp){

  if(gptp->tim6 != 0){

    return (gptcnt_t)(READ_REG32(gptp->tim6->CNTER));
  }
  else if(gptp->tima != 0){

    return (gptcnt_t)(READ_REG32(gptp->tima->CNTER));
  }
}

/**
 * @brief   Changes the interval of GPT peripheral.
 * @details This function changes the interval of a running GPT unit.
 * @pre     The GPT unit must have been activated using @p gptStart().
 * @pre     The GPT unit must have been running in continuous mode using
 *          @p gptStartContinuous().
 * @post    The GPT unit interval is changed to the new value.
 * @note    The function has effect at the next cycle start.
 *
 * @param[in] gptp      pointer to a @p GPTDriver object
 * @param[in] interval  new cycle time in timer ticks
 * @notapi
 */
#define gpt_lld_change_interval(gptp, interval)     gpt_change_interval(gptp, interval)

/**
 * @brief   Returns the interval of GPT peripheral.
 * @pre     The GPT unit must be running in continuous mode.
 *
 * @param[in] gptp      pointer to a @p GPTDriver object
 * @return              The current interval.
 *
 * @notapi
 */
#define gpt_lld_get_interval(gptp)                  gpt_get_interval(gptp)

/**
 * @brief   Returns the counter value of GPT peripheral.
 * @pre     The GPT unit must be running in continuous mode.
 * @note    The nature of the counter is not defined, it may count upward
 *          or downward, it could be continuously running or not.
 *
 * @param[in] gptp      pointer to a @p GPTDriver object
 * @return              The current counter value.
 *
 * @notapi
 */
#define gpt_lld_get_counter(gptp)                   gpt_get_counter(gptp)

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if (HC32_GPT_USE_TIM6_1 == TRUE) && !defined(__DOXYGEN__)
extern GPTDriver GPTD1;
#endif

#if (HC32_GPT_USE_TIM6_2 == TRUE) && !defined(__DOXYGEN__)
extern GPTDriver GPTD2;
#endif

#if (HC32_GPT_USE_TIM6_3 == TRUE) && !defined(__DOXYGEN__)
extern GPTDriver GPTD3;
#endif

#if (HC32_GPT_USE_TIM6_4 == TRUE) && !defined(__DOXYGEN__)
extern GPTDriver GPTD4;
#endif

#if (HC32_GPT_USE_TIM6_5 == TRUE) && !defined(__DOXYGEN__)
extern GPTDriver GPTD5;
#endif

#if (HC32_GPT_USE_TIM6_6 == TRUE) && !defined(__DOXYGEN__)
extern GPTDriver GPTD6;
#endif

#if (HC32_GPT_USE_TIM6_7 == TRUE) && !defined(__DOXYGEN__)
extern GPTDriver GPTD7;
#endif

#if (HC32_GPT_USE_TIM6_8 == TRUE) && !defined(__DOXYGEN__)
extern GPTDriver GPTD8;
#endif

#if (HC32_GPT_USE_TIMA_1 == TRUE) && !defined(__DOXYGEN__)
extern GPTDriver GPTD9;
#endif

#if (HC32_GPT_USE_TIMA_2 == TRUE) && !defined(__DOXYGEN__)
extern GPTDriver GPTD10;
#endif

#if (HC32_GPT_USE_TIMA_3 == TRUE) && !defined(__DOXYGEN__)
extern GPTDriver GPTD11;
#endif

#if (HC32_GPT_USE_TIMA_4 == TRUE) && !defined(__DOXYGEN__)
extern GPTDriver GPTD12;
#endif

#if (HC32_GPT_USE_TIMA_5 == TRUE) && !defined(__DOXYGEN__)
extern GPTDriver GPTD13;
#endif

#if (HC32_GPT_USE_TIMA_6 == TRUE) && !defined(__DOXYGEN__)
extern GPTDriver GPTD14;
#endif

#if (HC32_GPT_USE_TIMA_7 == TRUE) && !defined(__DOXYGEN__)
extern GPTDriver GPTD15;
#endif

#if (HC32_GPT_USE_TIMA_8 == TRUE) && !defined(__DOXYGEN__)
extern GPTDriver GPTD16;
#endif

#if (HC32_GPT_USE_TIMA_9 == TRUE) && !defined(__DOXYGEN__)
extern GPTDriver GPTD17;
#endif

#if (HC32_GPT_USE_TIMA_10 == TRUE) && !defined(__DOXYGEN__)
extern GPTDriver GPTD18;
#endif

#if (HC32_GPT_USE_TIMA_11 == TRUE) && !defined(__DOXYGEN__)
extern GPTDriver GPTD19;
#endif

#if (HC32_GPT_USE_TIMA_12 == TRUE) && !defined(__DOXYGEN__)
extern GPTDriver GPTD20;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void gpt_lld_init(void);
  void gpt_lld_start(GPTDriver *gptp);
  void gpt_lld_stop(GPTDriver *gptp);
  void gpt_lld_start_timer(GPTDriver *gptp, gptcnt_t interval);
  void gpt_lld_stop_timer(GPTDriver *gptp);
  void gpt_lld_polled_delay(GPTDriver *gptp, gptcnt_t interval);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_GPT == TRUE */

#endif /* HAL_GPT_LLD_H */

/** @} */
