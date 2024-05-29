/*
    ChibiOS - Copyright (C) 2022 Radiolink
    Driver by Radiolink Wu, March 2022
*/

/**
 * @file        TIMv1/hc32_tim.h
 * @brief       HC32 TIM units common header.
 * @note        This file requires definitions from the ST HC32 header file.
 *
 * @addtogroup HC32_TIMv1
 * @{
 */

#ifndef HC32_TIM_H
#define HC32_TIM_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @defgroup TMRA_Register_Bit_Band TMRA Register Bit Band
 * @{
 */
#define __BIT_BAND_BASE                         (0x42000000UL)
#define __PERIP_BASE                            (0x40000000UL)
#define __REG_OFS(regAddr)                      ((regAddr) - __PERIP_BASE)
#define __BIT_BAND_ADDR(regAddr, pos)           ((__REG_OFS(regAddr) << 5U) + ((uint32_t)(pos) << 2U) + __BIT_BAND_BASE)
#define BIT_BAND(regAddr, pos)                  (*(__IO uint32_t *)__BIT_BAND_ADDR((regAddr), (pos)))
/**
 * @}
 */
/**
 * @defgroup TMRA_Unit_Index TMRA Unit Index
 * @{
 */
#define __TMRA_BASE                             (0x4003A000UL)
#define __TMRA_UNIT_SIZE                        (0x400UL)
#define TMRA_IDX(__TMRAx__)                     (((uint32_t)&(__TMRAx__)->CNTER - __TMRA_BASE) / __TMRA_UNIT_SIZE)
/**
 * @}
 */

/**
 * @defgroup TMRA_Miscellaneous_Macros TMRA Miscellaneous Macros
 * @{
 */
#define TMRA_CH_COUNT                       (4U)
#define TMRA_PIN_PWM_OFFSET                 (3U)
/**
 * @}
 */

 /*!< PCLK. PCLK0 for unit1 ~ uint4. PCLK1 for unit5 ~ uint12.*/
#define TMRA_CLK_PCLK                       (0x0U)

/* Define for TMR6 BCONR register configuration */
#define BCONR_REG_CFG_MSK                       (0x0000000FUL)
#define BCONR_GEN_BUF_CHA_OFFSET                (0x00UL)
#define BCONR_GEN_BUF_CHB_OFFSET                (0x04UL)
#define BCONR_PERIOD_BUF_OFFSET                 (0x08UL)
#define BCONR_SPECIAL_BUF_CHA_OFFSET            (0x10UL)
#define BCONR_SPECIAL_BUF_CHB_OFFSET            (0x14UL)

/* Define mask value for port output configuration for PCNAR/PCNBR register */
#define PCNA_BR_REG_OUTPUT_CFG_MASK             (0x1003FFFFUL)
#define PCNA_BR_REG_EMB_CFG_MASK                (TMR6_PCNAR_EMBSA | TMR6_PCNAR_EMBRA | TMR6_PCNAR_EMBCA)

/**
 * @defgroup TMRA_Configuration_Bit_Mask TMRA Configuration Bit Mask
 * @{
 */
#define TMRA_BCSTR_INIT_MSK                     (0x01F6UL)
#define TMRA_BCSTR_INT_MSK                      (0x00003000UL)
#define TMRA_BCSTR_FLAG_MSK                     (0x0000C000UL)
#define TMRA_FCONR_FILTER_CLK_MSK               (0x3UL)
#define TMRA_CCONR_FILTER_CLK_MSK               (TMRA_CCONR_NOFICKCP)
#define TMRA_PWM_POLARITY_MSK                   (0x03FFUL)
#define TMRA_TRIG_COND_MSK                      (TMRA_START_COND_ALL | TMRA_STOP_COND_ALL | TMRA_CLR_COND_ALL)
#define TMRA_CACHE_COND_MSK                     (TMRA_BCONR_BSE0 | TMRA_BCONR_BSE1)
#define TMRA_TRIG_EVENT_MSK                     (AOS_TMRA_HTSSR_TRGSEL)
/**
 * @}
 */

/* Define mask value for GCONR register */
#define TMR6_INITIAL_MASK                       (TMR6_GCONR_DIR | TMR6_GCONR_MODE | TMR6_GCONR_CKDIV | TMR6_GCONR_OVSTP)

/** @defgroup TMR6_Count_Direction_define TMR6 base counter function direction define
 * @{
 */
#define TMR6_CNT_INCREASE                   (TMR6_GCONR_DIR)
#define TMR6_CNT_DECREASE                   (0x00U)
/**
 * @}
 */

/**
 * @defgroup TMRA_Count_Direction TMRA Counting Direction
 * @{
 */
#define TMRA_DIR_DOWN                       (0x0U)
#define TMRA_DIR_UP                         (TMRA_BCSTR_DIR)
/**
 * @}
 */

/** @defgroup TMR6_Count_Mode_define TMR6 base counter function mode define
 * @{
 */
#define TMR6_MODE_SAWTOOTH                   (0x00U)
#define TMR6_MODE_TRIANGLE                   (TMR6_GCONR_MODE)
/**
 * @}
 */

/**
 * @defgroup TMRA_Count_Mode TMRA Counting Mode
 * @{
 */
#define TMRA_MODE_SAWTOOTH                  (0x0U)
#define TMRA_MODE_TRIANGLE                  (TMRA_BCSTR_MODE)
/**
 * @}
 */

/** @defgroup TMR6_Input_Port_Filter_Clk TMR6 input port define
 * @{
 */
#define TMR6_INPUT_FILTER_PCLK0_DIV1            (0x00U)
#define TMR6_INPUT_FILTER_PCLK0_DIV4            (0x01U)
#define TMR6_INPUT_FILTER_PCLK0_DIV16           (0x02U)
#define TMR6_INPUT_FILTER_PCLK0_DIV64           (0x03U)
/**
 * @}
 */

/** @defgroup TMR6_Port_Mode_Func TMR6 port function mode selection
 * @{
 */
#define TMR6_PORT_COMPARE_OUTPUT                 (0x00U)
#define TMR6_PORT_CAPTURE_INPUT                  (TMR6_PCNAR_CAPMDA)
/**
 * @}
 */

/**
 * @defgroup TMRA_Function_Mode TMRA Function Mode
 * @{
 */
#define TMRA_FUNC_COMPARE                   (0x0U)
#define TMRA_FUNC_CAPTURE                   (TMRA_CCONR_CAPMD)
/**
 * @}
 */

/** @defgroup TMR6_Port_Input_Filter_Sta TMR6 port input filter function status
 * @{
 */
#define TMR6_PORT_INPUT_FILTER_OFF               (0x00U)
#define TMR6_PORT_INPUT_FILTER_ON                (0x01U)
/**
 * @}
 */

/** @defgroup TMR6_hardware_control_event_define TMR6 hardware start/stop/clear/update/capture events define
 * @{
 */
#define TMR6_HW_CTRL_PWMA_RISING             (TMR6_HSTAR_HSTA0)
#define TMR6_HW_CTRL_PWMA_FAILLING           (TMR6_HSTAR_HSTA1)
#define TMR6_HW_CTRL_PWMB_RISING             (TMR6_HSTAR_HSTA2)
#define TMR6_HW_CTRL_PWMB_FAILLING           (TMR6_HSTAR_HSTA3)
#define TMR6_HW_CTRL_INTER_EVENT0            (TMR6_HSTAR_HSTA8)
#define TMR6_HW_CTRL_INTER_EVENT1            (TMR6_HSTAR_HSTA9)
#define TMR6_HW_CTRL_INTER_EVENT2            (TMR6_HSTAR_HSTA10)
#define TMR6_HW_CTRL_INTER_EVENT3            (TMR6_HSTAR_HSTA11)
#define TMR6_HW_CTRL_TRIGEA_RISING           (TMR6_HSTAR_HSTA16)
#define TMR6_HW_CTRL_TRIGEA_FAILLING         (TMR6_HSTAR_HSTA17)
#define TMR6_HW_CTRL_TRIGEB_RISING           (TMR6_HSTAR_HSTA18)
#define TMR6_HW_CTRL_TRIGEB_FAILLING         (TMR6_HSTAR_HSTA19)
#define TMR6_HW_CTRL_TRIGEC_RISING           (TMR6_HSTAR_HSTA20)
#define TMR6_HW_CTRL_TRIGEC_FAILLING         (TMR6_HSTAR_HSTA21)
#define TMR6_HW_CTRL_TRIGED_RISING           (TMR6_HSTAR_HSTA22)
#define TMR6_HW_CTRL_TRIGED_FAILLING         (TMR6_HSTAR_HSTA23)
/**
 * @}
 */

/**
 * @defgroup TMRA_Hardware_Start_Condition TMRA Hardware Start Condition
 * @{
 */
#define TMRA_START_COND_INVALID             (0x0U)
#define TMRA_START_COND_TRIGR               (TMRA_HCONR_HSTA0)
#define TMRA_START_COND_TRIGF               (TMRA_HCONR_HSTA1)
#define TMRA_START_COND_EVENT               (TMRA_HCONR_HSTA2)
#define TMRA_START_COND_ALL                 (TMRA_START_COND_TRIGR | \
                                             TMRA_START_COND_TRIGF | \
                                             TMRA_START_COND_EVENT)
