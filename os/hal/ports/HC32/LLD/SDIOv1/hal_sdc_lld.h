/*
    ChibiOS - Copyright (C) 2022 Radiolink
    Driver by Radiolink dingchao, August 2022
*/

/**
 * @file    SDIOv1/hal_sdc_lld.h
 * @brief   SDIO driver header
 *
 * @addtogroup HC32_SDIO
 * @{
 */

#ifndef HAL_SDC_LLD_H
#define HAL_SDC_LLD_H

#if HAL_USE_SDC || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*
 * The following definitions are missing from some implementations, fixing
 * as zeroed masks.
 */
#if !defined(SDIO_STA_STBITERR)
#define SDIO_STA_STBITERR       0
#endif

#if !defined(SDIO_ICR_STBITERRC)
#define SDIO_ICR_STBITERRC      0
#endif

#if !defined(SDIO_ICR_CEATAENDC)
#define SDIO_ICR_CEATAENDC      0
#endif

#if !defined(SDIO_MASK_STBITERRIE)
#define SDIO_MASK_STBITERRIE    0
#endif

#if !defined(SDIO_USE_BOUNCEBUFFER)
#define SDIO_USE_BOUNCEBUFFER	FALSE
#endif

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   SDIO DMA priority (0..3|lowest..highest).
 */
#if !defined(HC32_SDC_SDIO_DMA_PRIORITY) || defined(__DOXYGEN__)
#define HC32_SDC_SDIO_DMA_PRIORITY         3
#endif

/**
 * @brief   SDIO interrupt priority level setting.
 */
#if !defined(HC32_SDC_SDIO_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define HC32_SDC_SDIO_IRQ_PRIORITY         9
#endif

/**
 * @brief   Enable clock bypass.
 * @note    Allow clock speed up to 50 Mhz.
 */
#if !defined(HC32_SDC_SDIO_50MHZ) || defined(__DOXYGEN__)
#define HC32_SDC_SDIO_50MHZ                FALSE
#endif

/**
 * @brief   Write timeout in milliseconds.
 */
#if !defined(HC32_SDC_WRITE_TIMEOUT_MS) || defined(__DOXYGEN__)
#define HC32_SDC_WRITE_TIMEOUT_MS          1000
#endif

/**
 * @brief   Read timeout in milliseconds.
 */
#if !defined(HC32_SDC_READ_TIMEOUT_MS) || defined(__DOXYGEN__)
#define HC32_SDC_READ_TIMEOUT_MS           1000
#endif

/**
 * @brief   Card clock activation delay in milliseconds.
 */
#if !defined(HC32_SDC_CLOCK_ACTIVATION_DELAY) || defined(__DOXYGEN__)
#define HC32_SDC_CLOCK_ACTIVATION_DELAY    10
#endif

/**
 * @brief   Support for unaligned transfers.
 * @note    Unaligned transfers are much slower.
 */
