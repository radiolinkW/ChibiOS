/*
    ChibiOS - Copyright (C) 2022 Radiolink
    Driver by Radiolink Diao, March 2022
*/

/**
 * @file        USARTv1/hc32_uart.h
 * @brief       HC32 USART units common header.
 * @note        This file requires definitions from the UART HC32 header file.
 *
 * @addtogroup HC32_USARTv1
 * @{
 */

#ifndef HC32_UART_H
#define HC32_UART_H

#define USART_DIV(INSTANCE)     (1UL << (READ_REG32_BIT((INSTANCE)->PR, USART_PR_PSC) * 2UL))

#define PCLK_FREQ     (240000000 >> (READ_REG32_BIT(M4_CMU->SCFGR, CMU_SCFGR_PCLK1S) >> CMU_SCFGR_PCLK1S_POS))

/**
 * @defgroup USART_Flag_Mask USART flag mask definition
 * @{
 */
#define USART_FLAG_MASK                     (USART_FLAG_PE      |              \
                                             USART_FLAG_FE      |              \
                                             USART_FLAG_ORE     |              \
                                             USART_FLAG_BE      |              \
                                             USART_FLAG_RXNE    |              \
                                             USART_FLAG_TC      |              \
                                             USART_FLAG_TXE     |              \
                                             USART_FLAG_RTOF    |              \
                                             USART_FLAG_LBD     |              \
                                             USART_FLAG_WKUP    |              \
                                             USART_FLAG_MPB)
/**
 * @}
 */


/**
 * @defgroup USART_CR1_Clear_Flag_Mask USART register clear flag bits mask definition
 * @{
 */
#define USART_CR1_CLR_FLAG_MASK             (USART_CR1_CPE      |              \
                                             USART_CR1_CORE     |              \
                                             USART_CR1_CFE      |              \
                                             USART_CR1_CRTOF    |              \
                                             USART_CR1_CBE      |              \
                                             USART_CR1_CWKUP    |              \
                                             USART_CR1_CLBD)
/**
 * @}
 */

/**
 * @defgroup USART_CR2_Reserved_Bit USART CR2 register reserved bit 9/10 definition
 * @{
 */
#define USART_CR2_BIT9                      (0x00000200UL)
#define USART_CR2_BIT10                     (0x00000400UL)
/**
 * @}
 */

/**
 * @defgroup USART_function_Mask USART function mask definition
 * @{
 */
#define USART_FUNCTION_MASK                 (USART_RX       |                  \
                                             USART_TX       |                  \
                                             USART_RTO      |                  \
                                             USART_INT_RX   |                  \
                                             USART_INT_TC   |                  \
                                             USART_INT_TXE  |                  \
                                             USART_INT_RTO)
/**
 * @}
 */

/**
 * @defgroup USART_Flag USART Flag
 * @{
 */
#define USART_FLAG_PE                       (USART_SR_PE)       /*!< Parity error flag */
#define USART_FLAG_FE                       (USART_SR_FE)       /*!< Framing error flag */
#define USART_FLAG_ORE                      (USART_SR_ORE)      /*!< Overrun error flag */
#define USART_FLAG_BE                       (USART_SR_BE)       /*!< LIN bus error flag */
#define USART_FLAG_RXNE                     (USART_SR_RXNE)     /*!< Receive data register not empty flag */
#define USART_FLAG_TC                       (USART_SR_TC)       /*!< Transmission complete flag */
#define USART_FLAG_TXE                      (USART_SR_TXE)      /*!< Transmit data register empty flag */
#define USART_FLAG_RTOF                     (USART_SR_RTOF)     /*!< Receive timeout flag */
#define USART_FLAG_LBD                      (USART_SR_LBD)      /*!< LIN break signal detection flag */
#define USART_FLAG_WKUP                     (USART_SR_WKUP)     /*!< LIN wakeup signal detection flag */
#define USART_FLAG_MPB                      (USART_SR_MPB)      /*!< Receive processor ID flag */
/**
 * @}
 */

/**
 * @defgroup USART_Transmission_Type USART Transmission Type
 * @{
 */
#define USART_TRANSMISSION_ID               (USART_DR_MPID)
#define USART_TRANSMISSION_DATA             (0UL)
/**
 * @}
 */


/**
 * @defgroup USART_Clear_Flag USART Clear Flag
 * @{
 */
#define USART_CLEAR_FLAG_PE                 (USART_CR1_CPE)     /*!< Clear Parity error flag */
#define USART_CLEAR_FLAG_FE                 (USART_CR1_CFE)     /*!< Clear Framing error flag */
#define USART_CLEAR_FLAG_ORE                (USART_CR1_CORE)    /*!< Clear Overrun error flag */
#define USART_CLEAR_FLAG_RTOF               (USART_CR1_CRTOF)   /*!< Clear RX timeout flag */
#define USART_CLEAR_FLAG_BE                 (USART_CR1_CBE)     /*!< Clear LIN bus error flag */
#define USART_CLEAR_FLAG_WKUP               (USART_CR1_CWKUP)   /*!< Clear LIN wakeup signal flag */
#define USART_CLEAR_FLAG_LBD                (USART_CR1_CLBD)    /*!< Clear LIN break detection flag */
/**
 * @}
 */


