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
 * @file    hal_pal_lld.h
 * @brief   PLATFORM PAL subsystem low level driver header.
 *
 * @addtogroup PAL
 * @{
 */

#ifndef HAL_PAL_LLD_H
#define HAL_PAL_LLD_H

#include "hc32_gpio.h"

#if (HAL_USE_PAL == TRUE) || defined(__DOXYGEN__)


/*===========================================================================*/
/* Unsupported modes and specific modes                                      */
/*===========================================================================*/

/* Specifies palInit() without parameter, required until all platforms will
   be updated to the new style.*/
#define PAL_NEW_INIT

#undef PAL_MODE_RESET
#undef PAL_MODE_UNCONNECTED
#undef PAL_MODE_INPUT
#undef PAL_MODE_INPUT_PULLUP
#undef PAL_MODE_INPUT_PULLDOWN
#undef PAL_MODE_INPUT_ANALOG
#undef PAL_MODE_OUTPUT_PUSHPULL
#undef PAL_MODE_OUTPUT_OPENDRAIN

#undef PAL_EVENT_MODE_EDGES_MASK
#undef PAL_EVENT_MODE_DISABLED
#undef PAL_EVENT_MODE_RISING_EDGE
#undef PAL_EVENT_MODE_FALLING_EDGE
#undef PAL_EVENT_MODE_BOTH_EDGES
/**
 * @name    HC32-specific I/O mode flags
 * @{
 */
#define PAL_HC32_PCR_MASK             (15U << 0U)
#define PAL_HC32_PCR_OUTPUTUP         (GPIO_PCR_POUT)
#define PAL_HC32_PCR_OUTPUTDOWN       (0U)

#define PAL_HC32_PCR_OUTPUTOFF        (0U)
#define PAL_HC32_PCR_OUTPUTON         (GPIO_PCR_POUTE)

#define PAL_HC32_PCR_OUTPUTCMOS       (0U)
#define PAL_HC32_PCR_OUTPUTNMOS       (GPIO_PCR_NOD)

#define PAL_HC32_PCR_LOW              (0U)
#define PAL_HC32_PCR_MEDIUM           (GPIO_PCR_DRV_0)
#define PAL_HC32_PCR_FAST             (GPIO_PCR_DRV_1)

#define PAL_HC32_PCR_PULLUP           (GPIO_PCR_PUU)
#define PAL_HC32_PCR_PULLDOWN         (0U)

#define PAL_HC32_PCR_INPUTUP
#define PAL_HC32_PCR_INPUTDOWN

#define PAL_HC32_PCR_INVEON           (GPIO_PCR_INVE)
#define PAL_HC32_PCR_INVEOFF          (0U)

#define PAL_HC32_PCR_INMODESMT        (0U)
#define PAL_HC32_PCR_INMODECMOS       (GPIO_PCR_CINSEL)

#define PAL_HC32_PCR_INTEON           (GPIO_PCR_INTE)
#define PAL_HC32_PCR_INTEOFF          (0U)

#define PAL_HC32_PCR_LTEON            (GPIO_PCR_LTE)
#define PAL_HC32_PCR_LTEOFF           (0U)

#define PAL_HC32_MODE_ANALOG          (GPIO_PCR_DDIS)
#define PAL_HC32_MODE_DIGIT           (0U)

#define PAL_HC32_ALTERNATE(n)         ((n) << 0U)
/**
 * @name    Standard I/O mode flags
 * @{
 */
/**
 * @brief   Implemented as input.
 */
#define PAL_MODE_RESET                  PAL_HC32_PCR_INMODESMT
/**
 * @brief   Implemented as analog with analog switch disabled and lock.
 */
#define PAL_MODE_UNCONNECTED            (PAL_HC32_MODE_ANALOG |            \
                                               PAL_HC32_PCR_LTEON)
/**
 * @brief   Regular input high-Z pad.
 */
#define PAL_MODE_INPUT                  PAL_HC32_PCR_INMODECMOS
/**
 * @brief   Input pad with weak pull up resistor.
 */
#define PAL_MODE_INPUT_PULLUP           (PAL_HC32_PCR_INMODESMT |           \
                                              PAL_HC32_PCR_PULLUP)
/**
 * @brief   Input pad with weak pull down resistor.
 */
#define PAL_MODE_INPUT_PULLDOWN         (PAL_HC32_PCR_INMODESMT |           \
                                               PAL_HC32_PCR_PULLDOWN)
