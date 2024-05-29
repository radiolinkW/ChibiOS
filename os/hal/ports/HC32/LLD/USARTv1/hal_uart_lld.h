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
 * @file    hal_uart_lld.h
 * @brief   HC32 UART subsystem low level driver header.
 *
 * @addtogroup UART
 * @{
 */

#ifndef HAL_UART_LLD_H
#define HAL_UART_LLD_H

#include "hc32_uart.h"

#ifndef HC32_DMA_REQUIRED
#define HC32_DMA_REQUIRED
#endif


#if (HAL_USE_UART == TRUE) || defined(__DOXYGEN__)

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
 * @brief   UART driver enable switch.
 * @details If set to @p TRUE the support for UART1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_UART_USE_USART1) || defined(__DOXYGEN__)
#define HC32_UART_USE_USART1             FALSE
#endif

/**
 * @brief   UART driver enable switch.
 * @details If set to @p TRUE the support for UART2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_UART_USE_USART2) || defined(__DOXYGEN__)
#define HC32_UART_USE_USART2             FALSE
#endif

/**
 * @brief   UART driver enable switch.
 * @details If set to @p TRUE the support for UART3 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_UART_USE_USART3) || defined(__DOXYGEN__)
#define HC32_UART_USE_USART3             FALSE
#endif

/**
 * @brief   UART driver enable switch.
 * @details If set to @p TRUE the support for UART4 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_UART_USE_USART4) || defined(__DOXYGEN__)
#define HC32_UART_USE_USART4             FALSE
#endif

/**
 * @brief   UART driver enable switch.
 * @details If set to @p TRUE the support for UART5 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_UART_USE_USART5) || defined(__DOXYGEN__)
#define HC32_UART_USE_USART5             FALSE
#endif

/**
 * @brief   UART driver enable switch.
 * @details If set to @p TRUE the support for UART6 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_UART_USE_USART6) || defined(__DOXYGEN__)
#define HC32_UART_USE_USART6             FALSE
#endif

/**
 * @brief   UART driver enable switch.
 * @details If set to @p TRUE the support for UART7 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_UART_USE_USART7) || defined(__DOXYGEN__)
#define HC32_UART_USE_USART7             FALSE
#endif

/**
 * @brief   UART driver enable switch.
 * @details If set to @p TRUE the support for UART8 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_UART_USE_USART8) || defined(__DOXYGEN__)
#define HC32_UART_USE_USART8             FALSE
#endif

/**
 * @brief   UART driver enable switch.
 * @details If set to @p TRUE the support for UART9 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_UART_USE_USART9) || defined(__DOXYGEN__)
#define HC32_UART_USE_USART9            FALSE
#endif

/**
 * @brief   UART driver enable switch.
 * @details If set to @p TRUE the support for UART10 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(HC32_UART_USE_USART10) || defined(__DOXYGEN__)
#define HC32_UART_USE_USART10             FALSE
#endif

/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/
/* Checks on allocation of USARTx units.*/
#if HC32_UART_USE_USART1
#if defined(HC32_USART1_IS_USED)
#error "UARTD1 requires USART1 but it is already used"
#else
#define HC32_USART1_IS_USED
#endif
#endif

#if HC32_UART_USE_USART2
#if defined(HC32_USART2_IS_USED)
#error "UARTD1 requires USART2 but it is already used"
#else
#define HC32_USART2_IS_USED
#endif
#endif

#if HC32_UART_USE_USART3
#if defined(HC32_USART3_IS_USED)
#error "UARTD1 requires USART3 but it is already used"
#else
#define HC32_USART3_IS_USED
#endif
#endif

#if HC32_UART_USE_USART4
#if defined(HC32_USART4_IS_USED)
#error "UARTD1 requires USART4 but it is already used"
#else
#define HC32_USART4_IS_USED
#endif
#endif

#if HC32_UART_USE_USART5
#if defined(HC32_USART5_IS_USED)
#error "UARTD1 requires USART5 but it is already used"
#else
#define HC32_USART5_IS_USED
#endif
#endif

#if HC32_UART_USE_USART6
#if defined(HC32_USART6_IS_USED)
#error "UARTD1 requires USART6 but it is already used"
#else
#define HC32_USART6_IS_USED
#endif
#endif

#if HC32_UART_USE_USART7
#if defined(HC32_USART7_IS_USED)
#error "UARTD1 requires USART7 but it is already used"
#else
#define HC32_USART7_IS_USED
#endif
#endif

#if HC32_UART_USE_USART8
#if defined(HC32_USART8_IS_USED)
#error "UARTD1 requires USART8 but it is already used"
#else
#define HC32_USART8_IS_USED
#endif
#endif

#if HC32_UART_USE_USART9
#if defined(HC32_USART9_IS_USED)
#error "UARTD1 requires USART9 but it is already used"
#else
#define HC32_USART9_IS_USED
#endif
#endif

#if HC32_UART_USE_USART10
#if defined(HC32_USART10_IS_USED)
#error "UARTD1 requires USART10 but it is already used"
#else
#define HC32_USART10_IS_USED
#endif
#endif
/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   UART driver condition flags type.
 */
typedef uint32_t uartflags_t;

/**
 * @brief   Type of structure representing an UART driver.
 */
typedef struct UARTDriver UARTDriver;

/**
 * @brief   Generic UART notification callback type.
 *
 * @param[in] uartp     pointer to the @p UARTDriver object
 */