/**
 * @}
 */

/**
 * @defgroup TMRA_Hardware_Stop_Condition TMRA Hardware Stop Condition
 * @{
 */
#define TMRA_STOP_COND_INVALID              (0x0U)
#define TMRA_STOP_COND_TRIGR                (TMRA_HCONR_HSTP0)
#define TMRA_STOP_COND_TRIGF                (TMRA_HCONR_HSTP1)
#define TMRA_STOP_COND_EVENT                (TMRA_HCONR_HSTP2)
#define TMRA_STOP_COND_ALL                  (TMRA_STOP_COND_TRIGR | \
                                             TMRA_STOP_COND_TRIGF | \
                                             TMRA_STOP_COND_EVENT)
/**
 * @}
 */


/**
 * @defgroup TMRA_Hardware_Clear_Condition TMRA Hardware Clear Condition
 * @note Symmetric units: uint 1 and 2; uint 3 and 4; ... ; uint 11 and 12.
 * @{
 */
#define TMRA_CLR_COND_INVALID               (0x0U)
#define TMRA_CLR_COND_TRIGR                 (TMRA_HCONR_HCLE0)
#define TMRA_CLR_COND_TRIGF                 (TMRA_HCONR_HCLE1)
#define TMRA_CLR_COND_EVENT                 (TMRA_HCONR_HCLE2)
#define TMRA_CLR_COND_SYM_TRIGR             (TMRA_HCONR_HCLE3)
#define TMRA_CLR_COND_SYM_TRIGF             (TMRA_HCONR_HCLE4)
#define TMRA_CLR_COND_PWM3R                 (TMRA_HCONR_HCLE5)
#define TMRA_CLR_COND_PWM3F                 (TMRA_HCONR_HCLE6)
#define TMRA_CLR_COND_ALL                   (TMRA_CLR_COND_TRIGR     | \
                                             TMRA_CLR_COND_TRIGF     | \
                                             TMRA_CLR_COND_EVENT     | \
                                             TMRA_CLR_COND_SYM_TRIGR | \
                                             TMRA_CLR_COND_SYM_TRIGF | \
                                             TMRA_CLR_COND_PWM3R     | \
                                             TMRA_CLR_COND_PWM3F)