/**
 * @defgroup USART_Transmit_Receive_Function USART Transmit/Receive Function
 * @{
 */
#define USART_RX                            (USART_CR1_RE)      /*!< USART RX function */
#define USART_TX                            (USART_CR1_TE)      /*!< USART TX function */
#define USART_RTO                           (USART_CR1_RTOE)    /*!< USART RX timerout function */
#define USART_INT_RX                        (USART_CR1_RIE)     /*!< USART receive data register not empty && receive error interrupt */
#define USART_INT_TXE                       (USART_CR1_TXEIE)   /*!< USART transmit data register empty interrupt */
#define USART_INT_TC                        (USART_CR1_TCIE)    /*!< USART transmission complete interrupt */
#define USART_INT_RTO                       (USART_CR1_RTOIE)   /*!< USART RX timerout interrupt */
/**
 * @}
 */

/**
 * @defgroup USART_Parity_Control USART Parity Control
 * @{
 */
#define USART_PARITY_NONE                   (0UL)               /*!< Parity control disabled */
#define USART_PARITY_EVEN                   (USART_CR1_PCE)     /*!< Parity control enabled and Even Parity is selected */
#define USART_PARITY_ODD                    (USART_CR1_PCE | \
                                             USART_CR1_PS)      /*!< Parity control enabled and Odd Parity is selected */
/**
 * @}
 */

/**
 * @defgroup USART_Data_Length_Bits Data Length Bits
 * @{
 */
#define USART_DATA_LENGTH_8BIT              (0UL)               /*!< 8 bits */
#define USART_DATA_LENGTH_9BIT              (USART_CR1_M)       /*!< 9 bits */
/**
 * @}
 */

/**
 * @defgroup USART_Oversampling_Bits USART Oversampling Bits
 * @{
 */
#define USART_OVERSAMPLING_16BIT            (0UL)               /*!< Oversampling by 16 bits */
#define USART_OVERSAMPLING_8BIT             (USART_CR1_OVER8)   /*!< Oversampling by 8 bits */
/**
 * @}
 */

/**
 * @defgroup USART_Significant_Bit USART Significant Bit
 * @{
 */
#define USART_LSB                           (0UL)               /*!< LSB(Least Significant Bit) */
#define USART_MSB                           (USART_CR1_ML)      /*!< MSB(Most Significant Bit) */
/**
 * @}
 */

/**
 * @defgroup USART_Clock_Mode USART Clock Mode Selection
 * @{
 */
#define USART_EXTCLK                        (USART_CR2_CLKC_1)  /*!< Select external clock source. */
#define USART_INTERNCLK_OUTPUT              (USART_CR2_CLKC_0)  /*!< Select internal clock source and output clock. */
#define USART_INTERNCLK_NONE_OUTPUT         (0UL)               /*!< Select internal clock source and don't output clock */
/**
 * @}
 */

/**
 * @defgroup USART_Noise_Filter_State USART Noise Filter State
 * @{
 */
#define USART_NOISE_FILTER_DISABLE          (0UL)               /*!< Disable noise filter */
#define USART_NOISE_FILTER_ENABLE           (USART_CR1_NFE)     /*!< Enable noise filter */
/**
 * @}
 */

/**
 * @defgroup USART_Start_Bit_Detect_Polarity USART Start Bit Detect Polarity
 * @{
 */
#define USART_SB_DETECT_LOW                 (0UL)               /*!< Detect RX pin low level */
#define USART_SB_DETECT_FALLING             (USART_CR1_SBS)     /*!< Detect RX pin falling edge */
/**
 * @}
 */

/**
 * @defgroup USART_PCLK_Division USART PCLK Clock Prescaler Division
 * @{
 */
#define USART_PCLK_DIV1                     (0UL)               /*!< PCLK */
#define USART_PCLK_DIV4                     (USART_PR_PSC_0)    /*!< PCLK/4 */
#define USART_PCLK_DIV16                    (USART_PR_PSC_1)    /*!< PCLK/16 */
#define USART_PCLK_DIV64                    (USART_PR_PSC)      /*!< PCLK/64 */
/**
 * @}
 */

/**
 * @defgroup USART_Stop_Bits USART Stop Bits
 * @{
 */
#define USART_CR2_STOP1_BITS                  (0UL)               /*!< 1 stop bit */
#define USART_CR2_STOP2_BITS                  (USART_CR2_STOP)    /*!< 2 stop bit */
/**
 * @}
 */

/**
 * @defgroup USART_Hardware_Flow_Control USART Hardware Flow Control RTS/CTS
 * @{
 */
#define USART_HWFLOWCTRL_NONE               (0UL)               /*!< Disable USART hardware flow controle */
#define USART_HWFLOWCTRL_RTS                (USART_CR3_RTSE)    /*!< USART hardware flow control RTS mode */
#define USART_HWFLOWCTRL_CTS                (USART_CR3_CTSE)    /*!< USART hardware flow control CTS mode */
#define USART_HWFLOWCTRL_RTS_CTS            (USART_CR3_RTSE | \
                                             USART_CR3_CTSE)    /*!< USART hardware flow control RTS and CTS mode */
/**
 * @}
 */



#endif /* HC32_UART_H */
