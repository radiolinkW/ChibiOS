/*
    ChibiOS - Copyright (C) 2022 Radiolink
    Driver by Radiolink Wu, May 2022
*/

/**
 * @file    SPIv1/hal_spi_lld.h
 * @brief   HC32 SPI subsystem low level driver header.
 *
 * @addtogroup SPI
 * @{
 */
#ifndef HAL_SPI_LLD_H
#define HAL_SPI_LLD_H

/*******************************************************************************
 * Global pre-processor symbols/macros ('#define')
 ******************************************************************************/
/**
 * @defgroup SPI_Global_Macros SPI Global Macros
 * @{
 */

/**
 * @defgroup SPI_Wire_Mode_Define SPI wire mode define
 * @{
 */
#define SPI_WIRE_4                  (0UL)
#define SPI_WIRE_3                  (SPI_CR1_SPIMDS)
/**
 * @}
 */

/**
 * @defgroup SPI_Transfer_Mode_Define SPI transfer mode define
 * @{
 */
#define SPI_FULL_DUPLEX             (0UL)               /*!< Full duplex. */
#define SPI_SEND_ONLY               (SPI_CR1_TXMDS)     /*!< Send only. */
/**
 * @}
 */

/**
 * @defgroup SPI_Master_Slave_Mode_Define SPI master slave mode define
 * @{
 */
#define SPI_SLAVE                   (0UL)
#define SPI_MASTER                  (SPI_CR1_MSTR)
/**
 * @}
 */

/**
 * @defgroup SPI_Communication_Suspend_Function_Define SPI communication suspend function define
 * @{
 */
#define SPI_COM_SUSP_FUNC_OFF       (0UL)
#define SPI_COM_SUSP_FUNC_ON        (SPI_CR1_CSUSPE)
/**
 * @}
 */

/**
 * @defgroup SPI_Mode_Fault_Dectet_Command_Define SPI mode fault dectect command define
 * @{
 */
#define SPI_MODFE_DISABLE           (0UL)               /*!< Disable mode fault detection. */
#define SPI_MODFE_ENABLE            (SPI_CR1_MODFE)     /*!< Enable mode fault detection. */
/**
 * @}
 */

/**
 * @defgroup SPI_Parity_Check_Define SPI parity check mode define
 * @{
 */
#define SPI_PARITY_INVALID          (0UL)                           /*!< Parity check invalid. */
#define SPI_PARITY_EVEN             (SPI_CR1_PAE)                   /*!< Parity check selection even parity. */
#define SPI_PARITY_ODD              (SPI_CR1_PAE | SPI_CR1_PAOE)    /*!< Parity check selection odd parity. */
/**
 * @}
 */

/**
 * @defgroup SPI_Frame_Level_Define SPI data frame level define, The Data in the
 *                                   SPI_DR register will be send to TX_BUFF after
 *                                   enough data frame write to the SPI_DR
 * @{
 */
#define SPI_FRAME_1     (0UL)                               /*!< Data 1 frame */
#define SPI_FRAME_2     (SPI_CFG1_FTHLV_0)                  /*!< Data 2 frame.*/
#define SPI_FRAME_3     (SPI_CFG1_FTHLV_1)                  /*!< Data 3 frame.*/
#define SPI_FRAME_4     (SPI_CFG1_FTHLV_0 | SPI_CFG1_FTHLV_1) /*!< Data 4 frame.*/
/**
 * @}
 */

/**
 * @defgroup SPI_Mode_Define SPI Mode define
 * @{
 */