/**
 * @brief   Analog input mode.
 */
#define PAL_MODE_INPUT_ANALOG           (PAL_HC32_MODE_ANALOG |            \
                                               PAL_HC32_PCR_INMODECMOS)
/**
 * @brief   Push-pull output pad.
 */
#define PAL_MODE_OUTPUT_PUSHPULL        (PAL_HC32_PCR_OUTPUTON |            \
                                               PAL_HC32_PCR_OUTPUTCMOS)
/**
 * @brief   Open-drain output pad.
 */
#define PAL_MODE_OUTPUT_OPENDRAIN       (PAL_HC32_PCR_OUTPUTON |            \
                                               PAL_HC32_PCR_OUTPUTNMOS)

#define PAL_EVENT_MODE_EDGES_MASK   3U  /**< @brief Mask of edges field.    */
#define PAL_EVENT_MODE_DISABLED     3U  /**< @brief Channel disabled.       */
#define PAL_EVENT_MODE_RISING_EDGE  1U  /**< @brief Rising edge callback.   */
#define PAL_EVENT_MODE_FALLING_EDGE 0U  /**< @brief Falling edge callback.  */
#define PAL_EVENT_MODE_BOTH_EDGES   2U  /**< @brief Both edges callback.    */


/**
 * @name    Port related definitions
 * @{
 */
/**
 * @brief   Width, in bits, of an I/O port.
 */
#define PAL_IOPORTS_WIDTH           8U

/**
 * @name    Port pspcr  reset value
 * @{
 */
/**
 * @brief   Width, in bits, of an I/O port.
 */
#define GPIO_PSPCR_RESET_VALUE           0x001f

/**
 * @name    Port pccr reset value
 * @{
 */
/**
 * @brief   Width, in bits, of an I/O port.
 */
#define GPIO_PCCR_RESET_VALUE            0x1000

/**
 * @name    Port pinaer reset value
 * @{
 */
/**
 * @brief   Width, in bits, of an I/O port.
 */
#define GPIO_PINAER_RESET_VALUE           0x0000

/**
 * @brief   Whole port mask.
 * @details This macro specifies all the valid bits into a port.
 */
#define PAL_WHOLE_PORT              ((ioportmask_t)0xFFU)
/** @} */

/**
 * @name    Line handling macros
 * @{
 */
/**
 * @brief   Forms a line identifier.
 * @details A port/pad pair are encoded into an @p ioline_t type. The encoding
 *          of this type is platform-dependent.
 */
#define PAL_LINE(port, pad)                                                 \
  ((ioline_t)(((uint16_t)(port))<<8) | ((uint16_t)(pad)))
/**
 * @brief   Decodes a port identifier from a line identifier.
 */
#define PAL_PORT(line)                                                      \
  ((uint8_t)((((uint16_t)(line)) & 0xFF00U) >> 8))
/**
 * @brief   Decodes a pad identifier from a line identifier.
 */
#define PAL_PAD(line)                                                       \
  ((uint8_t)((uint16_t)(line) & 0x00FFU))
/**
 * @brief   Value identifying an invalid line.
 */
#define PAL_NOLINE                      0U

/** @} */
/**
 * @brief   Generic I/O ports static initializer.
 * @details An instance of this structure must be passed to @p palInit() at
 *          system startup time in order to initialized the digital I/O
 *          subsystem. This represents only the initial setup, specific pads
 *          or whole ports can be reprogrammed at later time.
 * @note    Implementations may extend this structure to contain more,
 *          architecture dependent, fields.
 */
typedef struct {

} PALConfig;


/**
 * @brief   Digital I/O port sized unsigned type.
 */
typedef uint16_t ioportmask_t;

/**
 * @brief   Digital I/O modes.
 */
typedef uint16_t iomode_t;

/**
 * @brief   Type of an I/O line.
 */
typedef uint16_t ioline_t;

/**
<<<<<<< HEAD
=======
 * @brief   Type of an I/O event.
 */
typedef uint32_t ioeventmode_t;

/**
>>>>>>> debug-exit
 * @brief   Port Identifier.
 * @details This type can be a scalar or some kind of pointer, do not make
 *          any assumption about it, use the provided macros when populating
 *          variables of this type.
 */
typedef uint16_t ioportid_t;

/**
 * @brief   Type of an pad identifier.
 */
typedef uint16_t iopadid_t;

