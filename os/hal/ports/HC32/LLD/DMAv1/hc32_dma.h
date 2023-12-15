/*
    ChibiOS - Copyright (C) 2022 Radiolink
    Driver by Radiolink Wu, April 2022
*/

/**
 * @file    DMAv1/hc32_dma.h
 * @brief   DMA driver header
 *
 * @addtogroup HC32_DMA
 * @{
 */

#ifndef HC32_DMA_H
#define HC32_DMA_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @brief   Total number of two DMA unit.
 * @details This is the totle number of two DMA unit.
 */
#define HC32_DMA_CHANNELS           16U

/**
 * @brief   Returns an unique numeric identifier for a DMA channel.
 *
 * @param[in] dma       the DMA unit number
 * @param[in] stream    the channel number
 * @return              An unique numeric channel identifier.
 */
#define HC32_DMA_CHANNEL_ID(dma, channel) ((((dma) - 1U) * 8U) + (channel))

/**
 * @brief   Any channels selector.
 */
#define HC32_CHANNEL_ID_ANY         HC32_DMA_CHANNELS

/**
 * @brief   Returns a pointer to a @p hc32_dma_channel_t structure.
 *
 * @param[in] id        the stream numeric identifier
 * @return              A pointer to the @p hc32_dma_channel_t constant structure
 *                      associated to the DMA channel.
 */
#define HC32_DMA_CHANNEL(id)        (&_hc32_dma_channels[id])

/**
 * @brief   the default value of DMA_CHCTLx.
 */
#define HC32_DMA_CHCTL_RESET_VALUE      0x00001000U

/**
 * @brief   the default value of DMA_DTCTLx
 */
#define HC32_DMA_DTCTL_RESET_VALUE      0x00000001U

/**
 * @brief   the bit of block complete interrupt.
 */
#define BIT_BTC_INT_CLR             16

/**
 * @brief   the bit of transfer require error.
 */
#define BIT_REQERR__INT_CLR              16

/**
 * @defgroup DMA_Int_Config DMA interrupt function config
 * @{
 */
#define DMA_INT_ENABLE              (DMA_CHCTL_IE)          /*!< DMA interrupt enable */
#define DMA_INT_DISABLE             (0x00000000UL)          /*!< DMA interrupt disable */
/**
 * @}
 */

/**
 * @defgroup DMA_DataWidth_Sel DMA transfer data width
 * @{
 */
#define DMA_DATAWIDTH_8BIT          (0x00000000UL)          /*!< DMA transfer data width 8bit  */
#define DMA_DATAWIDTH_16BIT         (DMA_CHCTL_HSIZE_0)     /*!< DMA transfer data width 16bit */
#define DMA_DATAWIDTH_32BIT         (DMA_CHCTL_HSIZE_1)     /*!< DMA transfer data width 32bit */
/**
 * @}
 */

/**
 * @defgroup DMA_SrcAddr_Incremented_Mode DMA source address increment mode
 * @{
 */
#define DMA_SRC_ADDR_FIX            (0x00000000UL)          /*!< DMA source address fix             */
#define DMA_SRC_ADDR_INC            (DMA_CHCTL_SINC_0)      /*!< DMA source address increment       */
#define DMA_SRC_ADDR_DEC            (DMA_CHCTL_SINC_1)      /*!< DMA source address decrement       */
/**
 * @}
 */

/**
 * @defgroup DMA_DesAddr_Incremented_Mode DMA destination address increment mode
 * @{
 */
#define DMA_DEST_ADDR_FIX           (0x00000000UL)          /*!< DMA destination address fix        */
#define DMA_DEST_ADDR_INC           (DMA_CHCTL_DINC_0)      /*!< DMA destination address increment  */
#define DMA_DEST_ADDR_DEC           (DMA_CHCTL_DINC_1)      /*!< DMA destination address decrement  */
/**
 * @}
 */

/**
 * @defgroup DMA_Local_Macros DMA Local Macros
 * @{
 */
#define DMA_CH_REG(reg_base, ch)    (*(uint32_t *)((uint32_t)(&(reg_base)) + ((ch) * 0x40UL)))

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   HC32 DMA channel mode structure
 */
typedef struct {
  uint32_t u32IntEn;            /*!< Specifies the DMA interrupt function.              */
  uint32_t u32DataWidth;        /*!< Specifies the DMA transfer data width.             */
  uint32_t u32BlockSize;        /*!< Specifies the DMA block size.                      */
  uint32_t u32TransCnt;         /*!< Specifies the DMA transfer count.                  */
  uint32_t u32SrcInc;           /*!< Specifies the source address increment mode.       */
  uint32_t u32DestInc;          /*!< Specifies the destination address increment mode.  */
  uint32_t u32SrcRptEn;         /*!< Specifies the DMA source repeat function.          */
  uint32_t u32SrcRptSize;       /*!< Specifies the DMA source repeat size.              */
  uint32_t u32DestRptEn;        /*!< Specifies the DMA destination repeat function.     */
  uint32_t u32DestRptSize;      /*!< Specifies the DMA destination repeat size.         */
} dma_channel_mode_t;

