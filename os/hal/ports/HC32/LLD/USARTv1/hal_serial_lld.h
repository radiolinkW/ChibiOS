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
 * @file    hal_serial_lld.h
 * @brief   PLATFORM serial subsystem low level driver header.
 *
 * @addtogroup SERIAL
 * @{
 */

#ifndef HAL_SERIAL_LLD_H
#define HAL_SERIAL_LLD_H

#include "hc32_uart.h"

#if (HAL_USE_SERIAL == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    HC32 configuration options
 * @{
 */
/**
 * @brief   USART1 driver enable switch.
 * @details If set to @p TRUE the support for USART1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_SERIAL_USE_USART1) || defined(__DOXYGEN__)
#define HC32_SERIAL_USE_USART1             FALSE
#endif
/** @} */

/**
 * @brief   USART2 driver enable switch.
 * @details If set to @p TRUE the support for USART2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_SERIAL_USE_USART2) || defined(__DOXYGEN__)
#define HC32_SERIAL_USE_USART2             FALSE
#endif
/** @} */

/**
 * @brief   USART3 driver enable switch.
 * @details If set to @p TRUE the support for USART3 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_SERIAL_USE_USART3) || defined(__DOXYGEN__)
#define HC32_SERIAL_USE_USART3             FALSE
#endif
/** @} */

/**
 * @brief   USART4 driver enable switch.
 * @details If set to @p TRUE the support for USART4 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_SERIAL_USE_USART4) || defined(__DOXYGEN__)
#define HC32_SERIAL_USE_USART4             FALSE
#endif
/** @} */

/**
 * @brief   USART5 driver enable switch.
 * @details If set to @p TRUE the support for USART5 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_SERIAL_USE_USART5) || defined(__DOXYGEN__)
#define HC32_SERIAL_USE_USART5             FALSE
#endif
/** @} */

/**
 * @brief   USART6 driver enable switch.
 * @details If set to @p TRUE the support for USART6 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_SERIAL_USE_USART6) || defined(__DOXYGEN__)
#define HC32_SERIAL_USE_USART6             FALSE
#endif
/** @} */

/**
 * @brief   USART7 driver enable switch.
 * @details If set to @p TRUE the support for USART7 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_SERIAL_USE_USART7) || defined(__DOXYGEN__)
#define HC32_SERIAL_USE_USART7             FALSE
#endif
/** @} */

/**
 * @brief   USART8 driver enable switch.
 * @details If set to @p TRUE the support for USART8 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_SERIAL_USE_USART8) || defined(__DOXYGEN__)
#define HC32_SERIAL_USE_USART8             FALSE
#endif
/** @} */

/**
 * @brief   USART9 driver enable switch.
 * @details If set to @p TRUE the support for USART9 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_SERIAL_USE_USART9) || defined(__DOXYGEN__)
#define HC32_SERIAL_USE_USART9             FALSE
#endif
/** @} */

/**
 * @brief   USART10 driver enable switch.
 * @details If set to @p TRUE the support for USART10 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_SERIAL_USE_USART10) || defined(__DOXYGEN__)
#define HC32_SERIAL_USE_USART10             FALSE
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/
#if HC32_SERIAL_USE_USART1 && !HC32_HAS_USART1
#error "USART1 not present in the selected device"
#endif

#if HC32_SERIAL_USE_USART2 && !HC32_HAS_USART2
#error "USART2 not present in the selected device"
#endif

#if HC32_SERIAL_USE_USART3 && !HC32_HAS_USART3
#error "USART3 not present in the selected device"
#endif

#if HC32_SERIAL_USE_USART4 && !HC32_HAS_USART4
#error "USART4 not present in the selected device"
#endif

#if HC32_SERIAL_USE_USART5 && !HC32_HAS_USART5
#error "USART5 not present in the selected device"
#endif

#if HC32_SERIAL_USE_USART6 && !HC32_HAS_USART6
#error "USART6 not present in the selected device"
#endif

#if HC32_SERIAL_USE_USART7 && !HC32_HAS_USART7
#error "USART7 not present in the selected device"
#endif

#if HC32_SERIAL_USE_USART8 && !HC32_HAS_USART8
#error "USART8 not present in the selected device"
#endif

#if HC32_SERIAL_USE_USART9 && !HC32_HAS_USART9
#error "USART9 not present in the selected device"
#endif

#if HC32_SERIAL_USE_USART10 && !HC32_HAS_USART10
#error "USART10 not present in the selected device"
#endif

/* Checks on allocation of USARTx units.*/
#if HC32_SERIAL_USE_USART1
#if defined(HC32_USART1_IS_USED)
#error "SD1 requires USART1 but it is already used"
#else
#define HC2_USART1_IS_USED
#endif
#endif

#if HC32_SERIAL_USE_USART2
#if defined(HC32_USART2_IS_USED)
#error "SD1 requires USART2 but it is already used"
#else
#define HC2_USART2_IS_USED
#endif
#endif

#if HC32_SERIAL_USE_USART3
#if defined(HC32_USART3_IS_USED)
#error "SD1 requires USART3 but it is already used"
#else
#define HC2_USART3_IS_USED
#endif
#endif

#if HC32_SERIAL_USE_USART4
#if defined(HC32_USART4_IS_USED)
#error "SD1 requires USART4 but it is already used"
#else
#define HC2_USART4_IS_USED
#endif
#endif

#if HC32_SERIAL_USE_USART5
#if defined(HC32_USART5_IS_USED)
#error "SD1 requires USART5 but it is already used"
#else
#define HC2_USART5_IS_USED
#endif
#endif

#if HC32_SERIAL_USE_USART6
#if defined(HC32_USART6_IS_USED)
#error "SD1 requires USART6 but it is already used"
#else
#define HC2_USART6_IS_USED
#endif
#endif

#if HC32_SERIAL_USE_USART7
#if defined(HC32_USART7_IS_USED)
#error "SD1 requires USART7 but it is already used"
#else
#define HC2_USART7_IS_USED
#endif
#endif

#if HC32_SERIAL_USE_USART8
#if defined(HC32_USART8_IS_USED)
#error "SD1 requires USART8 but it is already used"
#else
#define HC2_USART8_IS_USED
#endif
#endif

#if HC32_SERIAL_USE_USART9
#if defined(HC32_USART9_IS_USED)
#error "SD1 requires USART9 but it is already used"
#else
#define HC2_USART9_IS_USED
#endif
#endif

#if HC32_SERIAL_USE_USART10
#if defined(HC32_USART10_IS_USED)
#error "SD1 requires USART10 but it is already used"
#else
#define HC2_USART10_IS_USED
#endif
#endif
/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/
typedef void (*uartirq_t)(void* sd);

#define _serial_irq_code(sd) {                                      \
  if ((sd)->config->irq_cb != NULL)                                 \
    (sd)->config->irq_cb((sd)->config->ctx);                        \
}

/**
 * @brief   PLATFORM Serial Driver configuration structure.
 * @details An instance of this structure must be passed to @p sdStart()
 *          in order to configure and start a serial driver operations.
 * @note    This structure content is architecture dependent, each driver
 *          implementation defines its own version and the custom static
 *          initializers.
 */
typedef struct {
  /**
   * @brief Bit rate.
   */
  uint32_t                  speed;
  /* End of the mandatory fields.*/
  /**
   * @brief Initialization value for the CR1 register.
   */
  uint16_t                  cr1;
  /**
   * @brief Initialization value for the CR2 register.
   */
  uint16_t                  cr2;
  /**
   * @brief Initialization value for the CR3 register.
   */
  uint16_t                  cr3;

  /**
   * @brief Set callback from irq
   */
  uartirq_t                 irq_cb;

  void*                     ctx;
} SerialConfig;

/**
 * @brief   @p SerialDriver specific data.
 */
#define _serial_driver_data                                                 \
  _base_asynchronous_channel_data                                           \
  /* Driver state.*/                                                        \
  sdstate_t                 state;                                          \
  /* Input queue.*/                                                         \
  input_queue_t             iqueue;                                         \
  /* Output queue.*/                                                        \
  output_queue_t            oqueue;                                         \
  /* Input circular buffer.*/                                               \
  uint8_t                   ib[SERIAL_BUFFERS_SIZE];                        \
  /* Output circular buffer.*/                                              \
  uint8_t                   ob[SERIAL_BUFFERS_SIZE];                        \
  /* End of the mandatory fields.*/                                         \
  /* Pointer to the USART registers block.*/                                \
  M4_USART_TypeDef             *usart;                                      \
  /* Mask to be applied on received frames.*/                               \
  uint8_t                   rxmask;                                         \
  IRQn_Type                  EI_NUM;                                         \
  IRQn_Type                  RI_NUM;                                         \
  IRQn_Type                  TI_NUM;                                         \
  IRQn_Type                  TCI_NUM;                                         \
  en_int_src_t              USART_EI;                                       \
  en_int_src_t              USART_RI;                                       \
  en_int_src_t              USART_TI;                                       \
  en_int_src_t              USART_TCI;                                      \
  const SerialConfig              *config;                                   \

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if (HC32_SERIAL_USE_USART1 == TRUE) && !defined(__DOXYGEN__)
extern SerialDriver SD1;
#endif

#if (HC32_SERIAL_USE_USART2 == TRUE) && !defined(__DOXYGEN__)
extern SerialDriver SD2;
#endif

#if (HC32_SERIAL_USE_USART3 == TRUE) && !defined(__DOXYGEN__)
extern SerialDriver SD3;
#endif

#if (HC32_SERIAL_USE_USART4 == TRUE) && !defined(__DOXYGEN__)
extern SerialDriver SD4;
#endif

#if (HC32_SERIAL_USE_USART5 == TRUE) && !defined(__DOXYGEN__)
extern SerialDriver SD5;
#endif

#if (HC32_SERIAL_USE_USART6 == TRUE) && !defined(__DOXYGEN__)
extern SerialDriver SD6;
#endif

#if (HC32_SERIAL_USE_USART7 == TRUE) && !defined(__DOXYGEN__)
extern SerialDriver SD7;
#endif

#if (HC32_SERIAL_USE_USART8 == TRUE) && !defined(__DOXYGEN__)
extern SerialDriver SD8;
#endif

#if (HC32_SERIAL_USE_USART9 == TRUE) && !defined(__DOXYGEN__)
extern SerialDriver SD9;
#endif

#if (HC32_SERIAL_USE_USART10 == TRUE) && !defined(__DOXYGEN__)
extern SerialDriver SD10;
#endif


#ifdef __cplusplus
extern "C" {
#endif
  void sd_lld_init(void);
  void sd_lld_start(SerialDriver *sdp, const SerialConfig *config);
  void sd_lld_stop(SerialDriver *sdp);
  void sd_lld_serve_interrupt(SerialDriver *sdp);
  void sd_lld_riserve_interrupt(SerialDriver *sdp);
  void sd_lld_eiserve_interrupt(SerialDriver *sdp);
  void sd_lld_tiserve_interrupt(SerialDriver *sdp);
  void sd_lld_tciserve_interrupt(SerialDriver *sdp);
  void sd_lld_rtoiserve_interrupt(SerialDriver *sdp);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_SERIAL == TRUE */

#endif /* HAL_SERIAL_LLD_H */

/** @} */