/*===========================================================================*/
/* I/O Ports Identifiers.                                                    */
/*===========================================================================*/

/*===========================================================================*/
/* Implementation, some of the following macros could be implemented as      */
/* functions, if so please put them in pal_lld.c.                            */
/*===========================================================================*/

/**
 * @brief   Low level PAL subsystem initialization.
 *
 * @notapi
 */
#define pal_lld_init() _pal_lld_init()

/**
 * @brief   Reads the physical I/O port states.
 *
 * @param[in] port      port identifier
 * @return              The port bits.
 *
 * @notapi
 */
#define pal_lld_readport(port)      _pal_lld_readport( port)

static inline uint16_t _pal_lld_readport(uint8_t port)
{
  __IO uint16_t *PODRx;
  PODRx = (__IO uint16_t *)((uint32_t)(&M4_GPIO->PODRA) + 0x10UL * port);
  return READ_REG16(*PODRx);
}
/**
 * @brief   Reads the output latch.
 * @details The purpose of this function is to read back the latched output
 *          value.
 *
 * @param[in] port      port identifier
 * @return              The latched logical states.
 *
 * @notapi
 */
#define pal_lld_readlatch(port)         _pal_lld_readlatch( port)

static inline uint16_t _pal_lld_readlatch(uint8_t port)
{
  __IO uint16_t *POERx;
  POERx = (__IO uint16_t *)((uint32_t)(&M4_GPIO->POERA) + 0x10UL * port);
  return READ_REG16(*POERx);
}

/**
 * @brief   Writes a bits mask on a I/O port.
 *
 * @param[in] port      port identifier
 * @param[in] bits      bits to be written on the specified port
 *
 * @notapi
 */
#define pal_lld_writeport(port, bits)     _pal_lld_writeport( port, bits)

static inline void _pal_lld_writeport(uint8_t port, uint16_t bits)
{
  __IO uint16_t *PODRx;
  PODRx = (__IO uint16_t *)((uint32_t)(&M4_GPIO->PODRA) + 0x10UL * port);
  WRITE_REG16(*PODRx,bits);
}
/**
 * @brief   Sets a bits mask on a I/O port.
 * @note    The @ref PAL provides a default software implementation of this
 *          functionality, implement this function if can optimize it by using
 *          special hardware functionalities or special coding.
 *
 * @param[in] port      port identifier
 * @param[in] bits      bits to be ORed on the specified port
 *
 * @notapi
 */
#define pal_lld_setport(port, bits)     _pal_lld_setport( port,  bits)

static inline void _pal_lld_setport(uint8_t port, uint16_t bits)
{
  __IO uint16_t *POSRx;
  POSRx = (__IO uint16_t *)((uint32_t)(&M4_GPIO->POSRA) + 0x10UL * port);
  SET_REG16_BIT(*POSRx, bits);
}
/**
 * @brief   Clears a bits mask on a I/O port.
 * @note    The @ref PAL provides a default software implementation of this
 *          functionality, implement this function if can optimize it by using
 *          special hardware functionalities or special coding.
 *
 * @param[in] port      port identifier
 * @param[in] bits      bits to be cleared on the specified port
 *
 * @notapi
 */
#define pal_lld_clearport(port, bits)    _pal_lld_clearport( port,  bits)                            \

static inline void _pal_lld_clearport(uint8_t port, uint16_t bits)
{
  __IO uint16_t *PORRx;
  PORRx = (__IO uint16_t *)((uint32_t)(&M4_GPIO->PORRA) + 0x10UL * port);
  WRITE_REG16(*PORRx,bits);
}
/**
 * @brief   Toggles a bits mask on a I/O port.
 * @note    The @ref PAL provides a default software implementation of this
 *          functionality, implement this function if can optimize it by using
 *          special hardware functionalities or special coding.
 *
 * @param[in] port      port identifier
 * @param[in] bits      bits to be XORed on the specified port
 *
 * @notapi
 */
#define pal_lld_toggleport(port, bits)   _pal_lld_toggleport( port,  bits)                                     \

static inline void  _pal_lld_toggleport(uint8_t port,uint16_t bits)
{
  __IO uint16_t *POTRx;
  POTRx = (__IO uint16_t *)((uint32_t)(&M4_GPIO->POTRA) + 0x10UL * port);
  SET_REG16_BIT(*POTRx,bits);
}