#if !defined(HC32_SDC_SDIO_UNALIGNED_SUPPORT) || defined(__DOXYGEN__)
#define HC32_SDC_SDIO_UNALIGNED_SUPPORT    TRUE
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if !OSAL_IRQ_IS_VALID_PRIORITY(HC32_SDC_SDIO_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to SDIO"
#endif

#if !defined(HC32_DMA_REQUIRED)
#define HC32_DMA_REQUIRED
#endif



/*
 * HC32 define
 */

#ifndef __IO
    #define     __IO    volatile
#endif

/*!< Get the specified register address of the specified SDIOC unit */
#define SDIOC_ARG(__UNIT__)                     ((uint32_t)(&((__UNIT__)->ARG0)))
#define SDIOC_BUF(__UNIT__)                     ((uint32_t)(&((__UNIT__)->BUF0)))
#define SDIOC_RESPx(__UNIT__, RESP_REG)         ((uint32_t)(&((__UNIT__)->RESP0)) + (uint32_t)(RESP_REG))

/* SDIOC NORINTSGEN register Mask */
#define SDIOC_NORINTSGEN_CLEAR_MASK             (0x01F7U)
/* SDIOC ERRINTSGEN register Mask */
#define SDIOC_ERRINTSGEN_CLEAR_MASK             (0x017FU)

/**
 * @defgroup SDIOC_Mode SDIOC Mode
 * @{
 */
#define SDIOC_MODE_SD                           (0x00UL)              /*!< SDIOCx selects SD mode  */
#define SDIOC_MODE_MMC                          (0x01UL)              /*!< SDIOCx selects MMC mode */
/**
 * @}
 */

/**
 * @defgroup SDIOC_Card_Detect_Select SDIOC Card Detect Select
 * @{
 */
#define SDIOC_CARD_DETECT_CD_PIN_LEVEL          (0x00U)               /*!< SDIOCx_CD(x=1~2) line is selected (for normal use)       */
#define SDIOC_CARD_DETECT_TEST_SIGNAL           (SDIOC_HOSTCON_CDSS)  /*!< The Card Detect Test Level is selected(for test purpose) */
/**
 * @}
 */

/**
 * @defgroup SDIOC_Bus_Width SDIOC Bus Width
 * @{
 */
#define SDIOC_BUS_WIDTH_1BIT                    (0x00U)               /*!< The Bus width is 1 bit */
#define SDIOC_BUS_WIDTH_4BIT                    (SDIOC_HOSTCON_DW)    /*!< The Bus width is 4 bit */
#define SDIOC_BUS_WIDTH_8BIT                    (SDIOC_HOSTCON_EXDW)  /*!< The Bus width is 8 bit */
/**
 * @}
 */

/**
 * @defgroup SDIOC_Speed_Mode SDIOC Speed Mode
 * @{
 */
#define SDIOC_SPEED_MODE_NORMAL                 (0x00U)               /*!< Normal speed mode */
#define SDIOC_SPEED_MODE_HIGH                   (SDIOC_HOSTCON_HSEN)  /*!< High speed mode   */
/**
 * @}
 */

/*
 * SDIO clock divider.
 */
#if 1

#define SDIOC_CLOCK_DIV_1                       (0x00U)               /*!< PCLK1/1   */
#define SDIOC_CLOCK_DIV_2                       (SDIOC_CLKCON_FS_0)   /*!< PCLK1/2   */
#define SDIOC_CLOCK_DIV_4                       (SDIOC_CLKCON_FS_1)   /*!< PCLK1/4   */
#define SDIOC_CLOCK_DIV_8                       (SDIOC_CLKCON_FS_2)   /*!< PCLK1/8   */
#define SDIOC_CLOCK_DIV_16                      (SDIOC_CLKCON_FS_3)   /*!< PCLK1/16  */
#define SDIOC_CLOCK_DIV_32                      (SDIOC_CLKCON_FS_4)   /*!< PCLK1/32  */
#define SDIOC_CLOCK_DIV_64                      (SDIOC_CLKCON_FS_5)   /*!< PCLK1/64  */
#define SDIOC_CLOCK_DIV_128                     (SDIOC_CLKCON_FS_6)   /*!< PCLK1/128 */
#define SDIOC_CLOCK_DIV_256                     (SDIOC_CLKCON_FS_7)   /*!< PCLK1/256 */

#define HC32_SDIO_DIV_HS                        SDIOC_CLOCK_DIV_2    //PCLK1 MAX 60MHz / 2
#define HC32_SDIO_DIV_HLS                       SDIOC_CLOCK_DIV_4    //不支持高速模式的卡配置
#define HC32_SDIO_DIV_LS                        SDIOC_CLOCK_DIV_256     //

#endif

/**
 * @defgroup SDIOC_Command_Type SDIOC Command Type
 * @{
 */
#define SDIOC_CMD_TYPE_NORMAL                   (0x00U)               /*!< Other commands                               */
#define SDIOC_CMD_TYPE_SUSPEND                  (SDIOC_CMD_TYP_0)     /*!< CMD52 for writing "Bus Suspend" in CCCR      */
#define SDIOC_CMD_TYPE_RESUME                   (SDIOC_CMD_TYP_1)     /*!< CMD52 for writing "Function Select" in CCCR  */
#define SDIOC_CMD_TYPE_ABORT                    (SDIOC_CMD_TYP)       /*!< CMD12, CMD52 for writing "I/O Abort" in CCCR */
/**
 * @}
 */

/**
 * @defgroup SDIOC_Data_Line_Valid SDIOC Data Line Valid
 * @{
 */
#define SDIOC_DATA_LINE_DISABLE                 (0x00U)               /*!< The current command uses only SDIOCx_CMD(x=1~2) command line       */
#define SDIOC_DATA_LINE_ENABLE                  (SDIOC_CMD_DAT)       /*!< The current command requires the use of SDIOCx_Dy(x=1~2) data line */
/**
 * @}
 */

/**
 * @defgroup SDIOC_Response_Type SDIOC Response Type
 * @{
 */
#define SDIOC_RESOPNE_TYPE_NO                   (0x00U)                                               /*!< No Response                        */
#define SDIOC_RESOPNE_TYPE_R2                   (SDIOC_CMD_RESTYP_0 | SDIOC_CMD_CCE)                  /*!< Command Response 2                 */
#define SDIOC_RESOPNE_TYPE_R3_R4                (SDIOC_CMD_RESTYP_1)                                  /*!< Command Response 3, 4              */
#define SDIOC_RESOPNE_TYPE_R1_R5_R6_R7          (SDIOC_CMD_RESTYP_1 | SDIOC_CMD_ICE | SDIOC_CMD_CCE)  /*!< Command Response 1, 5, 6, 7        */
#define SDIOC_RESOPNE_TYPE_R1B_R5B              (SDIOC_CMD_RESTYP   | SDIOC_CMD_ICE | SDIOC_CMD_CCE)  /*!< Command Response 1 and 5 with busy */
/**
 * @}
 */

/**
 * @defgroup SDIOC_Normal_Error_Interrupt_Status SDIOC Normal Error Interrupt Status
 * @{
 */
#define SDIOC_NORMAL_INT_FLAG_EI                (SDIOC_NORINTST_EI)     /*!< Error Interrupt Status     */
#define SDIOC_NORMAL_INT_FLAG_CINT              (SDIOC_NORINTST_CINT)   /*!< Card Interrupt status      */
#define SDIOC_NORMAL_INT_FLAG_CRM               (SDIOC_NORINTST_CRM)    /*!< Card Removal status        */
#define SDIOC_NORMAL_INT_FLAG_CIST              (SDIOC_NORINTST_CIST)   /*!< Card Insertion status      */
#define SDIOC_NORMAL_INT_FLAG_BRR               (SDIOC_NORINTST_BRR)    /*!< Buffer Read Ready status   */
#define SDIOC_NORMAL_INT_FLAG_BWR               (SDIOC_NORINTST_BWR)    /*!< Buffer Write Ready status  */
#define SDIOC_NORMAL_INT_FLAG_BGE               (SDIOC_NORINTST_BGE)    /*!< Block Gap Event status     */
#define SDIOC_NORMAL_INT_FLAG_TC                (SDIOC_NORINTST_TC)     /*!< Transfer Complete status   */
#define SDIOC_NORMAL_INT_FLAG_CC                (SDIOC_NORINTST_CC)     /*!< Command Complete status    */
#define SDIOC_ERROR_INT_FLAG_ACE                ((uint32_t)SDIOC_ERRINTST_ACE  << 16U)  /*!< Auto CMD12 Error Status      */
#define SDIOC_ERROR_INT_FLAG_DEBE               ((uint32_t)SDIOC_ERRINTST_DEBE << 16U)  /*!< Data End Bit Error status    */
#define SDIOC_ERROR_INT_FLAG_DCE                ((uint32_t)SDIOC_ERRINTST_DCE  << 16U)  /*!< Data CRC Error status        */
#define SDIOC_ERROR_INT_FLAG_DTOE               ((uint32_t)SDIOC_ERRINTST_DTOE << 16U)  /*!< Data Timeout Error status    */
#define SDIOC_ERROR_INT_FLAG_CIE                ((uint32_t)SDIOC_ERRINTST_CIE  << 16U)  /*!< Command Index Error status   */
#define SDIOC_ERROR_INT_FLAG_CEBE               ((uint32_t)SDIOC_ERRINTST_CEBE << 16U)  /*!< Command End Bit Error status */
#define SDIOC_ERROR_INT_FLAG_CCE                ((uint32_t)SDIOC_ERRINTST_CCE  << 16U)  /*!< Command CRC Error status     */
#define SDIOC_ERROR_INT_FLAG_CTOE               ((uint32_t)SDIOC_ERRINTST_CTOE << 16U)  /*!< Command Timeout Error status */
#define SDIOC_ERROR_INT_STATIC_FLAGS            ((uint32_t)SDIOC_ERROR_INT_FLAG_ACE | SDIOC_ERROR_INT_FLAG_DEBE | \
                                                           SDIOC_ERROR_INT_FLAG_DCE | SDIOC_ERROR_INT_FLAG_DTOE | \
                                                           SDIOC_ERROR_INT_FLAG_CIE | SDIOC_ERROR_INT_FLAG_CEBE | \
                                                           SDIOC_ERROR_INT_FLAG_CCE | SDIOC_ERROR_INT_FLAG_CTOE | \
                                                           SDIOC_NORMAL_INT_FLAG_TC | SDIOC_NORMAL_INT_FLAG_CC)