/* SCK pin output low in idle state; MOSI/MISO pin data valid in odd edge , MOSI/MISO pin data change in even edge */
#define SPI_MODE_0                  (0UL)
/* SCK pin output low in idle state; MOSI/MISO pin data valid in even edge , MOSI/MISO pin data change in odd edge */
#define SPI_MODE_1                  (SPI_CFG2_CPHA)
/* SCK pin output high in idle state; MOSI/MISO pin data valid in odd edge , MOSI/MISO pin data change in even edge */
#define SPI_MODE_2                  (SPI_CFG2_CPOL)
/* SCK pin output high in idle state; MOSI/MISO pin data valid in even edge , MOSI/MISO pin data change in odd edge */
#define SPI_MODE_3                  (SPI_CFG2_CPOL | SPI_CFG2_CPHA)
/**
 * @}
 */

/**
 * @defgroup SPI_Baud_Rate_Prescaler_Define SPI baudrate prescaler define
 * @{
 */
#define SPI_BR_PCLK1_DIV2            (0UL)                               /*!< SPI baud rate is the pclk1 divided by 2. */
#define SPI_BR_PCLK1_DIV4            (SPI_CFG2_MBR_0)                    /*!< SPI baud rate is the pclk1 clock divided by 4. */
#define SPI_BR_PCLK1_DIV8            (SPI_CFG2_MBR_1)                    /*!< SPI baud rate is the pclk1 clock divided by 8. */
#define SPI_BR_PCLK1_DIV16           (SPI_CFG2_MBR_1 | SPI_CFG2_MBR_0)   /*!< SPI baud rate is the pclk1 clock divided by 16. */
#define SPI_BR_PCLK1_DIV32           (SPI_CFG2_MBR_2)                    /*!< SPI baud rate is the pclk1 clock divided by 32. */
#define SPI_BR_PCLK1_DIV64           (SPI_CFG2_MBR_2 | SPI_CFG2_MBR_0)   /*!< SPI baud rate is the pclk1 clock divided by 64. */
#define SPI_BR_PCLK1_DIV128          (SPI_CFG2_MBR_2 | SPI_CFG2_MBR_1)   /*!< SPI baud rate is the pclk1 clock divided by 128. */
#define SPI_BR_PCLK1_DIV256          (SPI_CFG2_MBR_2 | SPI_CFG2_MBR_1 | SPI_CFG2_MBR_0)  /*!< SPI baud rate is the pclk1 divided by 256. */
/**
 * @}
 */

/**
 * @defgroup SPI_Data_Size_Define SPI data size define
 * @{
 */
#define SPI_DATA_SIZE_4BIT          (0UL)
#define SPI_DATA_SIZE_5BIT          (SPI_CFG2_DSIZE_0)
#define SPI_DATA_SIZE_6BIT          (SPI_CFG2_DSIZE_1)
#define SPI_DATA_SIZE_7BIT          (SPI_CFG2_DSIZE_0 | SPI_CFG2_DSIZE_1)
#define SPI_DATA_SIZE_8BIT          (SPI_CFG2_DSIZE_2)
#define SPI_DATA_SIZE_9BIT          (SPI_CFG2_DSIZE_2 | SPI_CFG2_DSIZE_0)
#define SPI_DATA_SIZE_10BIT         (SPI_CFG2_DSIZE_2 | SPI_CFG2_DSIZE_1)
#define SPI_DATA_SIZE_11BIT         (SPI_CFG2_DSIZE_2 | SPI_CFG2_DSIZE_1 | SPI_CFG2_DSIZE_0)
#define SPI_DATA_SIZE_12BIT         (SPI_CFG2_DSIZE_3)
#define SPI_DATA_SIZE_13BIT         (SPI_CFG2_DSIZE_3 | SPI_CFG2_DSIZE_0)
#define SPI_DATA_SIZE_14BIT         (SPI_CFG2_DSIZE_3 | SPI_CFG2_DSIZE_1)
#define SPI_DATA_SIZE_15BIT         (SPI_CFG2_DSIZE_3 | SPI_CFG2_DSIZE_1 | SPI_CFG2_DSIZE_0)
#define SPI_DATA_SIZE_16BIT         (SPI_CFG2_DSIZE_3 | SPI_CFG2_DSIZE_2)
#define SPI_DATA_SIZE_20BIT         (SPI_CFG2_DSIZE_3 | SPI_CFG2_DSIZE_2 | SPI_CFG2_DSIZE_0)
#define SPI_DATA_SIZE_24BIT         (SPI_CFG2_DSIZE_3 | SPI_CFG2_DSIZE_2 | SPI_CFG2_DSIZE_1)
#define SPI_DATA_SIZE_32BIT         (SPI_CFG2_DSIZE_3 | SPI_CFG2_DSIZE_2 | SPI_CFG2_DSIZE_1 | SPI_CFG2_DSIZE_0)
/**
 * @}
 */