/**
 * @}
 */

/**
 * @defgroup TMRA_Channel_Capture_Condition TMRA Capturing Condition Of Channel
 * @note 'TMRA_CAPT_COND_TRIGR' and 'TMRA_CAPT_COND_TRIGF' are only valid for channel 4.
 * @{
 */
#define TMRA_CAPT_COND_INVALID              (0x0U)
#define TMRA_CAPT_COND_PWMR                 (TMRA_CCONR_HICP0)
#define TMRA_CAPT_COND_PWMF                 (TMRA_CCONR_HICP1)
#define TMRA_CAPT_COND_EVENT                (TMRA_CCONR_HICP2)
#define TMRA_CAPT_COND_TRIGR                (TMRA_CCONR_HICP3)
#define TMRA_CAPT_COND_TRIGF                (TMRA_CCONR_HICP4)
#define TMRA_CAPT_COND_ALL                  (TMRA_CAPT_COND_PWMR  | \
                                             TMRA_CAPT_COND_PWMF  | \
                                             TMRA_CAPT_COND_EVENT | \
                                             TMRA_CAPT_COND_TRIGR | \
                                             TMRA_CAPT_COND_TRIGF)
/**
 * @}
 */

/** @defgroup TMR6_Count_Clock_define TMR6 base counter clock source define
 * @{
 */