/**
 * @}
 */

/**
 * @defgroup SDIOC_Normal_Error_Interrupt SDIOC Normal Error Interrupt
 * @{
 */
#define SDIOC_NORMAL_INT_CINTSEN                (SDIOC_NORINTSGEN_CINTSEN)   /*!< Card Interrupt                */
#define SDIOC_NORMAL_INT_CRMSEN                 (SDIOC_NORINTSGEN_CRMSEN)    /*!< Card Removal Interrupt        */
#define SDIOC_NORMAL_INT_CISTSEN                (SDIOC_NORINTSGEN_CISTSEN)   /*!< Card Insertion Interrupt      */
#define SDIOC_NORMAL_INT_BRRSEN                 (SDIOC_NORINTSGEN_BRRSEN)    /*!< Buffer Read Ready Interrupt   */
#define SDIOC_NORMAL_INT_BWRSEN                 (SDIOC_NORINTSGEN_BWRSEN)    /*!< Buffer Write Ready Interrupt  */
#define SDIOC_NORMAL_INT_BGESEN                 (SDIOC_NORINTSGEN_BGESEN)    /*!< Block Gap Event Interrupt     */
#define SDIOC_NORMAL_INT_TCSEN                  (SDIOC_NORINTSGEN_TCSEN)     /*!< Transfer Complete Interrupt   */
#define SDIOC_NORMAL_INT_CCSEN                  (SDIOC_NORINTSGEN_CCSEN)     /*!< Command Complete Interrupt    */
#define SDIOC_ERROR_INT_ACESEN                  ((uint32_t)SDIOC_ERRINTSGEN_ACESEN  << 16U)   /*!< Auto CMD12 Error Interrupt      */
#define SDIOC_ERROR_INT_DEBESEN                 ((uint32_t)SDIOC_ERRINTSGEN_DEBESEN << 16U)   /*!< Data End Bit Error Interrupt    */
#define SDIOC_ERROR_INT_DCESEN                  ((uint32_t)SDIOC_ERRINTSGEN_DCESEN  << 16U)   /*!< Data CRC Error Interrupt        */
#define SDIOC_ERROR_INT_DTOESEN                 ((uint32_t)SDIOC_ERRINTSGEN_DTOESEN << 16U)   /*!< Data Timeout Error Interrupt    */
#define SDIOC_ERROR_INT_CIESEN                  ((uint32_t)SDIOC_ERRINTSGEN_CIESEN  << 16U)   /*!< Command Index Error Interrupt   */
#define SDIOC_ERROR_INT_CEBESEN                 ((uint32_t)SDIOC_ERRINTSGEN_CEBESEN << 16U)   /*!< Command End Bit Error Interrupt */
#define SDIOC_ERROR_INT_CCESEN                  ((uint32_t)SDIOC_ERRINTSGEN_CCESEN  << 16U)   /*!< Command CRC Error Interrupt     */
#define SDIOC_ERROR_INT_CTOESEN                 ((uint32_t)SDIOC_ERRINTSGEN_CTOESEN << 16U)   /*!< Command Timeout Error Interrupt */
/**
 * @}
 */