/**
 * @brief   Reads a group of bits.
 * @note    The @ref PAL provides a default software implementation of this
 *          functionality, implement this function if can optimize it by using
 *          special hardware functionalities or special coding.
 *
 * @param[in] port      port identifier
 * @param[in] mask      group mask
 * @param[in] offset    group bit offset within the port
 * @return              The group logical states.
 *
 * @notapi
 */
#define pal_lld_readgroup(port, mask, offset)  _pal_lld_readgroup( port, mask,  offset)

static inline uint16_t _pal_lld_readgroup(uint8_t port,uint16_t mask,uint16_t offset)
{
  __IO uint16_t *PCRx;
  uint16_t GPIO_Pin_Mask;
  uint16_t GPIO_State;
  uint16_t GPIO_State_back = 0x0000;
  uint8_t PinPos;
  GPIO_Pin_Mask = (uint16_t)(mask) << (offset);
  for (PinPos = 0U; PinPos < 16U; PinPos++)
  {
      if ((GPIO_Pin_Mask & (uint16_t)(1UL << PinPos)) != 0U)
      {
        PCRx = (__IO uint16_t *)((uint32_t)(&M4_GPIO->PCRA0) + \
                                    (uint32_t)(port * 0x40UL) + PinPos * 4UL);
        GPIO_State = READ_REG16_BIT(*PCRx,0x0001);
      }
      else
      {
        GPIO_State = 0;
      }
      GPIO_State_back |= (GPIO_State << PinPos);
  }
  return GPIO_State_back;
}

/**
 * @brief   Writes a group of bits.
 * @note    The @ref PAL provides a default software implementation of this
 *          functionality, implement this function if can optimize it by using
 *          special hardware functionalities or special coding.
 *
 * @param[in] port      port identifier
 * @param[in] mask      group mask
 * @param[in] offset    group bit offset within the port
 * @param[in] bits      bits to be written. Values exceeding the group width
 *                      are masked.
 *
 * @notapi
 */
#define pal_lld_writegroup(port, mask, offset, bits)     _pal_lld_writegroup( port,  mask,  offset,  bits)

static inline void _pal_lld_writegroup(uint8_t port, uint16_t mask, uint16_t offset, uint16_t bits)
{
  __IO uint16_t *POSRx;
  __IO uint16_t *PORRx;
  uint16_t GPIO_Pin;
  uint16_t GPIO_Pin_Reset;
  GPIO_Pin = ((uint16_t)(bits) & (uint16_t)(mask)) << (offset);
  GPIO_Pin_Reset = ((~(uint16_t)(bits) & (uint16_t)(mask)) << (offset));
  POSRx = (__IO uint16_t *)((uint32_t)(&M4_GPIO->POSRA) + 0x10UL * port);
  SET_REG16_BIT(*POSRx,GPIO_Pin);
  PORRx = (__IO uint16_t *)((uint32_t)(&M4_GPIO->PORRA) + 0x10UL * port);
  SET_REG16_BIT(*PORRx,GPIO_Pin_Reset);
}
/**
 * @brief   Pads group mode setup.
 * @details This function programs a pads group belonging to the same port
 *          with the specified mode.
 * @note    Programming an unknown or unsupported mode is silently ignored.
 *
 * @param[in] port      port identifier
 * @param[in] mask      group mask
 * @param[in] offset    group bit offset within the port
 * @param[in] mode      group mode  PAL_MODE_RESET or PAL_MODE_UNCONNECTED ....
 *
 * @notapi
 */
#define pal_lld_setgroupmode(port, mask, offset, mode)    _pal_lld_setgroupmode( port, mask , offset, mode)

static inline void _pal_lld_setgroupmode(uint8_t port, uint16_t mask, uint16_t offset, uint16_t mode)
{
  __IO uint16_t *PCRx;
  uint8_t PinPos;
  uint16_t GPIO_Pin;
  GPIO_Pin = (uint16_t)(mask) << (offset);
  for (PinPos = 0U; PinPos < 16U; PinPos++)
  {
      if ((GPIO_Pin & (uint16_t)(1UL << PinPos)) != 0U)
      {
          PCRx = (__IO uint16_t *)((uint32_t)(&M4_GPIO->PCRA0) + \
                                    (uint32_t)(port * 0x40UL) + PinPos * 4UL);
          SET_REG16_BIT(*PCRx, mode);
      }
  }
}
/**
 * @brief   Reads a logical state from an I/O pad.
 * @note    The @ref PAL provides a default software implementation of this
 *          functionality, implement this function if can optimize it by using
 *          special hardware functionalities or special coding.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number within the port
 * @return              The logical state.
 * @retval PAL_LOW      low logical state.
 * @retval PAL_HIGH     high logical state.
 *
 * @notapi
 */
