/*
    ChibiOS - Copyright (C) 2022 Radiolink
    Driver by Radiolink Wu, June 2022
*/

/**
 * @file    OTGv1/hal_usb_lld.h
 * @brief   HC32 USB subsystem low level driver header.
 *
 * @addtogroup USB
 * @{
 */

#ifndef HAL_USB_LLD_H
#define HAL_USB_LLD_H

#if HAL_USE_USB || defined(__DOXYGEN__)

#include "hc32_otg.h"

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/
#define hc32_otg_t                          HD_USB_REGS
#define OTG_FS_ADDR                         0x40080000UL
#define HC32_OTG1_FIFO_MEM_SIZE             640

/**
 * @brief   Status stage handling method.
 */
#define USB_EP0_STATUS_STAGE                USB_EP0_STATUS_STAGE_SW

/**
 * @brief   The address can be changed immediately upon packet reception.
 */
#define USB_SET_ADDRESS_MODE                USB_EARLY_SET_ADDRESS

/**
 * @brief   Method for set address acknowledge.
 */
#define USB_SET_ADDRESS_ACK_HANDLING        USB_SET_ADDRESS_ACK_SW

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

//The bit of the diepint/doepint
#define XFER_COMPL        1ul
#define EPDISABLED        1ul<<1
#define TIME_OUT          1ul<<3
#define SETUP_BIT         1ul<<3
#define INTKNTXFEMP       1ul<<4
#define INEPNAKEFF        1ul<<6
#define TXFEMP            1ul<<7

//The bit of the GINTSTS
#define MODEMIS_INT       1ul<<1
#define SOF_INT           1ul<<3
#define RXFLVL_INT        1ul<<4
#define USBSUSP_INT       1ul<<11
#define USBRST_INT        1ul<<12
#define ENUMDONE_INT      1ul<<13
#define INEP_INT          1ul<<18
#define OUTEP_INT         1ul<<19
#define INCOMPLSOIN       1ul<<20
#define INCOMPLSOOUT      1ul<<21
#define VBUSV_INT         1ul<<30
#define WAKEUP_INT        1ul<<31

/**
 * @defgroup CLK_USB_CLK_Sel USB clock selection
 * @{
 */
#define CLK_USB_CLK_MCLK_DIV2       (0x01U << CMU_USBCKCFGR_USBCKS_POS)
#define CLK_USB_CLK_MCLK_DIV3       (0x02U << CMU_USBCKCFGR_USBCKS_POS)
#define CLK_USB_CLK_MCLK_DIV4       (0x03U << CMU_USBCKCFGR_USBCKS_POS)
#define CLK_USB_CLK_MCLK_DIV5       (0x04U << CMU_USBCKCFGR_USBCKS_POS)
#define CLK_USB_CLK_MCLK_DIV6       (0x05U << CMU_USBCKCFGR_USBCKS_POS)
#define CLK_USB_CLK_MCLK_DIV7       (0x06U << CMU_USBCKCFGR_USBCKS_POS)
#define CLK_USB_CLK_MCLK_DIV8       (0x07U << CMU_USBCKCFGR_USBCKS_POS)
#define CLK_USB_CLK_PLLHQ           (0x08U << CMU_USBCKCFGR_USBCKS_POS)
#define CLK_USB_CLK_PLLHR           (0x09U << CMU_USBCKCFGR_USBCKS_POS)
#define CLK_USB_CLK_PLLAP           (0x0AU << CMU_USBCKCFGR_USBCKS_POS)
#define CLK_USB_CLK_PLLAQ           (0x0BU << CMU_USBCKCFGR_USBCKS_POS)
#define CLK_USB_CLK_PLLAR           (0x0CU << CMU_USBCKCFGR_USBCKS_POS)
/**
 * @}
 */

#define STS_GOUT_NAK                           (1u)
#define STS_DATA_UPDT                          (2u)
#define STS_XFER_COMP                          (3u)
#define STS_SETUP_COMP                         (4u)
#define STS_SETUP_UPDT                         (6u)