/*使能全部中断标志*/
#define HC32_SDIO_INT_ALL_EN ((uint32_t)SDIOC_NORMAL_INT_CINTSEN | (uint32_t)SDIOC_NORMAL_INT_CRMSEN | \
                              (uint32_t)SDIOC_NORMAL_INT_CISTSEN | (uint32_t)SDIOC_NORMAL_INT_BRRSEN | \
                              (uint32_t)SDIOC_NORMAL_INT_BWRSEN  | (uint32_t)SDIOC_NORMAL_INT_BGESEN | \
                              (uint32_t)SDIOC_NORMAL_INT_TCSEN   | (uint32_t)SDIOC_NORMAL_INT_CCSEN  | \
                              SDIOC_ERROR_INT_ACESEN | SDIOC_ERROR_INT_DEBESEN | \
                              SDIOC_ERROR_INT_DCESEN | SDIOC_ERROR_INT_DTOESEN | \
                              SDIOC_ERROR_INT_CIESEN | SDIOC_ERROR_INT_CEBESEN | \
                              SDIOC_ERROR_INT_CCESEN | SDIOC_ERROR_INT_CTOESEN)

/**
 * @brief Value to clear all interrupts flag at once.
 */
#define HC32_SDIO_ICR_ALL_FLAGS (SDIOC_NORMAL_INT_FLAG_EI | SDIOC_NORMAL_INT_FLAG_CINT | \
                                 SDIOC_NORMAL_INT_FLAG_CRM | SDIOC_NORMAL_INT_FLAG_CIST | \
                                 SDIOC_NORMAL_INT_FLAG_BRR | SDIOC_NORMAL_INT_FLAG_BWR | \
                                 SDIOC_NORMAL_INT_FLAG_BGE | SDIOC_NORMAL_INT_FLAG_TC | \
                                 SDIOC_NORMAL_INT_FLAG_CC | SDIOC_ERROR_INT_FLAG_ACE | \
                                 SDIOC_ERROR_INT_FLAG_DEBE | SDIOC_ERROR_INT_FLAG_DCE | \
                                 SDIOC_ERROR_INT_FLAG_DTOE | SDIOC_ERROR_INT_FLAG_CIE | \
                                 SDIOC_ERROR_INT_FLAG_CEBE | SDIOC_ERROR_INT_FLAG_CCE | \
                                 SDIOC_ERROR_INT_FLAG_CTOE)