#define pal_lld_readpad(port, pad) _pal_lld_readpad( port,  pad)

static inline uint16_t _pal_lld_readpad(uint8_t port, uint16_t pad)
{
  __IO uint16_t *PFSRx;
  __IO uint16_t *PODRx;
  __IO uint16_t *PIDRx;
  uint8_t PinPos;
  uint16_t GPIO_Pin;
  uint16_t GPIO_State;
  GPIO_Pin = (uint16_t)(1UL << pad);
  for (PinPos = 0U; PinPos < 16U; PinPos++)
  {
      if ((GPIO_Pin & (uint16_t)(1UL << PinPos)) != 0U)
      {
          PFSRx = (__IO uint16_t *)((uint32_t)(&M4_GPIO->PFSRA0) + \
                                    (uint32_t)(port * 0x40UL) + PinPos * 4UL);
          GPIO_State = READ_REG16(*PFSRx);
      }
  }
  if((GPIO_State == 0x0000) ||((GPIO_State | 0x0000) == 0x0100))
    {
      PODRx = (__IO uint16_t *)((uint32_t)(&M4_GPIO->PODRA) + 0x10UL * port);
      return ((*PODRx & (GPIO_Pin)) != 0U) ? Pin_Set : Pin_Reset;
    }
    else
    {
      PIDRx = (__IO uint16_t *)((uint32_t)(&M4_GPIO->PIDRA) + 0x10UL * port);
      return ((READ_REG16(*PIDRx) & (GPIO_Pin)) != 0U) ? Pin_Set : Pin_Reset;
    }
}

/**
 * @brief   Writes a logical state on an output pad.
 * @note    This function is not meant to be invoked directly by the
 *          application  code.
 * @note    The @ref PAL provides a default software implementation of this
 *          functionality, implement this function if can optimize it by using
 *          special hardware functionalities or special coding.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number within the port
 * @param[in] bit       logical value, the value must be @p PAL_LOW or
 *                      @p PAL_HIGH
 *
 * @notapi
 */
#define pal_lld_writepad(port, pad, bit)    _pal_lld_writepad(port, pad, bit)

static inline void _pal_lld_writepad(uint8_t port, uint16_t pad, uint16_t bit)
{
   __IO uint16_t *PODRx;
   uint16_t GPIO_Pin;
   PODRx = (__IO uint16_t *)((uint32_t)(&M4_GPIO->PODRA) + 0x10UL * port);
   GPIO_Pin = (uint16_t)(1UL << pad);
  if( bit != 0U )
  {
    SET_REG16_BIT(*PODRx, GPIO_Pin);
  }
  else
  {
    CLEAR_REG16_BIT(*PODRx, GPIO_Pin);
  }
}

/**
 * @brief   Sets a pad logical state to @p PAL_HIGH.
 * @note    The @ref PAL provides a default software implementation of this
 *          functionality, implement this function if can optimize it by using
 *          special hardware functionalities or special coding.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number within the port
 *
 * @notapi
 */
#define pal_lld_setpad(port, pad)       _pal_lld_setpad( port, pad)        \

static inline void _pal_lld_setpad(uint8_t port, uint16_t pad)
{
  __IO uint16_t *POSRx;
  uint16_t GPIO_Pin;
  GPIO_Pin  = (uint16_t)(1UL << pad);
  POSRx = (__IO uint16_t *)(((uint32_t)(&M4_GPIO->POSRA) + 0x10UL * port));
  SET_REG16_BIT(*POSRx, GPIO_Pin);
}
/**
 * @brief   Clears a pad logical state to @p PAL_LOW.
 * @note    The @ref PAL provides a default software implementation of this
 *          functionality, implement this function if can optimize it by using
 *          special hardware functionalities or special coding.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number within the port
 *
 * @notapi
 */
#define pal_lld_clearpad(port, pad)    _pal_lld_clearpad( port,  pad)         \