#define TMR6_CLK_PCLK0_DIV1                  (0x00UL)
#define TMR6_CLK_PCLK0_DIV2                  (0x01UL << TMR6_GCONR_CKDIV_POS)
#define TMR6_CLK_PCLK0_DIV4                  (0x02UL << TMR6_GCONR_CKDIV_POS)
#define TMR6_CLK_PCLK0_DIV8                  (0x03UL << TMR6_GCONR_CKDIV_POS)
#define TMR6_CLK_PCLK0_DIV16                 (0x04UL << TMR6_GCONR_CKDIV_POS)
#define TMR6_CLK_PCLK0_DIV32                 (0x05UL << TMR6_GCONR_CKDIV_POS)
#define TMR6_CLK_PCLK0_DIV64                 (0x06UL << TMR6_GCONR_CKDIV_POS)
#define TMR6_CLK_PCLK0_DIV128                (0x07UL << TMR6_GCONR_CKDIV_POS)
#define TMR6_CLK_PCLK0_DIV256                (0x08UL << TMR6_GCONR_CKDIV_POS)
#define TMR6_CLK_PCLK0_DIV512                (0x09UL << TMR6_GCONR_CKDIV_POS)
#define TMR6_CLK_PCLK0_DIV1024               (0x0AUL << TMR6_GCONR_CKDIV_POS)
/**
 * @}
 */

/**
 * @defgroup TMRA_PCLK_Divider TMRA PCLK Divider
 * @note Clock divider is only valid for PCLK(PCLK0 for unit1 ~ uint4. PCLK1 for unit5 ~ uint12).
 * @{
 */
#define TMRA_PCLK_DIV1                      (0x0UL)                             /*!< The clock source of TMRA is PCLK. */
#define TMRA_PCLK_DIV2                      (0x1UL << TMRA_BCSTR_CKDIV_POS)     /*!< The clock source of TMRA is PCLK / 2. */
#define TMRA_PCLK_DIV4                      (0x2UL << TMRA_BCSTR_CKDIV_POS)     /*!< The clock source of TMRA is PCLK / 4. */
#define TMRA_PCLK_DIV8                      (0x3UL << TMRA_BCSTR_CKDIV_POS)     /*!< The clock source of TMRA is PCLK / 8. */
#define TMRA_PCLK_DIV16                     (0x4UL << TMRA_BCSTR_CKDIV_POS)     /*!< The clock source of TMRA is PCLK / 16. */
#define TMRA_PCLK_DIV32                     (0x5UL << TMRA_BCSTR_CKDIV_POS)     /*!< The clock source of TMRA is PCLK / 32. */
#define TMRA_PCLK_DIV64                     (0x6UL << TMRA_BCSTR_CKDIV_POS)     /*!< The clock source of TMRA is PCLK / 64. */
#define TMRA_PCLK_DIV128                    (0x7UL << TMRA_BCSTR_CKDIV_POS)     /*!< The clock source of TMRA is PCLK / 128. */
#define TMRA_PCLK_DIV256                    (0x8UL << TMRA_BCSTR_CKDIV_POS)     /*!< The clock source of TMRA is PCLK / 256. */
#define TMRA_PCLK_DIV512                    (0x9UL << TMRA_BCSTR_CKDIV_POS)     /*!< The clock source of TMRA is PCLK / 512. */
#define TMRA_PCLK_DIV1024                   (0xAUL << TMRA_BCSTR_CKDIV_POS)     /*!< The clock source of TMRA is PCLK / 1024. */
/**
 * @}
 */