/**
 * @brief Mask of error flags in STA register.
 */
#define STM32_SDIO_STA_ERROR_MASK (SDIO_STA_CCRCFAIL | SDIO_STA_DCRCFAIL |  \
                                   SDIO_STA_CTIMEOUT | SDIO_STA_DTIMEOUT |  \
                                   SDIO_STA_TXUNDERR | SDIO_STA_RXOVERR)


/**
 * @defgroup SDIOC_Transfer_Direction SDIOC Transfer Direction
 * @{
 */
#define SDIOC_TRANSFER_DIR_TO_CARD              (0x00U)                 /*!< Write (Host to Card) */
#define SDIOC_TRANSFER_DIR_TO_HOST              (SDIOC_TRANSMODE_DDIR)  /*!< Read (Card to Host)  */
/**
 * @}
 */

/**
 * @defgroup SDIOC_Auto_Send_CMD12 SDIOC Auto Send CMD12
 * @{
 */
#define SDIOC_AUTO_SEND_CMD12_DISABLE           (0x00U)                    /*!< Do not send autocommands                                   */
#define SDIOC_AUTO_SEND_CMD12_ENABLE            (SDIOC_TRANSMODE_ATCEN_0)  /*!< CMD12 is automatically sent after multiple block transfers */
/**
 * @}
 */

/**
 * @defgroup SDIOC_Transfer_Mode SDIOC Transfer Mode
 * @{
 */