#define EP_TYPE_CTRL                           (0u)
#define EP_TYPE_ISOC                           (1u)
#define EP_TYPE_BULK                           (2u)
#define EP_TYPE_INTR                           (3u)
#define EP_TYPE_MSK                            (3u)

/**
 *******************************************************************************
 ** \brief Following macro definations are for reading, writing or modifying the
 **        regsters.
 ******************************************************************************/
#define HD_USB_RDREG32(reg)  (*(__IO uint32_t *)(reg))
#define HD_USB_WRREG32(reg,value) (*(__IO uint32_t *)(reg) = (value))
#define HD_USB_MDFREG32(reg,clear_mask,set_mask) (HD_USB_WRREG32((reg), (((HD_USB_RDREG32((reg))) & ~(clear_mask)) | (set_mask))))

#define USB_MAX_ENDPOINTS                   HC32_OTG1_ENDPOINTS

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Peripheral-specific parameters block.
 */
typedef struct {
  uint32_t                      rx_fifo_size;
  uint32_t                      otg_ram_size;
  uint8_t                       num_endpoints;
} hc32_otg_params_t;

/**
 * @brief   Type of an IN endpoint state structure.
 */
typedef struct {
  /**
   * @brief   Requested transmit transfer size.
   */
  size_t                        txsize;
  /**
   * @brief   Transmitted bytes so far.
   */
  size_t                        txcnt;
  /**
   * @brief   Pointer to the transmission linear buffer.
   */
  const uint8_t                 *txbuf;
#if (USB_USE_WAIT == TRUE) || defined(__DOXYGEN__)
  /**
   * @brief   Waiting thread.
   */
  thread_reference_t            thread;
#endif
  /* End of the mandatory fields.*/
  /**
   * @brief   Total transmit transfer size.
   */
  size_t                        totsize;
} USBInEndpointState;

/**
 * @brief   Type of an OUT endpoint state structure.
 */
typedef struct {
  /**
   * @brief   Requested receive transfer size.
   */
  size_t                        rxsize;
  /**
   * @brief   Received bytes so far.
   */
  size_t                        rxcnt;
  /**
   * @brief   Pointer to the receive linear buffer.
   */
  uint8_t                       *rxbuf;
#if (USB_USE_WAIT == TRUE) || defined(__DOXYGEN__)
  /**
   * @brief   Waiting thread.
   */
  thread_reference_t            thread;
#endif
  /* End of the mandatory fields.*/
  /**
   * @brief   Total receive transfer size.
   */
  size_t                        totsize;
} USBOutEndpointState;

/**
 * @brief   Type of an USB endpoint configuration structure.
 * @note    Platform specific restrictions may apply to endpoints.
 */
typedef struct {
  /**
   * @brief   Type and mode of the endpoint.
   */
  uint32_t                      ep_mode;
  /**
   * @brief   Setup packet notification callback.
   * @details This callback is invoked when a setup packet has been
   *          received.
   * @post    The application must immediately call @p usbReadPacket() in
   *          order to access the received packet.
   * @note    This field is only valid for @p USB_EP_MODE_TYPE_CTRL
   *          endpoints, it should be set to @p NULL for other endpoint
   *          types.
   */
  usbepcallback_t               setup_cb;
  /**
   * @brief   IN endpoint notification callback.
   * @details This field must be set to @p NULL if callback is not required.
   */
  usbepcallback_t               in_cb;
  /**
   * @brief   OUT endpoint notification callback.
   * @details This field must be set to @p NULL if callback is not required.
   */
  usbepcallback_t               out_cb;
  /**
   * @brief   IN endpoint maximum packet size.
   * @details This field must be set to zero if the IN endpoint is not used.
   */
  uint16_t                      in_maxsize;
  /**
   * @brief   OUT endpoint maximum packet size.
   * @details This field must be set to zero if the OUT endpoint is not used.
   */
  uint16_t                      out_maxsize;
  /**
   * @brief   @p USBEndpointState associated to the IN endpoint.
   * @details This field must be set to @p NULL if the IN endpoint is not
   *          used.
   */
  USBInEndpointState            *in_state;
  /**
   * @brief   @p USBEndpointState associated to the OUT endpoint.
   * @details This field must be set to @p NULL if the OUT endpoint is not
   *          used.
   */
  USBOutEndpointState           *out_state;
  /* End of the mandatory fields.*/
  /**
   * @brief   Determines the space allocated for the TXFIFO as multiples of
   *          the packet size (@p in_maxsize). Note that zero is interpreted
   *          as one for simplicity and robustness.
   */
  uint16_t                      in_multiplier;
  /**
   * @brief   Pointer to a buffer for setup packets.
   * @details Setup packets require a dedicated 8-bytes buffer, set this
   *          field to @p NULL for non-control endpoints.
   */
  uint8_t                       *setup_buf;
} USBEndpointConfig;