static inline void  _pal_lld_clearpad(uint8_t port, uint16_t pad)
{
  __IO uint16_t *PORRx;
  uint16_t GPIO_Pin;
  GPIO_Pin = (uint16_t)(1UL << pad);
  PORRx = (__IO uint16_t *)(((uint32_t)(&M4_GPIO->PORRA) + 0x10UL * port));
  SET_REG16_BIT(*PORRx, GPIO_Pin);
}

/**
 * @brief   Toggles a pad logical state.
 * @note    The @ref PAL provides a default software implementation of this
 *          functionality, implement this function if can optimize it by using
 *          special hardware functionalities or special coding.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number within the port
 *
 * @notapi
 */
#define pal_lld_togglepad(port, pad)  _pal_lld_togglepad( port,  pad)         \

static inline void _pal_lld_togglepad(uint8_t port, uint16_t pad)
{
  __IO uint16_t *POTRx;
  uint16_t GPIO_Pin;
  GPIO_Pin = (uint16_t)(1UL << pad);
  POTRx = (__IO uint16_t *)((uint32_t)(&M4_GPIO->POTRA) + 0x10UL * port);
  SET_REG16_BIT(*POTRx, GPIO_Pin);
}

/**
 * @brief   Pad mode setup.
 * @details This function programs a pad with the specified mode.
 * @note    The @ref PAL provides a default software implementation of this
 *          functionality, implement this function if can optimize it by using
 *          special hardware functionalities or special coding.
 * @note    Programming an unknown or unsupported mode is silently ignored.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number within the port
 * @param[in] mode      pad mode PAL_MODE_RESET or PAL_MODE_UNCONNECTED ....
 *
 * @notapi
 */
#define pal_lld_setpadmode(port, pad, mode)  _pal_lld_setpadmode( port, pad, mode)
static inline void _pal_lld_setpadmode(uint8_t port,uint16_t pad,uint16_t mode)
{
  __IO uint16_t *PCRx;
  uint8_t PinPos;
  uint16_t GPIO_Pin;
  GPIO_Pin = (uint16_t)(1UL << pad);
  for (PinPos = 0U; PinPos < 16U; PinPos++)
  {
    if ((GPIO_Pin & (1UL<<PinPos)) != 0U)
      {
          PCRx = (__IO uint16_t *)((uint32_t)(&M4_GPIO->PCRA0) + \
                                    (uint32_t)(port * 0x40UL) + PinPos * 4UL);
          SET_REG16_BIT(*PCRx, mode);
      }
  }
}
/**
 * @brief   Returns a PAL event structure associated to a pad.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number within the port
 *
 * @notapi
 */
#define pal_lld_get_pad_event(port, pad)                                    \
  &_pal_events[pad]; (void)(port)

/**
 * @brief   Sets a line logic state to @p PAL_HIGH.
 * @note    The operation is not guaranteed to be atomic on all the
 *          architectures, for atomicity and/or portability reasons you may
 *          need to enclose port I/O operations between @p osalSysLock() and
 *          @p osalSysUnlock().
 * @note    The function can be called from any context.
 *
 * @param[in] line      line identifier
 *
 * @special
 */
#define  pal_lld_setline(line)      _pal_lld_setline(line)
static inline void _pal_lld_setline(uint16_t line)
{
  __IO uint16_t *POSRx;
  POSRx = (__IO uint16_t *)(((uint32_t)(&M4_GPIO->POSRA) + 0x10UL * (PAL_PORT(line))));
  SET_REG16_BIT(*POSRx, (1UL << PAL_PAD(line)));
}

/**
 * @brief   Clears a line logic state to @p PAL_LOW.
 * @note    The operation is not guaranteed to be atomic on all the
 *          architectures, for atomicity and/or portability reasons you may
 *          need to enclose port I/O operations between @p osalSysLock() and
 *          @p osalSysUnlock().
 * @note    The function can be called from any context.
 *
 * @param[in] line      line identifier
 *
 * @special
 */
#define pal_lld_clearline(line)  _pal_lld_clearline(line)
static inline void _pal_lld_clearline(uint16_t line)
{
    __IO uint16_t *PORRx;
    PORRx = (__IO uint16_t *)((uint32_t)(&M4_GPIO->PORRA) + 0x10UL *  (PAL_PORT(line)));
    SET_REG16_BIT(*PORRx, (1UL << PAL_PAD(line)));
}

/**
 * @brief   Toggles a line logic state.
 * @note    The operation is not guaranteed to be atomic on all the
 *          architectures, for atomicity and/or portability reasons you may
 *          need to enclose port I/O operations between @p osalSysLock() and
 *          @p osalSysUnlock().
 * @note    The function can be called from any context.
 *
 * @param[in] line      line identifier
 *
 * @special
 */