#define SDIOC_TRANSFER_MODE_SINGLE              (0x00U)                                       /*!< Single Block transfer        */
#define SDIOC_TRANSFER_MODE_INFINITE            (SDIOC_TRANSMODE_MULB)                        /*!< Infinite Block transfer      */
#define SDIOC_TRANSFER_MODE_MULTIPLE            (SDIOC_TRANSMODE_MULB | SDIOC_TRANSMODE_BCE)  /*!< Multiple Block transfer      */
#define SDIOC_TRANSFER_MODE_STOP_MULTIPLE       (0x8000U | SDIOC_TRANSFER_MODE_MULTIPLE)      /*!< Stop Multiple Block transfer */
/**
 * @}
 */

/**
 * @defgroup SDIOC_Data_Timeout_Time SDIOC Data Timeout Time
 * @{
 */
#define SDIOC_DATA_TIMEOUT_CLK_2_13             (0x00U)  /*!< Timeout time: PCLK1*2^13 */
#define SDIOC_DATA_TIMEOUT_CLK_2_14             (0x01U)  /*!< Timeout time: PCLK1*2^14 */
#define SDIOC_DATA_TIMEOUT_CLK_2_15             (0x02U)  /*!< Timeout time: PCLK1*2^15 */
#define SDIOC_DATA_TIMEOUT_CLK_2_16             (0x03U)  /*!< Timeout time: PCLK1*2^16 */
#define SDIOC_DATA_TIMEOUT_CLK_2_17             (0x04U)  /*!< Timeout time: PCLK1*2^17 */
#define SDIOC_DATA_TIMEOUT_CLK_2_18             (0x05U)  /*!< Timeout time: PCLK1*2^18 */
#define SDIOC_DATA_TIMEOUT_CLK_2_19             (0x06U)  /*!< Timeout time: PCLK1*2^19 */
#define SDIOC_DATA_TIMEOUT_CLK_2_20             (0x07U)  /*!< Timeout time: PCLK1*2^20 */
#define SDIOC_DATA_TIMEOUT_CLK_2_21             (0x08U)  /*!< Timeout time: PCLK1*2^21 */
#define SDIOC_DATA_TIMEOUT_CLK_2_22             (0x09U)  /*!< Timeout time: PCLK1*2^22 */
#define SDIOC_DATA_TIMEOUT_CLK_2_23             (0x0AU)  /*!< Timeout time: PCLK1*2^23 */
#define SDIOC_DATA_TIMEOUT_CLK_2_24             (0x0BU)  /*!< Timeout time: PCLK1*2^24 */
#define SDIOC_DATA_TIMEOUT_CLK_2_25             (0x0CU)  /*!< Timeout time: PCLK1*2^25 */
#define SDIOC_DATA_TIMEOUT_CLK_2_26             (0x0DU)  /*!< Timeout time: PCLK1*2^26 */
#define SDIOC_DATA_TIMEOUT_CLK_2_27             (0x0EU)  /*!< Timeout time: PCLK1*2^27 */

#define SDIOC_DATA_TIMEOUT_DISABLE              (0x0FU)  //禁止设定
/**
 * @}
 */

/**
 * @defgroup SDIOC_Software_Reset_Type SDIOC_Software_Reset_Type
 * @{
 */
#define SDIOC_SW_RESET_DATA_LINE                (SDIOC_SFTRST_RSTD)  /*!< Only part of data circuit is reset                                     */
#define SDIOC_SW_RESET_CMD_LINE                 (SDIOC_SFTRST_RSTC)  /*!< Only part of command circuit is reset                                  */
#define SDIOC_SW_RESET_ALL                      (SDIOC_SFTRST_RSTA)  /*!< Reset the entire Host Controller except for the card detection circuit */
/**
 * @}
 */

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of card flags.
 */
typedef uint32_t sdcmode_t;

/**
 * @brief   SDC Driver condition flags type.
 */
typedef uint32_t sdcflags_t;

/**
 * @brief   Type of a structure representing an SDC driver.
 */
typedef struct SDCDriver SDCDriver;

/**
 * @brief   Driver configuration structure.
 * @note    It could be empty on some architectures.
 */