/** @defgroup TMR6_Count_Stop_After_Overflow_define TMR6 count stop after overflow function define
 * @{
 */
#define TMR6_CNT_CONTINUOUS                   (0x00U)
#define TMR6_STOP_AFTER_OVF                   (TMR6_GCONR_OVSTP)
/**
 * @}
 */

/**
 * @defgroup TMRA_Count_Overflow_Operation TMRA Count Overflow Operation
 * @note Count up corresponds to overflow, counter zeroing when counting value overflow period value.
 * @note Count down corresponds to underflow, counter reload period value when counting value underflow 0.
 * @{
 */
#define TMRA_OVF_CNT_CONTINUE               (0x0U)
#define TMRA_OVF_CNT_STOP                   (TMRA_BCSTR_OVSTP)
/**
 * @}
 */

/** @defgroup TMR6_Period_Register_Index_Define TMR6 period register Index define
 * @{
 */
#define TMR6_PERIOD_REG_A   (0x00UL)
#define TMR6_PERIOD_REG_B   (0x01UL)
#define TMR6_PERIOD_REG_C   (0x02UL)

/**
 * @}
 */

/** @defgroup TMR6_Compare_Register_Index_Define TMR6 compare register Index define
 * @{
 */
#define TMR6_CMP_REG_A      (0x00UL)
#define TMR6_CMP_REG_B      (0x01UL)
#define TMR6_CMP_REG_C      (0x02UL)
#define TMR6_CMP_REG_D      (0x03UL)
#define TMR6_CMP_REG_E      (0x04UL)
#define TMR6_CMP_REG_F      (0x05UL)
/**
 * @}
 */

/** @defgroup TMR6_Pwm_channel_Define TMR6 Pwm channel index define
 * @{
 */
#define TMR6_CH_A           (0x00UL)
#define TMR6_CH_B           (0x01UL)
/**
 * @}
 */

/**
 * @defgroup TMRA_Channel TMRA Channel
 * @{
 */
#define TMRA_CH_1                           (0U)
#define TMRA_CH_2                           (1U)
#define TMRA_CH_3                           (2U)
#define TMRA_CH_4                           (3U)
/**
 * @}
 */
/*
 * @defgroup TMRA_Event_Type TMRA Event Type
 * @{
 */
#define TMRA_EVENT_CMP_CH1                  (TMRA_ECONR_ETEN1)          /*!< The event of compare-match of channel 1. */
#define TMRA_EVENT_CMP_CH2                  (TMRA_ECONR_ETEN2)          /*!< The event of compare-match of channel 2. */
#define TMRA_EVENT_CMP_CH3                  (TMRA_ECONR_ETEN3)          /*!< The event of compare-match of channel 3. */
#define TMRA_EVENT_CMP_CH4                  (TMRA_ECONR_ETEN4)          /*!< The event of compare-match of channel 4. */
#define TMRA_EVENT_ALL                      (TMRA_EVENT_CMP_CH1 | \
                                             TMRA_EVENT_CMP_CH2 | \
                                             TMRA_EVENT_CMP_CH3 | \
                                             TMRA_EVENT_CMP_CH4)

/** @defgroup TMR6_Buffer_Function_sta_Define TMR6 buffer function status define
 * @{
 */
#define TMR6_BUF_FUNC_OFF   (0x00000000UL)
#define TMR6_BUF_FUNC_ON    (TMR6_BCONR_BENA)
/**
 * @}
 */

/** @defgroup TMR6_Buffer_Number_Chose_Define TMR6 buffer number configuration define
 * @{
 */
#define TMR6_BUF_FUNC_SINGLE   (0x00000000UL)
#define TMR6_BUF_FUNC_DOUBLE   (TMR6_BCONR_BSEA)
/**
 * @}
 */