/**
 * @brief   Type of an USB driver configuration structure.
 */
typedef struct {
  /**
   * @brief   USB events callback.
   * @details This callback is invoked when an USB driver event is registered.
   */
  usbeventcb_t                  event_cb;
  /**
   * @brief   Device GET_DESCRIPTOR request callback.
   * @note    This callback is mandatory and cannot be set to @p NULL.
   */
  usbgetdescriptor_t            get_descriptor_cb;
  /**
   * @brief   Requests hook callback.
   * @details This hook allows to be notified of standard requests or to
   *          handle non standard requests.
   */
  usbreqhandler_t               requests_hook_cb;
  /**
   * @brief   Start Of Frame callback.
   */
  usbcallback_t                 sof_cb;
  /* End of the mandatory fields.*/
} USBConfig;

/**
 * @brief   Structure representing an USB driver.
 */
struct USBDriver {
  /**
   * @brief   Driver state.
   */
  usbstate_t                    state;
  /**
   * @brief   Current configuration data.
   */
  const USBConfig               *config;
  /**
   * @brief   Bit map of the transmitting IN endpoints.
   */
  uint16_t                      transmitting;
  /**
   * @brief   Bit map of the receiving OUT endpoints.
   */
  uint16_t                      receiving;
  /**
   * @brief   Active endpoints configurations.
   */
  const USBEndpointConfig       *epc[USB_MAX_ENDPOINTS + 1];
  /**
   * @brief   Fields available to user, it can be used to associate an
   *          application-defined handler to an IN endpoint.
   * @note    The base index is one, the endpoint zero does not have a
   *          reserved element in this array.
   */
  void                          *in_params[USB_MAX_ENDPOINTS];
  /**
   * @brief   Fields available to user, it can be used to associate an
   *          application-defined handler to an OUT endpoint.
   * @note    The base index is one, the endpoint zero does not have a
   *          reserved element in this array.
   */
  void                          *out_params[USB_MAX_ENDPOINTS];
  /**
   * @brief   Endpoint 0 state.
   */
  usbep0state_t                 ep0state;
  /**
   * @brief   Next position in the buffer to be transferred through endpoint 0.
   */
  uint8_t                       *ep0next;
  /**
   * @brief   Number of bytes yet to be transferred through endpoint 0.
   */
  size_t                        ep0n;
  /**
   * @brief   Endpoint 0 end transaction callback.
   */
  usbcallback_t                 ep0endcb;
  /**
   * @brief   Setup packet buffer.
   */
  uint8_t                       setup[8];
  /**
   * @brief   Current USB device status.
   */
  uint16_t                      status;
  /**
   * @brief   Assigned USB address.
   */
  uint8_t                       address;
  /**
   * @brief   Current USB device configuration.
   */
  uint8_t                       configuration;
  /**
   * @brief   State of the driver when a suspend happened.
   */
  usbstate_t                    saved_state;
#if defined(USB_DRIVER_EXT_FIELDS)
  USB_DRIVER_EXT_FIELDS
#endif
  /* End of the mandatory fields.*/
  /**
   * @brief   Pointer to the OTG peripheral associated to this driver.
   */
  hc32_otg_t                   otg;
  /**
   * @brief   Peripheral-specific parameters.
   */
  const hc32_otg_params_t      *otgparams;
  /**
   * @brief   Pointer to the next address in the packet memory.
   */
  uint32_t                      pmnext;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Returns the exact size of a receive transaction.
 * @details The received size can be different from the size specified in
 *          @p usbStartReceiveI() because the last packet could have a size
 *          different from the expected one.
 * @pre     The OUT endpoint must have been configured in transaction mode
 *          in order to use this function.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 * @return              Received data size.
 *
 * @notapi
 */
#define usb_lld_get_transaction_size(usbp, ep)                              \
  ((usbp)->epc[ep]->out_state->rxcnt)

/**
 * @brief   Connects the USB device.
 *
 * @notapi
 */
#define usb_lld_connect_bus(usbp) {                                       \
  USB_CORE_DCTL_TypeDef  dctl_con;                                           \
  dctl_con.d32 = HD_USB_RDREG32(&(&(usbp)->otg)->DREGS->DCTL);                 \
  dctl_con.b.sftdiscon  = 0u;                                                \
  HD_USB_WRREG32(&(&(usbp)->otg)->DREGS->DCTL, dctl_con.d32);                  \
}

