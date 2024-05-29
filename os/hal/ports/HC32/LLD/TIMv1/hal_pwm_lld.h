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
 * @file    hal_pwm_lld.h
 * @brief   PLATFORM PWM subsystem low level driver header.
 *
 * @addtogroup PWM
 * @{
 */

#ifndef HAL_PWM_LLD_H
#define HAL_PWM_LLD_H

#if (HAL_USE_PWM == TRUE) || defined(__DOXYGEN__)

#include "hc32_tim.h"
/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @brief   Number of PWM channels per PWM driver.
 */
#define PWM_CHANNELS                            4

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    PLATFORM configuration options
 * @{
 */
/**
 * @brief   PWMD9 driver enable switch.
 * @details If set to @p TRUE the support for PWM1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_PWM_USE_TIMA_1) || defined(__DOXYGEN__)
#define HC32_PWM_USE_TIMA_1                  FALSE
#endif

/**
 * @brief   PWMD10 driver enable switch.
 * @details If set to @p TRUE the support for PWM1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_PWM_USE_TIMA_2) || defined(__DOXYGEN__)
#define HC32_PWM_USE_TIMA_2                  FALSE
#endif

/**
 * @brief   PWMD11 driver enable switch.
 * @details If set to @p TRUE the support for PWM1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_PWM_USE_TIMA_3) || defined(__DOXYGEN__)
#define HC32_PWM_USE_TIMA_3                  FALSE
#endif

/**
 * @brief   PWMD12 driver enable switch.
 * @details If set to @p TRUE the support for PWM1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_PWM_USE_TIMA_4) || defined(__DOXYGEN__)
#define HC32_PWM_USE_TIMA_4                  FALSE
#endif

/**
 * @brief   PWMD13 driver enable switch.
 * @details If set to @p TRUE the support for PWM1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_PWM_USE_TIMA_5) || defined(__DOXYGEN__)
#define HC32_PWM_USE_TIMA_5                  FALSE
#endif

/**
 * @brief   PWMD14 driver enable switch.
 * @details If set to @p TRUE the support for PWM1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_PWM_USE_TIMA_6) || defined(__DOXYGEN__)
#define HC32_PWM_USE_TIMA_6                  FALSE
#endif

/**
 * @brief   PWMD15 driver enable switch.
 * @details If set to @p TRUE the support for PWM1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_PWM_USE_TIMA_7) || defined(__DOXYGEN__)
#define HC32_PWM_USE_TIMA_7                  FALSE
#endif

/**
 * @brief   PWMD16 driver enable switch.
 * @details If set to @p TRUE the support for PWM1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_PWM_USE_TIMA_8) || defined(__DOXYGEN__)
#define HC32_PWM_USE_TIMA_8                  FALSE
#endif

/**
 * @brief   PWMD17 driver enable switch.
 * @details If set to @p TRUE the support for PWM1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_PWM_USE_TIMA_9) || defined(__DOXYGEN__)
#define HC32_PWM_USE_TIMA_9                  FALSE
#endif

/**
 * @brief   PWMD18 driver enable switch.
 * @details If set to @p TRUE the support for PWM1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_PWM_USE_TIMA_10) || defined(__DOXYGEN__)
#define HC32_PWM_USE_TIMA_10                  FALSE
#endif

/**
 * @brief   PWMD19 driver enable switch.
 * @details If set to @p TRUE the support for PWM1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_PWM_USE_TIMA_11) || defined(__DOXYGEN__)
#define HC32_PWM_USE_TIMA_11                  FALSE
#endif

/**
 * @brief   PWMD20 driver enable switch.
 * @details If set to @p TRUE the support for PWM1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_PWM_USE_TIMA_12) || defined(__DOXYGEN__)
#define HC32_PWM_USE_TIMA_12                  FALSE
#endif
/** @} */

/* Checks on allocation of TIMx units.*/
#if HC32_PWM_USE_TIMA_1
#if defined(HC32_TIMA_1_IS_USED)
#error "PWMD9 requires TIMA_1 but the timer is already used"
#else
#define HC32_TIMA_1_IS_USED
#endif
#endif

#if HC32_PWM_USE_TIMA_2
#if defined(HC32_TIMA_2_IS_USED)
#error "PWMD10 requires TIMA_2 but the timer is already used"
#else
#define HC32_TIMA_2_IS_USED
#endif
#endif

#if HC32_PWM_USE_TIMA_3
#if defined(HC32_TIMA_3_IS_USED)
#error "PWMD11 requires TIMA_3 but the timer is already used"
#else
#define HC32_TIMA_3_IS_USED
#endif
#endif

#if HC32_PWM_USE_TIMA_4
#if defined(HC32_TIMA_4_IS_USED)
#error "PWMD12 requires TIMA_4 but the timer is already used"
#else
#define HC32_TIMA_4_IS_USED
#endif
#endif

#if HC32_PWM_USE_TIMA_5
#if defined(HC32_TIMA_5_IS_USED)
#error "PWMD13 requires TIMA_5 but the timer is already used"
#else
#define HC32_TIMA_5_IS_USED
#endif
#endif

#if HC32_PWM_USE_TIMA_6
#if defined(HC32_TIMA_6_IS_USED)
#error "PWMD14 requires TIMA_6 but the timer is already used"
#else
#define HC32_TIMA_6_IS_USED
#endif
#endif

#if HC32_PWM_USE_TIMA_7
#if defined(HC32_TIMA_7_IS_USED)
#error "PWMD15 requires TIMA_7 but the timer is already used"
#else
#define HC32_TIMA_7_IS_USED
#endif
#endif

#if HC32_PWM_USE_TIMA_8
#if defined(HC32_TIMA_8_IS_USED)
#error "PWMD16 requires TIMA_8 but the timer is already used"
#else
#define HC32_TIMA_81_IS_USED
#endif
#endif

#if HC32_PWM_USE_TIMA_9
#if defined(HC32_TIMA_9_IS_USED)
#error "PWMD17 requires TIMA_9 but the timer is already used"
#else
#define HC32_TIMA_9_IS_USED
#endif
#endif

#if HC32_PWM_USE_TIMA_10
#if defined(HC32_TIMA_10_IS_USED)
#error "PWMD18 requires TIMA_10 but the timer is already used"
#else
#define HC32_TIMA_10_IS_USED
#endif
#endif

#if HC32_PWM_USE_TIMA_11
#if defined(HC32_TIMA_11_IS_USED)
#error "PWMD19 requires TIMA_11 but the timer is already used"
#else
#define HC32_TIMA_11_IS_USED
#endif
#endif

#if HC32_PWM_USE_TIMA_12
#if defined(HC32_TIMA_12_IS_USED)
#error "PWMD20 requires TIMA_12 but the timer is already used"
#else
#define HC32_TIMA_12_IS_USED
#endif
#endif

/*===========================================================================*/
/* Configuration checks.                                                     */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of a PWM mode.
 */
typedef uint32_t pwmmode_t;

/**
 * @brief   Type of a PWM channel.
 */
typedef uint8_t pwmchannel_t;

/**
 * @brief   Type of a channels mask.
 */
typedef uint32_t pwmchnmsk_t;

/**
 * @brief   Type of a PWM counter.
 */
typedef uint32_t pwmcnt_t;

/**
 * @brief   Type of a PWM driver channel configuration structure.
 */
typedef struct {
  /**
   * @brief Channel active logic level.
   */
  pwmmode_t                 mode;
  /**
   * @brief Channel callback pointer.
   * @note  This callback is invoked on the channel compare event. If set to
   *        @p NULL then the callback is disabled.
   */
  pwmcallback_t             callback;
  /* End of the mandatory fields.*/
} PWMChannelConfig;

/**
 * @brief   Type of a PWM driver configuration structure.
 */
typedef struct {
  /**
   * @brief   Timer clock in Hz.
   * @note    The low level can use assertions in order to catch invalid
   *          frequency specifications.
   */
  uint32_t                  frequency;
  /**
   * @brief   PWM period in ticks.
   * @note    The low level can use assertions in order to catch invalid
   *          period specifications.
   */
  pwmcnt_t                  period;
  /**
   * @brief Periodic callback pointer.
   * @note  This callback is invoked on PWM counter reset. If set to
   *        @p NULL then the callback is disabled.
   */
  pwmcallback_t             callback;
  /**
   * @brief Channels configurations.
   */
  PWMChannelConfig          channels[PWM_CHANNELS];
  /* End of the mandatory fields.*/
} PWMConfig;

/**
 * @brief   Structure representing a PWM driver.
 */
struct PWMDriver {
  /**
   * @brief Driver state.
   */
  pwmstate_t                state;
  /**
   * @brief Current driver configuration data.
   */
  const PWMConfig           *config;
  /**
   * @brief   Current PWM period in ticks.
   */
  pwmcnt_t                  period;
  /**
   * @brief   Mask of the enabled channels.
   */
  pwmchnmsk_t               enabled;
  /**
   * @brief   Number of channels in this instance.
   */
  pwmchannel_t              channels;
#if defined(PWM_DRIVER_EXT_FIELDS)
  PWM_DRIVER_EXT_FIELDS
#endif

  M4_TMRA_TypeDef               *tima;
  uint32_t 						TMR_FRE;
  /* End of the mandatory fields.*/
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/
static inline void pwm_change_period(PWMDriver *pwmp, pwmcnt_t period){

	 pwmp->period = (period)*(float)(pwmp->TMR_FRE /(float)(pwmp->config->frequency));
	/*Set the comparison reference value*/
	WRITE_REG32(pwmp->tima->PERAR, pwmp->period);
}
/**
 * @brief   Changes the period the PWM peripheral.
 * @details This function changes the period of a PWM unit that has already
 *          been activated using @p pwmStart().
 * @pre     The PWM unit must have been activated using @p pwmStart().
 * @post    The PWM unit period is changed to the new value.
 * @note    The function has effect at the next cycle start.
 * @note    If a period is specified that is shorter than the pulse width
 *          programmed in one of the channels then the behavior is not
 *          guaranteed.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] period    new cycle time in ticks
 *
 * @notapi
 */
#define pwm_lld_change_period(pwmp, period)  pwm_change_period(pwmp, period);

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/
#if (HC32_PWM_USE_TIMA_1 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD9;
#endif

#if (HC32_PWM_USE_TIMA_2 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD10;
#endif

#if (HC32_PWM_USE_TIMA_3 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD11;
#endif

#if (HC32_PWM_USE_TIMA_4 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD12;
#endif

#if (HC32_PWM_USE_TIMA_5 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD13;
#endif

#if (HC32_PWM_USE_TIMA_6 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD14;
#endif

#if (HC32_PWM_USE_TIMA_7 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD15;
#endif

#if (HC32_PWM_USE_TIMA_8 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD16;
#endif

#if (HC32_PWM_USE_TIMA_9 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD17;
#endif

#if (HC32_PWM_USE_TIMA_10 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD18;
#endif

#if (HC32_PWM_USE_TIMA_11 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD19;
#endif

#if (HC32_PWM_USE_TIMA_12 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD20;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void pwm_lld_init(void);
  void pwm_lld_start(PWMDriver *pwmp);
  void pwm_lld_stop(PWMDriver *pwmp);
  void pwm_lld_enable_channel(PWMDriver *pwmp,
                              pwmchannel_t channel,
                              pwmcnt_t width);
  void pwm_lld_disable_channel(PWMDriver *pwmp, pwmchannel_t channel);
  void pwm_lld_enable_periodic_notification(PWMDriver *pwmp);
  void pwm_lld_disable_periodic_notification(PWMDriver *pwmp);
  void pwm_lld_enable_channel_notification(PWMDriver *pwmp,
                                           pwmchannel_t channel);
  void pwm_lld_disable_channel_notification(PWMDriver *pwmp,
                                            pwmchannel_t channel);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_PWM == TRUE */

#endif /* HAL_PWM_LLD_H */

/** @} */