#define pal_lld_toggleline(line)  _pal_lld_toggleline(line)
static inline void _pal_lld_toggleline(uint16_t line)
{
  __IO uint16_t *POTRx;
  POTRx = (__IO uint16_t *)((uint32_t)(&M4_GPIO->POTRA) + 0x10UL *  (PAL_PORT(line)));
  SET_REG16_BIT(*POTRx, (1UL << PAL_PAD(line)));
}

/**
 * @brief   Writes a logic state on an output line.
 * @note    The operation is not guaranteed to be atomic on all the
 *          architectures, for atomicity and/or portability reasons you may
 *          need to enclose port I/O operations between @p osalSysLock() and
 *          @p osalSysUnlock().
 * @note    The function can be called from any context.
 *
 * @param[in] line      line identifier
 * @param[in] bit       logic value, the value must be @p PAL_LOW or
 *                      @p PAL_HIGH
 *
 * @special
 */
#define pal_lld_writeline(line, bit) _pal_lld_writeline(line, bit)
static inline void _pal_lld_writeline(uint16_t line,uint16_t bit)
{
  __IO uint16_t *PODRx;
  PODRx = (__IO uint16_t *)((uint32_t)(&M4_GPIO->PODRA) + 0x10UL * (PAL_PORT(line)));
 if( bit != 0U )
 {
   SET_REG16_BIT(*PODRx, (1UL << PAL_PAD(line)));
 }
 else
 {
   CLEAR_REG16_BIT(*PODRx, (1UL << PAL_PAD(line)));
 }
}

/**
 * @brief   Reads an input line logic state.
 * @note    The function can be called from any context.
 *
 * @param[in] line      line identifier
 * @return              The logic state.
 * @retval PAL_LOW      low logic state.
 * @retval PAL_HIGH     high logic state.
 *
 * @special
 */
#define pal_lld_readline(line)  _pal_lld_readline(line)
static inline uint16_t _pal_lld_readline(uint16_t line)
{
    __IO uint16_t *PFSRx;
    __IO uint16_t *PODRx;
    __IO uint16_t *PIDRx;
    uint8_t PinPos;
    uint16_t GPIO_State = 0;
    for (PinPos = 0U; PinPos < 16U; PinPos++)
    {
        if (PAL_PAD(line) == PinPos)
        {
            PFSRx = (__IO uint16_t *)((uint32_t)(&M4_GPIO->PFSRA0) + \
                                      (uint32_t)(PAL_PORT(line) * 0x40UL) + PinPos * 4UL);
            GPIO_State = READ_REG16(*PFSRx);
        }
    }
    if((GPIO_State == 0x0000) ||((GPIO_State | 0x0000) == 0x0100))
      {
        PODRx = (__IO uint16_t *)((uint32_t)(&M4_GPIO->PODRA) + 0x10UL * PAL_PORT(line));
        return ((*PODRx & (1UL << PAL_PAD(line))) != 0U) ? Pin_Set : Pin_Reset;
      }
      else
      {
        PIDRx = (__IO uint16_t *)((uint32_t)(&M4_GPIO->PIDRA) + 0x10UL * PAL_PORT(line));
        return ((READ_REG16(*PIDRx) & (1UL << PAL_PAD(line))) != 0U) ? Pin_Set : Pin_Reset;
      }
}

/**
 * @brief   Line mode setup.
 * @note    The operation is not guaranteed to be atomic on all the
 *          architectures, for atomicity and/or portability reasons you may
 *          need to enclose port I/O operations between @p osalSysLock() and
 *          @p osalSysUnlock().
 * @note    The function can be called from any context.
 *
 * @param[in] line      line identifier
 * @param[in] mode      pad mode PAL_MODE_RESET or PAL_MODE_UNCONNECTED ....
 *
 * @special
 */
#define pal_lld_setlinemode(line, mode)  _pal_lld_setlinemode(line, mode)
static inline void  _pal_lld_setlinemode(uint16_t line, uint16_t mode)
{
  __IO uint16_t *PCRx;
  uint8_t u8PinPos;
   for (u8PinPos = 0U; u8PinPos < 16U; u8PinPos++)
   {
       if(PAL_PAD(line) == u8PinPos)
       {
         PCRx = (__IO uint16_t *)((uint32_t)(&M4_GPIO->PCRA0) + \
                                     (uint32_t)(PAL_PORT(line) * 0x40UL) + u8PinPos * 4UL);
         SET_REG16_BIT(*PCRx, mode);
       }
   }
}