/**
 * @brief   HC32 DMA channel descriptor structure.
 */
typedef struct {
  M4_DMA_TypeDef     *dma;          /**< @brief Associated DMA.                                     */
  uint8_t            ch;            /**< @brief Associated DMA channel.                             */
  uint8_t            isr;           /**< @brief Associated DMA channel Interrupt source number.     */
  uint8_t            selfindex;     /**< @brief Index to self in array.                             */
  uint8_t            IRQn;          /**< @brief Associated DMA channel Interrupt vector number.     */
} hc32_dma_channel_t;

/**
 * @brief   HC32 DMA interrupt status.
 */
typedef struct {
  bool REQERR;
  bool TRNERR;
  bool BTC;
  bool TC;
} dma_int_status_t;

/**
 * @brief   HC32 DMA ISR function type.
 *
 * @param[in] p         parameter for the registered function
 * @param[in] flags     pre-shifted content of the xISR register, the bits
 *                      are aligned to bit zero
 */
typedef void (*hc32_dmaisr_t)(void *p, dma_int_status_t flags);

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief       Setup of the source DMA pointer.
 *
 * @param[in] dmachp    point to a hc32_dma_channel_t structure
 * @param[in] addr      the source addr of dma transfer
 */
#define dmaChannelSetSource(dmachp,addr) {                                                  \
  WRITE_REG32(DMA_CH_REG((dmachp)->dma->SAR0, (dmachp)->ch), (uint32_t)(addr));             \
}

/**
 *  @brief      Setup of the destination DMA pointer.
 *
 *  @param[in] dmachp   pointer to hc32_channel_t structure
 *  @param[in] addr     value to written in the address
 *
 *  @special
 */

#define dmaChannelSetDest(dmachp,addr){                                                     \
  WRITE_REG32(DMA_CH_REG((dmachp)->dma->DAR0, (dmachp)->ch), (uint32_t)(addr));             \
}


/**
* @brief        Set the number of transfers to be performed.
*
* @param[in] dmachp     pointer to a hc32_dma_channel_t structure
* @param[in] n          number of transfer
*/
#define dmaChannelSetCounter(dmachp,n) {                                                    \
  __IO uint32_t *DTCTLx;                                                                    \
  DTCTLx = &DMA_CH_REG((dmachp)->dma->DTCTL0, (dmachp)->ch);                                \
  MODIFY_REG32(*DTCTLx,DMA_DTCTL_CNT,((uint32_t)(n) << DMA_DTCTL_CNT_POS));                \
}

/**
 * @brief   Setup of the DMA transfer mode.
 * @param[in] dmachp    pointer to a hc32_dma_channel_t structure
 * @param[in] mode      the DMA transfer
 *
 * @special
 */
__STATIC_INLINE void dmaChannelSetMode(const hc32_dma_channel_t *dmachp,dma_channel_mode_t *ch_mode) {
  __IO uint32_t *CHCTLx;

  WRITE_REG32(DMA_CH_REG(dmachp->dma->DTCTL0,dmachp->ch),(ch_mode->u32BlockSize| \
      (ch_mode->u32TransCnt << DMA_DTCTL_CNT_POS)));

  CHCTLx = &DMA_CH_REG(dmachp->dma->CHCTL0,dmachp->ch);
  MODIFY_REG32(*CHCTLx,                                                            \
      (DMA_CHCTL_SINC | DMA_CHCTL_DINC | DMA_CHCTL_HSIZE | DMA_CHCTL_IE |          \
          DMA_CHCTL_SRPTEN | DMA_CHCTL_DRPTEN),                                    \
      (ch_mode->u32IntEn | ch_mode->u32DataWidth |                                 \
       ch_mode->u32SrcInc | ch_mode->u32DestInc  |                                 \
       ch_mode->u32SrcRptEn | ch_mode->u32DestRptEn));

  WRITE_REG32(DMA_CH_REG(dmachp->dma->RPT0, dmachp->ch),                           \
      ((ch_mode->u32DestRptSize << DMA_RPT_DRPT_POS) | ch_mode->u32SrcRptSize));
}

/**
 * @brief   Enable a DMA channel.
 * parma[i] dmachp pointer to a hc32_dma_channel_t structure
 */
#define dmaChannelEnable(dmachp) {                                                          \
  /* Global setting, Enable or Disable DMA */                                               \
  WRITE_REG32((dmachp)->dma->EN, 1U);                                                       \
                                                                                            \
  /* DMA channel enable */                                                                  \
  WRITE_REG32((dmachp)->dma->CHEN, ((1UL << (dmachp)->ch) & 0xFFUL));                       \
                                                                                            \
}

/**
 * @brief   Disables a DMA channel aborting the current transfer.
 *
 * @param[in] dmachp    pointer to a hc32_dma_channel_t structure
 *
 * @special
 */
#define dmaChannelDisable(dmachp) {                                                         \
                                                                                            \
  WRITE_REG32((dmachp)->dma->CHENCLR, ((1UL << (dmachp)->ch) & 0xFFUL));                    \
  dmaChannelClearInterrupt(dmachp);                                                         \
}