/** @defgroup TMR6_Buffer_Transfer_Time_Cfg_Define TMR6 buffer transfer time configuration define
 * @{
 */
#define TMR6_BUF_TRANS_TIM_NONE        (0x00000000UL)
#define TMR6_BUF_TRANS_TIM_OVERFLOW    (TMR6_BCONR_BTRUA)
#define TMR6_BUF_TRANS_TIM_UNDERFLOW   (TMR6_BCONR_BTRDA)
#define TMR6_BUF_TRANS_TIM_BOTH        (TMR6_BCONR_BTRUA | TMR6_BCONR_BTRDA)
/**
 * @}
 */

/** @defgroup TMR6_Port_Output_Sta TMR6 port output status
 * @{
 */
#define TMR6_PORT_OUTPUT_STA_LOW                 (0x00U)
#define TMR6_PORT_OUTPUT_STA_HIGH                (0x01U)
#define TMR6_PORT_OUTPUT_STA_HOLD                (0x02U)
#define TMR6_PORT_OUTPUT_STA_REVERSE             (0x03U)
/**
 * @}
 */

/** @defgroup TMR6_Force_Port_Output_Sta TMR6 force port output status next period
 * @{
 */
#define TMR6_FORCE_PORT_OUTPUT_INVALID          (0x00U)
#define TMR6_FORCE_PORT_OUTPUT_STA_LOW          (0x02U)
#define TMR6_FORCE_PORT_OUTPUT_STA_HIGH         (0x03U)
/**
 * @}
 */

/** @defgroup TMR6_Port_Define TMR6 input and output port define
 * @{
 */
#define TMR6_IO_PWMA                            (0x00U)
#define TMR6_IO_PWMB                            (0x01U)
#define TMR6_INPUT_TRIGA                        (0x02U)
#define TMR6_INPUT_TRIGB                        (0x03U)
#define TMR6_INPUT_TRIGC                        (0x04U)
#define TMR6_INPUT_TRIGD                        (0x05U)
/**
 * @}
 */

/**
 * @defgroup TMRA_PWM_Out_Command TMRA PWM Out Command
 * @{
 */
#define TMRA_PWM_DISABLE                    (0x0U)                      /*!< Disable PWM output. */
#define TMRA_PWM_ENABLE                     (TMRA_PCONR_OUTEN)          /*!< Enable PWM output. */
/**
 * @}
 */

/**
 * @defgroup TMRA_PWM_Start_Polarity TMRA PWM Start Polarity
 * @note The 'START' in the following macros is the state 'counting start'.
 * @{
 */
#define TMRA_PWM_START_LOW                  (0x0U)                      /*!< PWM output low. */
#define TMRA_PWM_START_HIGH                 (TMRA_PCONR_STAC_0)         /*!< PWM output high. */
#define TMRA_PWM_START_KEEP                 (TMRA_PCONR_STAC_1)         /*!< PWM output keeps the current polarity. */
/**
 * @}
 */

/**
 * @defgroup TMRA_PWM_Stop_Polarity TMRA PWM Stop Polarity
 * @note The 'STOP' in the following macros is the state 'counting stop'.
 * @{
 */
#define TMRA_PWM_STOP_LOW                   (0x0U)                      /*!< PWM output low. */
#define TMRA_PWM_STOP_HIGH                  (TMRA_PCONR_STPC_0)         /*!< PWM output high. */
#define TMRA_PWM_STOP_KEEP                  (TMRA_PCONR_STPC_1)         /*!< PWM output keeps the current polarity. */
/**
 * @}
 */

/**
 * @defgroup TMRA_PWM_Match_Cmp_Polarity TMRA PWM Polarity When Counting Matchs Compare Reference Value
 * @{
 */