/**
 * @brief   Pad event enable.
 * @note    Programming an unknown or unsupported mode is silently ignored.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number within the port
 * @param[in] mode      pad event mode PAL_EVENT_MODE_EDGES_MASK or PAL_EVENT_MODE_DISABLED ...
 *
 * @notapi
 */
#define pal_lld_enablepadevent(port, pad, mode)  _pal_lld_enablepadevent(port, pad, mode)
static inline void _pal_lld_enablepadevent(uint16_t port,uint16_t pad,uint8_t mode)
{
  __IO uint16_t *PCRx;
  uint8_t u8PinPos;
  uint16_t GPIO_Pin;
  GPIO_Pin = (uint16_t)(1UL << pad);
   for (u8PinPos = 0U; u8PinPos < 16U; u8PinPos++)
   {
        if ((GPIO_Pin & (uint16_t)(1UL << u8PinPos)) != 0U)
       {
         PCRx = (__IO uint16_t *)((uint32_t)(&M4_GPIO->PCRA0) + \
                                     (uint32_t)(port * 0x40UL) + u8PinPos * 4UL);
         SET_REG16_BIT(*PCRx,0x1000);
         SET_REG32_BIT(*(uint32_t *)((uint32_t)(&M4_INTC->EIRQCR0) + 4UL*u8PinPos),(uint32_t)mode);
       }
   }
}

/**
 * @brief   Line event enable.
 * @note    Programming an unknown or unsupported mode is silently ignored.
 *
 * @param[in] line      line identifier
 * @param[in] mode      line event mode PAL_EVENT_MODE_EDGES_MASK or PAL_EVENT_MODE_DISABLED ...
 *
 * @iclass
 */
#define pal_lld_enablelineevent(line, mode) _pal_lld_enablelineevent(line, mode)
static inline void _pal_lld_enablelineevent(uint16_t line, uint8_t mode)
{
  __IO uint16_t *PCRx;
  uint8_t u8PinPos;
   for (u8PinPos = 0U; u8PinPos < 16U; u8PinPos++)
   {
       if (PAL_PAD(line) == u8PinPos)
       {
         PCRx = (__IO uint16_t *)((uint32_t)(&M4_GPIO->PCRA0) + \
                                     (uint32_t)(PAL_PORT(line) * 0x40UL) + u8PinPos * 4UL);
         SET_REG16_BIT(*PCRx,0x1000);
         SET_REG32_BIT(*(uint32_t *)((uint32_t)(&M4_INTC->EIRQCR0) + 4UL*u8PinPos),(uint32_t)mode);
       }
   }
}

/**
 * @brief   Line event disable.
 * @details This function also disables previously programmed event callbacks.
 *
 * @param[in] line      line identifier
 *
 * @iclass
 */
#define pal_lld_disablelineevent(line) _pal_lld_disablelineevent(line)
static inline void _pal_lld_disablelineevent(uint16_t line)
{
  __IO uint16_t *PCRx;
  uint8_t u8PinPos;
  for (u8PinPos = 0U; u8PinPos < 16U; u8PinPos++)
  {
      if ((PAL_PAD(line) == u8PinPos))
      {
        PCRx = (__IO uint16_t *)((uint32_t)(&M4_GPIO->PCRA0) + \
                                    (uint32_t)(PAL_PORT(line) * 0x40UL) + u8PinPos * 4UL);
        CLEAR_REG16_BIT(*PCRx,0X1000);
      }
  }
}
/**
 * @brief   Returns a PAL event structure associated to a line.
 *
 * @param[in] line      line identifier
 *
 * @notapi
 */
#define pal_lld_get_line_event(line)                        \
  &_pal_events[PAL_PAD(line)];

#if !defined(__DOXYGEN__)
#if (PAL_USE_WAIT == TRUE) || (PAL_USE_CALLBACKS == TRUE)
extern palevent_t _pal_events[16];
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void _pal_lld_init(void);
  void _pal_lld_setpadfunc(ioportid_t port,
                               iopadid_t pad,
                               uint8_t mode,uint16_t bef);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_PAL == TRUE */

#endif /* HAL_PAL_LLD_H */

/** @} */
