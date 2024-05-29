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

#include "ch.h"
#include "hal.h"

//static virtual_timer_t vt1, vt2;
//
//static void restart(void *p) {
//
//  (void)p;
//
//  chSysLockFromISR();
//  uartStartSendI(&UARTD1, 14, "Hello World!\r\n");
//  chSysUnlockFromISR();
//}
//
//static void ledoff(void *p) {
//
//  (void)p;
//
////  palSetPad(IOPORT3, GPIOC_LED);
//}

/*
 * This callback is invoked when a transmission buffer has been completely
 * read by the driver.
 */
static void txend1(UARTDriver *uartp) {

  (void)uartp;

//  palClearPad(IOPORT3, GPIOC_LED);
}

/*
 * This callback is invoked when a transmission has physically completed.
 */
static void txend2(UARTDriver *uartp) {

  (void)uartp;

//  palSetPad(IOPORT3, GPIOC_LED);
//  chSysLockFromISR();
//  chVTResetI(&vt1);
//  chVTDoSetI(&vt1, TIME_MS2I(5000), restart, NULL);
//  chSysUnlockFromISR();
}

/*
 * This callback is invoked on a receive error, the errors mask is passed
 * as parameter.
 */
static void rxerr(UARTDriver *uartp, uartflags_t e) {

  (void)uartp;
  (void)e;
}

/*
 * This callback is invoked when a character is received but the application
 * was not ready to receive it, the character is passed as parameter.
 */
static void rxchar(UARTDriver *uartp, uint16_t c) {

  (void)uartp;
  (void)c;

  /* Flashing the LED each time a character is received.*/
//  palClearPad(IOPORT3, GPIOC_LED);
//  chSysLockFromISR();
//  chVTResetI(&vt2);
//  chVTDoSetI(&vt2, TIME_MS2I(200), ledoff, NULL);
//  chSysUnlockFromISR();
}

/*
 * This callback is invoked when a receive buffer has been completely written.
 */
static void rxend(UARTDriver *uartp) {

  (void)uartp;
}

/*
 * UART driver configuration structure.
 */
static UARTConfig uart_cfg_1 = {
  txend1,
  txend2,
  rxend,
  rxchar,
  rxerr,
  115200,
  0,
  USART_CR2_STOP1_BITS,
  0
};
char buf[11] = {0};

static THD_WORKING_AREA(waThread1, 128);
static THD_FUNCTION(Thread1, arg) {
  (void)arg;
  while(1){
  uartStartSend(&UARTD1, 11, "123456789\r\n");
  chThdSleepMilliseconds(1000);
  }
}

static THD_WORKING_AREA(waThread2, 128);
static THD_FUNCTION(Thread2, arg) {
  (void)arg;
  while(1){
    uartStartSend(&UARTD3,sizeof(buf), buf);
    chThdSleepMilliseconds(500);
  }
}

/*
 * Application entry point.
 */

int main(void) {

  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  halInit();
  chSysInit();

  chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO, Thread1, NULL);
  chThdCreateStatic(waThread2, sizeof(waThread2), NORMALPRIO, Thread2, NULL);
  __IO uint16_t *PFSRx;
  uint8_t u8PinPos;

  /*RX PH13 FUNC33*/
   for (u8PinPos = 0U; u8PinPos < 16U; u8PinPos++)
       {
           if ((0x2000U & (uint16_t)(1UL << u8PinPos)) != 0U)
           {
               PFSRx = (__IO uint16_t *)((uint32_t)(&M4_GPIO->PFSRA0) + \
                                         (uint32_t)(0x07U * 0x40UL) + u8PinPos * 4UL);
               WRITE_REG16(*PFSRx, (0 | (uint16_t)0x21U));
           }
       }
   /*TX PH15 FUNC32*/
   for (u8PinPos = 0U; u8PinPos < 16U; u8PinPos++)
       {
           if ((0x8000U & (uint16_t)(1UL << u8PinPos)) != 0U)
           {
               PFSRx = (__IO uint16_t *)((uint32_t)(&M4_GPIO->PFSRA0) + \
                                         (uint32_t)(0x07U * 0x40UL) + u8PinPos * 4UL);
               WRITE_REG16(*PFSRx, (0 | (uint16_t)0x20U));
           }
       }

   /*RX PB8 FUNC35*/
      for (u8PinPos = 0U; u8PinPos < 16U; u8PinPos++)
          {
              if ((0x0100U & (uint16_t)(1UL << u8PinPos)) != 0U)
              {
                  PFSRx = (__IO uint16_t *)((uint32_t)(&M4_GPIO->PFSRA0) + \
                                            (uint32_t)(0x01U * 0x40UL) + u8PinPos * 4UL);
                  WRITE_REG16(*PFSRx, (0 | (uint16_t)0x23U));
              }
          }
      /*TX PB9 FUNC34*/
      for (u8PinPos = 0U; u8PinPos < 16U; u8PinPos++)
          {
              if ((0x0200U & (uint16_t)(1UL << u8PinPos)) != 0U)
              {
                  PFSRx = (__IO uint16_t *)((uint32_t)(&M4_GPIO->PFSRA0) + \
                                            (uint32_t)(0x01U * 0x40UL) + u8PinPos * 4UL);
                  WRITE_REG16(*PFSRx, (0 | (uint16_t)0x22U));
              }
          }


      /*RX PD8 FUNC37*/
         for (u8PinPos = 0U; u8PinPos < 16U; u8PinPos++)
             {
                 if ((0x0100U & (uint16_t)(1UL << u8PinPos)) != 0U)
                 {
                     PFSRx = (__IO uint16_t *)((uint32_t)(&M4_GPIO->PFSRA0) + \
                                               (uint32_t)(0x03U * 0x40UL) + u8PinPos * 4UL);
                     WRITE_REG16(*PFSRx, (0 | (uint16_t)0x25U));
                 }
             }
         /*TX PD9 FUNC36*/
         for (u8PinPos = 0U; u8PinPos < 16U; u8PinPos++)
             {
                 if ((0x0200U & (uint16_t)(1UL << u8PinPos)) != 0U)
                 {
                     PFSRx = (__IO uint16_t *)((uint32_t)(&M4_GPIO->PFSRA0) + \
                                               (uint32_t)(0x03U * 0x40UL) + u8PinPos * 4UL);
                     WRITE_REG16(*PFSRx, (0 | (uint16_t)0x24U));
                 }
             }

  /*
   * Activates the serial driver 2 using the driver default configuration.
   */
  uartStart(&UARTD1, &uart_cfg_1);
  uartStart(&UARTD2, &uart_cfg_1);
  uartStart(&UARTD3, &uart_cfg_1);
  /*
   * Starts the transmission, it will be handled entirely in background.
   */
  /*
   * Normal main() thread activity, in this demo it does nothing.
   */

  while (true) {
    memset(buf,0,sizeof(buf));
     uartStartReceive(&UARTD2, sizeof(buf), buf);
    chThdSleepMilliseconds(50);

//    if(txbuf != NULL){
//      uartStartSend(&UARTD1, sizeof(buf), buf);
//    }
//    chThdSleepMilliseconds(500);
  }
  return 0;
}