typedef struct {
  /**
   * @brief   Working area for memory consuming operations.
   * @note    Buffer must be word aligned and big enough to store 512 bytes.
   * @note    It is mandatory for detecting MMC cards bigger than 2GB else it
   *          can be @p NULL. SD cards do NOT need it.
   * @note    Memory pointed by this buffer is only used by @p sdcConnect(),
   *          afterward it can be reused for other purposes.
   */
  uint8_t       *scratchpad;
  /**
   * @brief   Bus width.
   */
  sdcbusmode_t  bus_width;

  /* End of the mandatory fields.*/

  /**
   * @brief bus slowdown
   * This is an additional slowdown applied to high speed bus operation
   */
  uint8_t slowdown;
} SDCConfig;

/**
 * @brief   @p SDCDriver specific methods.
 */
#define _sdc_driver_methods                                                 \
  _mmcsd_block_device_methods

/**
 * @extends MMCSDBlockDeviceVMT
 *
 * @brief   @p SDCDriver virtual methods table.
 */
struct SDCDriverVMT {
  _sdc_driver_methods
};

/**
 * @brief   Structure representing an SDC driver.
 */
struct SDCDriver {
  /**
   * @brief Virtual Methods Table.
   */
  const struct SDCDriverVMT *vmt;
  _mmcsd_block_device_data
  /**
   * @brief Current configuration data.
   */
  const SDCConfig           *config;
  /**
   * @brief Various flags regarding the mounted card.
   */
  sdcmode_t                 cardmode;
  /**
   * @brief Errors flags.
   */
  sdcflags_t                errors;
  /**
   * @brief Card RCA.
   */
  uint32_t                  rca;
  /* End of the mandatory fields.*/
  /**
   * @brief Thread waiting for I/O completion IRQ.
   */
  thread_reference_t        thread;
  /**
   * @brief     DMA mode bit mask.
   */
  dma_channel_mode_t                  dmamode;
  /**
   * @brief     Transmit DMA channel.
   */
  const hc32_dma_channel_t  *dma;
  /**
   * @brief     Pointer to the SDIO registers block.
   * @note      Needed for debugging aid.
   */
  M4_SDIOC_TypeDef              *sdio;
  /**
   * @brief   Buffer for internal operations.
   */
  uint8_t                   buf[MMCSD_BLOCK_SIZE];

  // bouncebuffer to support DMA to all memory regions
  struct bouncebuffer_t *bouncebuffer;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if !defined(__DOXYGEN__)
extern SDCDriver SDCD1;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void sdc_lld_init(void);
  void sdc_lld_start(SDCDriver *sdcp);
  void sdc_lld_stop(SDCDriver *sdcp);
  void sdc_lld_start_clk(SDCDriver *sdcp);
  void sdc_lld_set_data_clk(SDCDriver *sdcp, sdcbusclk_t clk);
  void sdc_lld_stop_clk(SDCDriver *sdcp);
  void sdc_lld_set_bus_mode(SDCDriver *sdcp, sdcbusmode_t mode);
  void sdc_lld_send_cmd_none(SDCDriver *sdcp, uint8_t cmd, uint32_t arg);
  bool sdc_lld_send_cmd_short(SDCDriver *sdcp, uint8_t cmd, uint32_t arg,
                              uint32_t *resp);
  bool sdc_lld_send_cmd_short_crc(SDCDriver *sdcp, uint8_t cmd, uint32_t arg,
                                  uint32_t *resp);
  bool sdc_lld_send_cmd_long_crc(SDCDriver *sdcp, uint8_t cmd, uint32_t arg,
                                 uint32_t *resp);
  bool sdc_lld_read_special(SDCDriver *sdcp, uint8_t *buf, size_t bytes,
                            uint8_t cmd, uint32_t argument);
  bool sdc_lld_read(SDCDriver *sdcp, uint32_t startblk,
                    uint8_t *buf, uint32_t blocks);
  bool sdc_lld_write(SDCDriver *sdcp, uint32_t startblk,
                     const uint8_t *buf, uint32_t blocks);
  bool sdc_lld_sync(SDCDriver *sdcp);
  bool sdc_lld_is_card_inserted(SDCDriver *sdcp);
  bool sdc_lld_is_write_protected(SDCDriver *sdcp);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_SDC */

#endif /* HAL_SDC_LLD_H */

/** @} */