typedef void (*uartcb_t)(UARTDriver *uartp);

/**
 * @brief   Character received UART notification callback type.
 *
 * @param[in] uartp     pointer to the @p UARTDriver object triggering the
 *                      callback
 * @param[in] c         received character
 */
typedef void (*uartccb_t)(UARTDriver *uartp, uint16_t c);

/**
 * @brief   Receive error UART notification callback type.
 *
 * @param[in] uartp     pointer to the @p UARTDriver object triggering the
 *                      callback
 * @param[in] e         receive error mask
 */
typedef void (*uartecb_t)(UARTDriver *uartp, uartflags_t e);

/**
 * @brief   Driver configuration structure.
 * @note    Implementations may extend this structure to contain more,
 *          architecture dependent, fields.
 */
typedef struct {
  /**
   * @brief End of transmission buffer callback.
   */
  uartcb_t                  txend1_cb;
  /**
   * @brief Physical end of transmission callback.
   */
  uartcb_t                  txend2_cb;
  /**
   * @brief Receive buffer filled callback.
   */
  uartcb_t                  rxend_cb;
  /**
   * @brief Character received while out if the @p UART_RECEIVE state.
   */
  uartccb_t                 rxchar_cb;
  /**
   * @brief Receive error callback.
   */
  uartecb_t                 rxerr_cb;
//  /**
//   * @brief Receiver timeout callback..
//   */
//  uartcb_t                 timeout_cb;
  /**
   * @brief Bit rate.
   */
  uint32_t                  speed;
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

} UARTConfig;

/**
 * @brief   Structure representing an UART driver.
 * @note    Implementations may extend this structure to contain more,
 *          architecture dependent, fields.
 */
struct UARTDriver {
  /**
   * @brief Driver state.
   */
  uartstate_t               state;
  /**
   * @brief Transmitter state.
   */
  uarttxstate_t             txstate;
  /**
   * @brief Receiver state.
   */
  uartrxstate_t             rxstate;
  /**
   * @brief Current configuration data.
   */
  const UARTConfig          *config;
#if (UART_USE_WAIT == TRUE) || defined(__DOXYGEN__)
  /**
   * @brief   Synchronization flag for transmit operations.
   */
  bool                      early;
  /**
   * @brief   Waiting thread on RX.
   */
  thread_reference_t        threadrx;
  /**
   * @brief   Waiting thread on TX.
   */
  thread_reference_t        threadtx;
#endif /* UART_USE_WAIT */
#if (UART_USE_MUTUAL_EXCLUSION == TRUE) || defined(__DOXYGEN__)
  /**
   * @brief   Mutex protecting the peripheral.
   */
  mutex_t                   mutex;
#endif /* UART_USE_MUTUAL_EXCLUSION */
#if defined(UART_DRIVER_EXT_FIELDS)
  UART_DRIVER_EXT_FIELDS
#endif
  /* End of the mandatory fields.*/
  /**
   * @brief Pointer to the USART registers block.
   */
  M4_USART_TypeDef             *usart;

  en_event_src_t                rxsrc;

  en_event_src_t                txsrc;

  /**
   * @brief Receive DMA channel.
   */
  const hc32_dma_channel_t  *dmarx;
  /**
   * @brief Transmit DMA channel.
   */
  const hc32_dma_channel_t  *dmatx;
  /**
   * @brief Default receive buffer while into @p UART_RX_IDLE state.
   */
  volatile uint16_t         rxbuf;

  /* End of the mandatory fields.*/
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if (HC32_UART_USE_USART1 == TRUE) && !defined(__DOXYGEN__)
extern UARTDriver UARTD1;
#endif

#if (HC32_UART_USE_USART2 == TRUE) && !defined(__DOXYGEN__)
extern UARTDriver UARTD2;
#endif

#if (HC32_UART_USE_USART3 == TRUE) && !defined(__DOXYGEN__)
extern UARTDriver UARTD3;
#endif

#if (HC32_UART_USE_USART4 == TRUE) && !defined(__DOXYGEN__)
extern UARTDriver UARTD4;
#endif

#if (HC32_UART_USE_USART5 == TRUE) && !defined(__DOXYGEN__)
extern UARTDriver UARTD5;
#endif

#if (HC32_UART_USE_USART6 == TRUE) && !defined(__DOXYGEN__)
extern UARTDriver UARTD6;
#endif

#if (HC32_UART_USE_USART7 == TRUE) && !defined(__DOXYGEN__)
extern UARTDriver UARTD7;
#endif

#if (HC32_UART_USE_USART8 == TRUE) && !defined(__DOXYGEN__)
extern UARTDriver UARTD9;
#endif

#if (HC32_UART_USE_USART9 == TRUE) && !defined(__DOXYGEN__)
extern UARTDriver UARTD9;
#endif

#if (HC32_UART_USE_USART10 == TRUE) && !defined(__DOXYGEN__)
extern UARTDriver UARTD10;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void uart_lld_init(void);
  void uart_lld_start(UARTDriver *uartp);
  void uart_lld_stop(UARTDriver *uartp);
  void uart_lld_start_send(UARTDriver *uartp, size_t n, const void *txbuf);
  size_t uart_lld_stop_send(UARTDriver *uartp);
  void uart_lld_start_receive(UARTDriver *uartp, size_t n, void *rxbuf);
  size_t uart_lld_stop_receive(UARTDriver *uartp);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_UART == TRUE */

#endif /* HAL_UART_LLD_H */

/** @} */