/**
 * @brief   DMA channel interrupt status clear.
 * @note    Clear DMA transfer and error interrupt status.
 *
 * @param[in] dmachp    pointer to a hc32_dma_channel_t structure
 *
 * @special
 */
#define dmaChannelClearInterrupt(dmachp) {                                                                  \
                                                                                                            \
  uint32_t u32TcInt,u32ErrInt;                                                                              \
                                                                                                            \
  /* Clear DMA error interrupt flag.*/                                                                      \
  u32ErrInt = ((1UL << (dmachp)->ch) | (1UL << ((dmachp)->ch + BIT_REQERR__INT_CLR))) & 0xFFFFFFFFUL;       \
  SET_REG32_BIT((dmachp)->dma->INTCLR0, u32ErrInt);                                                         \
                                                                                                            \
  /* Clear DMA transfer complete interrupt flag.*/                                                          \
  u32TcInt = ((1UL << (dmachp)->ch) | (1UL << ((dmachp)->ch + BIT_BTC_INT_CLR))) & 0xFFFFFFFFUL;            \
  SET_REG32_BIT((dmachp)->dma->INTCLR1, u32TcInt);                                                          \
}

/**
 * @brief   Starts a memory to memory operation using the specified channel.
 * @note    The default transfer data mode is "byte to byte" but it can be
 *          changed by specifying extra options in the @p mode parameter.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamFree().
 *
 * @param[in] dmachp    pointer to a hc32_dma_channel_t structure
 * @param[in] mode      this value is implicitly ORed with:
 *                      - @p DMA_SRC_ADDR_INC
 *                      - @p DMA_DEST_ADDR_INC
 *                      - @p DMA_INT_ENABLE
 *                      .
 * @param[in] src       source address
 * @param[in] dst       destination address
 * @param[in] n         number of data units to copy
 */
#define dmaStartMemCopy(dmachp, mode, src, dest) {                                                           \
  dmaSetTriggerSrc((dmachp),EVT_AOS_STRG);                                                                   \
  dmaChannelSetSource((dmachp),(uint32_t)(src));                                                             \
  dmaChannelSetDest((dmachp),(uint32_t)(dest));                                                              \
                                                                                                             \
  mode.u32IntEn     = DMA_INT_ENABLE;                                                                        \
  mode.u32TransCnt  =(1UL);                                                                                  \
  mode.u32DestInc   =DMA_DEST_ADDR_INC;                                                                      \
  mode.u32SrcInc    =DMA_SRC_ADDR_INC;                                                                       \
  dmaChannelSetMode(dmachp,&mode);                                                                           \
                                                                                                             \
  dmaChannelEnable(dmachp);                                                                                  \
  WRITE_REG32(bM4_AOS->INTSFTTRG_b.STRG, 1U);                                                                \
}

/**
 * @brief   Polled wait for DMA transfer end.
 * @pre     The stream must have been allocated using @p dmaChannelAllocI().
 * @post    After use the channel can be released using @p dmaChannelFreeI().
 *
 * @param[in] dmastp    pointer to a hc32_dma_channel_t structure
 */
#define dmaWaitCompletion(dmachp) {                                         \
  while((dmachp)->dma->CHEN & ((1UL << (dmachp)->ch) & 0xFFUL));            \
  dmaChannelClearInterrupt(dmachp)                                          \
}

/**
 * @brief   Config DMA transfer trigger source.
 *
 * @param[in] dmachp    pointer to a hc32_dma_channel_t structure
 * @parma[in] enSrc     DMA transfer trigger source.
 *             @arg     This parameter can be en_envent_src_t
 *
 */
__STATIC_INLINE void dmaSetTriggerSrc(const hc32_dma_channel_t *dmachp,en_event_src_t enSrc) {                    \
  __IO uint32_t *TRGSELx;                                                                                   \
                                                                                                            \
  if(M4_DMA1 == (dmachp)->dma) {                                                                            \
    TRGSELx = (uint32_t *)((uint32_t)(&M4_AOS->DMA1_TRGSEL0) + (dmachp)->ch*4UL);                           \
  }                                                                                                         \
  else {                                                                                                    \
    TRGSELx = (uint32_t *)((uint32_t)(&M4_AOS->DMA2_TRGSEL0) + (dmachp)->ch*4UL);                           \
  }                                                                                                         \
  MODIFY_REG32(*TRGSELx, AOS_DMA1_TRGSEL_TRGSEL, enSrc);                                                    \
}
/** @} */

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if !defined(__DOXYGEN__)
extern const hc32_dma_channel_t _hc32_dma_channels[HC32_DMA_CHANNELS];
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void dmaInit(void);
  const hc32_dma_channel_t *dmaChannelAllocI(uint32_t id,
                          uint32_t priority,
                          hc32_dmaisr_t func,
                          void *param);
  void dmaChannelFreeI(const hc32_dma_channel_t *dmachp);
  void dmaBtcEnable(const hc32_dma_channel_t *dmachp, uint32_t priority);
#ifdef __cplusplus
}
#endif

#endif /* HC32_DMA_H */

/** @} */