/**
 * @brief   Disconnect the USB device.
 *
 * @notapi
 */
#define usb_lld_disconnect_bus(usbp) {                                          \
  USB_CORE_DCTL_TypeDef  dctl_dis;                                           \
  dctl_dis.d32 = HD_USB_RDREG32(&(&(usbp)->otg)->DREGS->DCTL);                 \
  dctl_dis.b.sftdiscon  = 1u;                                                \
  HD_USB_WRREG32(&(&(usbp)->otg)->DREGS->DCTL, dctl_dis.d32);                  \
}

/**
 * @brief   Start of host wake-up procedure.
 *
 * @notapi
 */
#define usb_lld_wakeup_host(usbp) {                                          \
  USB_CORE_DCTL_TypeDef     dctl;                                            \
  hc32_otg_t *otgp = &(usbp)->otg;                                             \
  dctl.d32          = 0ul;                                                   \
  dctl.b.rmtwkupsig = 1u;                                                    \
  HD_USB_MDFREG32(&otgp->DREGS->DCTL, 0ul, dctl.d32);                        \
  osalThreadSleepMilliseconds(HC32_USB_HOST_WAKEUP_DURATION);                \
  HD_USB_MDFREG32(&otgp->DREGS->DCTL, dctl.d32, 0ul);                        \
}

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if HC32_USB_USE_OTG1 && !defined(__DOXYGEN__)
extern USBDriver USBD1;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void usb_lld_init(void);
  void usb_lld_start(USBDriver *usbp);
  void usb_lld_stop(USBDriver *usbp);
  void usb_lld_reset(USBDriver *usbp);
  void usb_lld_set_address(USBDriver *usbp);
  void usb_lld_init_endpoint(USBDriver *usbp, usbep_t ep);
  void usb_lld_disable_endpoints(USBDriver *usbp);
  usbepstatus_t usb_lld_get_status_in(USBDriver *usbp, usbep_t ep);
  usbepstatus_t usb_lld_get_status_out(USBDriver *usbp, usbep_t ep);
  void usb_lld_read_setup(USBDriver *usbp, usbep_t ep, uint8_t *buf);
  void usb_lld_start_out(USBDriver *usbp, usbep_t ep);
  void usb_lld_start_in(USBDriver *usbp, usbep_t ep);
  void usb_lld_stall_out(USBDriver *usbp, usbep_t ep);
  void usb_lld_stall_in(USBDriver *usbp, usbep_t ep);
  void usb_lld_clear_out(USBDriver *usbp, usbep_t ep);
  void usb_lld_clear_in(USBDriver *usbp, usbep_t ep);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_USB */

#endif /* HAL_USB_LLD_H */

/** @} */