#define TMRA_PWM_CMP_LOW                    (0x0U)                      /*!< PWM output low. */
#define TMRA_PWM_CMP_HIGH                   (TMRA_PCONR_CMPC_0)         /*!< PWM output high. */
#define TMRA_PWM_CMP_KEEP                   (TMRA_PCONR_CMPC_1)         /*!< PWM output keeps the current polarity. */
#define TMRA_PWM_CMP_REVERSE                (TMRA_PCONR_CMPC)           /*!< PWM output reverses the current polarity. */
/**
 * @}
 */

/**
 * @defgroup TMRA_PWM_Match_Period_Polarity TMRA PWM Polarity When Counting Matchs Period Reference Value
 * @{
 */
#define TMRA_PWM_PERIOD_LOW                 (0x0U)                      /*!< PWM output low. */
#define TMRA_PWM_PERIOD_HIGH                (TMRA_PCONR_PERC_0)         /*!< PWM output high. */
#define TMRA_PWM_PERIOD_KEEP                (TMRA_PCONR_PERC_1)         /*!< PWM output keeps the current polarity. */
#define TMRA_PWM_PERIOD_REVERSE             (TMRA_PCONR_PERC)           /*!< PWM output reverses the current polarity. */
/**
 * @}
 */

/**
 * @defgroup TMRA_PWM_Force_Polarity TMRA PWM Force Polarity
 * @{
 */
#define TMRA_PWM_FORCE_INVALID              (0x0U)                      /*!< Force polarity is invalid. */
#define TMRA_PWM_FORCE_LOW                  (TMRA_PCONR_FORC_1)         /*!< Force the PWM output low at the beginning of the next cycle. \
                                                                             The beginning of the next cycle: overflow position or underflow position \
                                                                             of sawtooth wave; valley position of triangle wave. */
#define TMRA_PWM_FORCE_HIGH                 (TMRA_PCONR_FORC)           /*!< Force the PWM output high at the beginning of the next cycle. \
                                                                             The beginning of the next cycle: overflow position or underflow position \
                                                                             of sawtooth wave; valley position of triangle wave. */
/**
 * @}
 */


/** @defgroup TMR6_Sta_Bit_Get_Define TMR6 status bit define
 * @{
 */
#define TMR6_STAT_CNT_MATCH_A          (TMR6_STFLR_CMAF)
#define TMR6_STAT_CNT_MATCH_B          (TMR6_STFLR_CMBF)
#define TMR6_STAT_CNT_MATCH_C          (TMR6_STFLR_CMCF)
#define TMR6_STAT_CNT_MATCH_D          (TMR6_STFLR_CMDF)
#define TMR6_STAT_CNT_MATCH_E          (TMR6_STFLR_CMEF)
#define TMR6_STAT_CNT_MATCH_F          (TMR6_STFLR_CMFF)
#define TMR6_STAT_OVERFLOW             (TMR6_STFLR_OVFF)
#define TMR6_STAT_UNDERFLOW            (TMR6_STFLR_UDFF)
#define TMR6_STAT_DEAD_TIME_ERR        (TMR6_STFLR_DTEF)
#define TMR6_STAT_UPCNT_SP_MATCH_A     (TMR6_STFLR_CMSAUF)
#define TMR6_STAT_DOWNCNT_SP_MATCH_A   (TMR6_STFLR_CMSADF)
#define TMR6_STAT_UPCNT_SP_MATCH_B     (TMR6_STFLR_CMSBUF)
#define TMR6_STAT_DOWNCNT_SP_MATCH_B   (TMR6_STFLR_CMSBDF)
#define TMR6_STAT_CNT_DIR              (TMR6_STFLR_DIRF)
/**
 * @}
 */

/**
 * @defgroup TMRA_Status_Flag TMRA Status Flag
 * @{
 */
#define TMRA_FLAG_OVF                       (1UL << 14U)
#define TMRA_FLAG_UNF                       (1UL << 15U)
#define TMRA_FLAG_CMP_CH1                   (1UL << 16U)
#define TMRA_FLAG_CMP_CH2                   (1UL << 17U)
#define TMRA_FLAG_CMP_CH3                   (1UL << 18U)
#define TMRA_FLAG_CMP_CH4                   (1UL << 19U)
#define TMRA_FLAG_ALL                       (TMRA_FLAG_OVF | \
                                             TMRA_FLAG_UNF | \
                                             TMRA_FLAG_CMP_CH1 | \
                                             TMRA_FLAG_CMP_CH2 | \
                                             TMRA_FLAG_CMP_CH3 | \
                                             TMRA_FLAG_CMP_CH4)