/**
 * @defgroup SPI_First_Bit_Define SPI first bit define
 * @{
 */
#define SPI_FIRST_MSB               (0UL)
#define SPI_FIRST_LSB               (SPI_CFG2_LSBF)
/**
 * @}
 */

#if HAL_USE_SPI || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @brief   Circular mode support flag.
 */
#define SPI_SUPPORTS_CIRCULAR           TRUE

#if !defined(HC32_DMA_REQUIRED)
#define HC32_DMA_REQUIRED
#endif

#if SPI_SELECT_MODE == SPI_SELECT_MODE_LLD
#error "SPI_SELECT_MODE_LLD not supported by this driver"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Low level fields of the SPI driver structure.
 */
#define spi_lld_driver_fields                                               \
  /* pointer to the SPIx registers block.*/                                 \
  M4_SPI_TypeDef            *spi;                                           \
  /* Receive DMA channel.*/                                                 \
  const hc32_dma_channel_t  *dmarx;                                         \
  /* Transmit DMA channel.*/                                                \
  const hc32_dma_channel_t  *dmatx;                                         \
  /* RX DMA mode.*/                                                         \
  dma_channel_mode_t        txdmamode;                                      \
  /* TX DMA mode.*/                                                         \
  dma_channel_mode_t        rxdmamode

/**
 * @brief   Low level fields of the SPI configuration structure.
 */
#define spi_lld_config_fields                                               \
  /* SPI CR1 register initialization data.*/                                \
  uint32_t                  cr1;                                            \
  /* SPI CFG1 register initialization data.*/                               \
  uint32_t                  cfg1;                                           \
  /* SPI CFG2 register initialization data.*/                               \
  uint32_t                  cfg2;

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if HC32_SPI_USE_SPI1 && !defined(__DOXYGEN__)
extern SPIDriver SPID1;
#endif

#if HC32_SPI_USE_SPI2 && !defined(__DOXYGEN__)
extern SPIDriver SPID2;
#endif

#if HC32_SPI_USE_SPI3 && !defined(__DOXYGEN__)
extern SPIDriver SPID3;
#endif

#if HC32_SPI_USE_SPI4 && !defined(__DOXYGEN__)
extern SPIDriver SPID4;
#endif

#if HC32_SPI_USE_SPI5 && !defined(__DOXYGEN__)
extern SPIDriver SPID5;
#endif

#if HC32_SPI_USE_SPI6 && !defined(__DOXYGEN__)
extern SPIDriver SPID6;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void spi_lld_init(void);
  void spi_deinit(M4_SPI_TypeDef *SPIx);
  void spi_lld_start(SPIDriver *spip);
  void spi_lld_stop(SPIDriver *spip);
  void spi_lld_ignore(SPIDriver *spip, size_t n);
  void spi_lld_exchange(SPIDriver *spip, size_t n,
                        const void *txbuf, void *rxbuf);
  void spi_lld_send(SPIDriver *spip, size_t n, const void *txbuf);
  void spi_lld_receive(SPIDriver *spip, size_t n, void *rxbuf);
#if(SPI_SUPPORTS_CIRCULAR == TRUE) || defined(__DOXYGEN__)
  void spi_lld_abort(SPIDriver *spip);
#endif
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_SPI */

#endif /* HAL_SPI_LLD_H */

/** @} */
