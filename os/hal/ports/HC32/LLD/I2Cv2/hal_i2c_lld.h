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
 * @file    hal_i2c_lld.h
 * @brief   HC32 I2C subsystem low level driver header.
 *
 * @addtogroup I2C
 * @{
 */

#ifndef HAL_I2C_LLD_H
#define HAL_I2C_LLD_H

#ifndef HC32_DMA_REQUIRED
#define HC32_DMA_REQUIRED
#endif


#if (HAL_USE_I2C == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/
/** @defgroup I2C_Digital_Filter_mode I2C digital filter mode
  * @{
  */
#define I2C_DIG_FILTMODE_1CYCLE              (0UL << I2C_FLTR_DNF_POS)
#define I2C_DIG_FILTMODE_2CYCLE              (1UL << I2C_FLTR_DNF_POS)
#define I2C_DIG_FILTMODE_3CYCLE              (2UL << I2C_FLTR_DNF_POS)
#define I2C_DIG_FILTMODE_4CYCLE              (3UL << I2C_FLTR_DNF_POS)
/**
 * @}
 */
/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    HC32 configuration options
 * @{
 */
/**
 * @brief   I2C1 driver enable switch.
 * @details If set to @p TRUE the support for I2C1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_I2C_USE_I2C1) || defined(__DOXYGEN__)
#define HC32_I2C_USE_I2C1                  FALSE
#endif

/**
 * @brief   I2C2 driver enable switch.
 * @details If set to @p TRUE the support for I2C2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_I2C_USE_I2C2) || defined(__DOXYGEN__)
#define HC32_I2C_USE_I2C2                  FALSE
#endif

/**
 * @brief   I2C3 driver enable switch.
 * @details If set to @p TRUE the support for I2C3 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_I2C_USE_I2C3) || defined(__DOXYGEN__)
#define HC32_I2C_USE_I2C3                  FALSE
#endif

/**
 * @brief   I2C4 driver enable switch.
 * @details If set to @p TRUE the support for I2C4 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_I2C_USE_I2C4) || defined(__DOXYGEN__)
#define HC32_I2C_USE_I2C4                  FALSE
#endif

/**
 * @brief   I2C5 driver enable switch.
 * @details If set to @p TRUE the support for I2C5 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_I2C_USE_I2C5) || defined(__DOXYGEN__)
#define HC32_I2C_USE_I2C5                  FALSE
#endif

/**
 * @brief   I2C6 driver enable switch.
 * @details If set to @p TRUE the support for I2C6 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_I2C_USE_I2C6) || defined(__DOXYGEN__)
#define HC32_I2C_USE_I2C6                  FALSE
#endif
/** @} */



/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/
#if HC32_I2C_USE_I2C1 && !HC32_HAS_I2C1
#error "I2C1 not present in the selected device"
#endif

#if HC32_I2C_USE_I2C2 && !HC32_HAS_I2C2
#error "I2C2 not present in the selected device"
#endif

#if HC32_I2C_USE_I2C3 && !HC32_HAS_I2C3
#error "I2C3 not present in the selected device"
#endif

#if HC32_I2C_USE_I2C4 && !HC32_HAS_I2C4
#error "I2C4 not present in the selected device"
#endif

#if HC32_I2C_USE_I2C5 && !HC32_HAS_I2C5
#error "I2C3 not present in the selected device"
#endif

#if HC32_I2C_USE_I2C6 && !HC32_HAS_I2C6
#error "I2C4 not present in the selected device"
#endif
/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

typedef enum {
  OPMODE_I2C = 0,
  OPMODE_SMBUS = 2,
} i2copmode_t;

/**
 * @brief   Supported duty cycle modes for the I2C bus.
 */
typedef enum {
  FILTMODE_1CYCLE = 1,
  FILTMODE_2CYCLE = 2,
  FILTMODE_3CYCLE = 3,
  FILTMODE_4CYCLE = 4,
} i2cdutycycle_t;
/**
 * @brief   Type representing an I2C address.
 */
typedef uint16_t i2caddr_t;

/**
 * @brief   Type of I2C Driver condition flags.
 */
typedef uint32_t i2cflags_t;

/**
 * @brief   Type of I2C driver configuration structure.
 * @note    Implementations may extend this structure to contain more,
 *          architecture dependent, fields.
 */
typedef struct {
  /* End of the mandatory fields.*/
  i2copmode_t     op_mode;       /**< @brief Specifies the I2C mode.        */
  uint32_t        clock_speed;   /**< @brief Specifies the clock frequency.
                                        @note Must be set to a value lower
                                        than 400kHz.                          */
  i2cdutycycle_t  duty_cycle;    /**< @brief Specifies the I2C fast mode
                                      duty cycle.                           */
} I2CConfig;

/**
 * @brief   Type of a structure representing an I2C driver.
 */
typedef struct I2CDriver I2CDriver;

/**
 * @brief   Structure representing an I2C driver.
 */
struct I2CDriver {
  /**
   * @brief   Driver state.
   */
  i2cstate_t                state;
  /**
   * @brief   Current configuration data.
   */
  const I2CConfig           *config;
  /**
   * @brief   Error flags.
   */
  i2cflags_t                errors;
#if (I2C_USE_MUTUAL_EXCLUSION == TRUE) || defined(__DOXYGEN__)
  mutex_t                   mutex;
#endif
#if defined(I2C_DRIVER_EXT_FIELDS)
  I2C_DRIVER_EXT_FIELDS
#endif
  thread_reference_t        thread;

  i2caddr_t                 addr;

  uint32_t                  txinum;
  uint32_t                  rxinum;
  uint32_t                  teinum;
  uint32_t                  eeinum;

  en_int_src_t              txisrc;
  en_int_src_t              rxisrc;
  en_int_src_t              teisrc;
  en_int_src_t              eeisrc;

  uint8_t*                  txbuf;
  uint8_t*                  rxbuf;

  uint32_t                  tx_size;
  uint32_t                  rx_size;

  uint32_t                  tx_dataindex;
  uint32_t                  rx_dataindex;

  uint32_t                  irq_priority;

  /**
     true when we are in an I2C transaction
   */
  bool                      rx_transfer;
  bool                      tx_transfer;

  M4_I2C_TypeDef            *i2c;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Get errors from I2C driver.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 *
 * @notapi
 */
#define i2c_lld_get_errors(i2cp) ((i2cp)->errors)

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if (HC32_I2C_USE_I2C1 == TRUE) && !defined(__DOXYGEN__)
extern I2CDriver I2CD1;
#endif

#if (HC32_I2C_USE_I2C2 == TRUE) && !defined(__DOXYGEN__)
extern I2CDriver I2CD2;
#endif

#if (HC32_I2C_USE_I2C3 == TRUE) && !defined(__DOXYGEN__)
extern I2CDriver I2CD3;
#endif

#if (HC32_I2C_USE_I2C4 == TRUE) && !defined(__DOXYGEN__)
extern I2CDriver I2CD4;
#endif

#if (HC32_I2C_USE_I2C5 == TRUE) && !defined(__DOXYGEN__)
extern I2CDriver I2CD5;
#endif

#if (HC32_I2C_USE_I2C6 == TRUE) && !defined(__DOXYGEN__)
extern I2CDriver I2CD6;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void i2c_lld_init(void);
  void i2c_lld_start(I2CDriver *i2cp);
  void i2c_lld_soft_stop(I2CDriver *i2cp);
  void i2c_lld_stop(I2CDriver *i2cp);
  msg_t i2c_lld_master_transmit_timeout(I2CDriver *i2cp, i2caddr_t addr,
                                        const uint8_t *txbuf, size_t txbytes,
                                        uint8_t *rxbuf, size_t rxbytes,
                                        sysinterval_t timeout);
  msg_t i2c_lld_master_receive_timeout(I2CDriver *i2cp, i2caddr_t addr,
                                       uint8_t *rxbuf, size_t rxbytes,
                                       sysinterval_t timeout);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_I2C == TRUE */

#endif /* HAL_I2C_LLD_H */

/** @} */