/**
 * @}
 */

/** @defgroup TMR6_Interrupt_Enable_Bit_Define TMR6 interrupt configuration bit define
 * @{
 */

#define TMR6_IRQ_EN_CNT_MATCH_A           (TMR6_ICONR_INTENA)
#define TMR6_IRQ_EN_CNT_MATCH_B           (TMR6_ICONR_INTENB)
#define TMR6_IRQ_EN_CNT_MATCH_C           (TMR6_ICONR_INTENC)
#define TMR6_IRQ_EN_CNT_MATCH_D           (TMR6_ICONR_INTEND)
#define TMR6_IRQ_EN_CNT_MATCH_E           (TMR6_ICONR_INTENE)
#define TMR6_IRQ_EN_CNT_MATCH_F           (TMR6_ICONR_INTENF)
#define TMR6_IRQ_EN_OVERFLOW              (TMR6_ICONR_INTENOVF)
#define TMR6_IRQ_EN_UNDERFLOW             (TMR6_ICONR_INTENUDF)
#define TMR6_IRQ_EN_DEAD_TIME_ERR         (TMR6_ICONR_INTENDTE)
#define TMR6_IRQ_EN_UPCNT_SP_MATCH_A      (TMR6_ICONR_INTENSAU)
#define TMR6_IRQ_EN_DOWNCNT_SP_MATCH_A    (TMR6_ICONR_INTENSAD)
#define TMR6_IRQ_EN_UPCNT_SP_MATCH_B      (TMR6_ICONR_INTENSBU)
#define TMR6_IRQ_EN_DOWNCNT_SP_MATCH_B    (TMR6_ICONR_INTENSBD)
#define TIM6_IRQ_EN_ALL                   (TMR6_IRQ_EN_CNT_MATCH_A          |\
                                           TMR6_IRQ_EN_CNT_MATCH_B          |\
                                           TMR6_IRQ_EN_CNT_MATCH_C          |\
                                           TMR6_IRQ_EN_CNT_MATCH_D          |\
                                           TMR6_IRQ_EN_CNT_MATCH_E          |\
                                           TMR6_IRQ_EN_CNT_MATCH_F          |\
                                           TMR6_IRQ_EN_OVERFLOW             |\
                                           TMR6_IRQ_EN_UNDERFLOW            |\
                                           TMR6_IRQ_EN_DEAD_TIME_ERR        |\
                                           TMR6_IRQ_EN_UPCNT_SP_MATCH_A     |\
                                           TMR6_IRQ_EN_DOWNCNT_SP_MATCH_A   |\
                                           TMR6_IRQ_EN_UPCNT_SP_MATCH_B     |\
                                           TMR6_IRQ_EN_DOWNCNT_SP_MATCH_B)
/**
 * @}
 */

/**
 * @defgroup TMRA_Interrupt_Type TMRA Interrupt Type
 * @{
 */
#define TMRA_INT_OVF                        (1UL << 12U)
#define TMRA_INT_UNF                        (1UL << 13U)
#define TMRA_INT_CMP_CH1                    (1UL << 16U)
#define TMRA_INT_CMP_CH2                    (1UL << 17U)
#define TMRA_INT_CMP_CH3                    (1UL << 18U)
#define TMRA_INT_CMP_CH4                    (1UL << 19U)
#define TMRA_INT_ALL                        (TMRA_INT_OVF     | \
                                             TMRA_INT_UNF     | \
                                             TMRA_INT_CMP_CH1 | \
                                             TMRA_INT_CMP_CH2 | \
                                             TMRA_INT_CMP_CH3 | \
                                             TMRA_INT_CMP_CH4)
/**
 * @}
 */

#endif /* HC32_TIM_H */


/** @} */
