/*
    ChibiOS - Copyright (C) 2022 Radiolink
    Driver by Radiolink Wu, March 2022
*/

/**
 * @file    RCCv1/hc32_clkdiv.inc
 * @brief   HCLK/PCLK divide setting.
 *
 * @addtogoup HC32_CLKDIV_HANDER
 * @{
 */

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

__STATIC_INLINE void CLK_ClkDiv(uint8_t u8ClkCate, uint32_t u32Div)
{
    __IO uint32_t timeout = 0UL;
    /* backup FCGx setting */
    __IO uint32_t fcg0 = M4_PWC->FCG0;
    __IO uint32_t fcg1 = M4_PWC->FCG1;
    __IO uint32_t fcg2 = M4_PWC->FCG2;
    __IO uint32_t fcg3 = M4_PWC->FCG3;
    uint8_t u8TmpFlag = 0U;

    /* Only current system clock source or target system clock source is PLLH
    need to close fcg0~fcg3 and open fcg0~fcg3 during switch system clock source.
    We need to backup fcg0~fcg3 before close them. */
    if (CLK_SYSCLKSOURCE_PLLH == READ_REG8_BIT(M4_CMU->CKSWR, CMU_CKSWR_CKSW))
    {
        u8TmpFlag = 1U;

        /* Close FCGx. */
        M4_PWC->FCG0 = CLK_FCG0_DEFAULT;
        M4_PWC->FCG1 = CLK_FCG1_DEFAULT;
        M4_PWC->FCG2 = CLK_FCG2_DEFAULT;
        M4_PWC->FCG3 = CLK_FCG3_DEFAULT;

        /* Wait stable after close FCGx. */
        do
        {
            timeout++;
        } while(timeout < CLK_SYSCLK_SW_STABLE);
    }

    /* PCLK0 div */
    if (0U != (CLK_CATE_PCLK0 & u8ClkCate))
    {
        MODIFY_REG32(M4_CMU->SCFGR, CMU_SCFGR_PCLK0S, u32Div);
    }
    /* PCLK1 div */
    if (0U != (CLK_CATE_PCLK1 & u8ClkCate))
    {
        MODIFY_REG32(M4_CMU->SCFGR, CMU_SCFGR_PCLK1S, u32Div);
    }
    /* PCLK2 div */
    if (0U != (CLK_CATE_PCLK2 & u8ClkCate))
    {
        MODIFY_REG32(M4_CMU->SCFGR, CMU_SCFGR_PCLK2S, u32Div);
    }
    /* PCLK3 div */
    if (0U != (CLK_CATE_PCLK3 & u8ClkCate))
    {
        MODIFY_REG32(M4_CMU->SCFGR, CMU_SCFGR_PCLK3S, u32Div);
    }
    /* PCLK4 div */
    if (0U != (CLK_CATE_PCLK4 & u8ClkCate))
    {
        MODIFY_REG32(M4_CMU->SCFGR, CMU_SCFGR_PCLK4S, u32Div);
    }
    /* Ext. bus clock div */
    if (0U != (CLK_CATE_EXCLK & u8ClkCate))
    {
        MODIFY_REG32(M4_CMU->SCFGR, CMU_SCFGR_EXCKS, u32Div);
    }
    /* HCLK div */
    if (0U != (CLK_CATE_HCLK & u8ClkCate))
    {
        MODIFY_REG32(M4_CMU->SCFGR, CMU_SCFGR_HCLKS, u32Div);
    }

    timeout = 0UL;
    do
    {
        timeout++;
    } while(timeout < CLK_SYSCLK_SW_STABLE);

    if (1U == u8TmpFlag)
    {
        M4_PWC->FCG0 = fcg0;
        M4_PWC->FCG1 = fcg1;
        M4_PWC->FCG2 = fcg2;
        M4_PWC->FCG3 = fcg3;

        /* Wait stable after open fcg. */
        timeout = 0UL;
        do
        {
            timeout++;
        } while(timeout < CLK_SYSCLK_SW_STABLE);
    }
}

__STATIC_INLINE void CLK_SetSysClkSrc(uint8_t u8Src)
{
    __IO uint32_t timeout = 0UL;
    /* backup FCGx setting */
    __IO uint32_t fcg0 = M4_PWC->FCG0;
    __IO uint32_t fcg1 = M4_PWC->FCG1;
    __IO uint32_t fcg2 = M4_PWC->FCG2;
    __IO uint32_t fcg3 = M4_PWC->FCG3;
    uint8_t u8TmpFlag = 0U;

    /* Only current system clock source or target system clock source is PLLH
    need to close fcg0~fcg3 and open fcg0~fcg3 during switch system clock source.
    We need to backup fcg0~fcg3 before close them. */
    if (CLK_SYSCLKSOURCE_PLLH == READ_REG8_BIT(M4_CMU->CKSWR, CMU_CKSWR_CKSW) ||    \
        (CLK_SYSCLKSOURCE_PLLH == u8Src))
    {
        u8TmpFlag = 1U;

        /* Close FCGx. */
        M4_PWC->FCG0 = CLK_FCG0_DEFAULT;
        M4_PWC->FCG1 = CLK_FCG1_DEFAULT;
        M4_PWC->FCG2 = CLK_FCG2_DEFAULT;
        M4_PWC->FCG3 = CLK_FCG3_DEFAULT;

        /* Wait stable after close FCGx. */
        do
        {
            timeout++;
        } while(timeout < CLK_SYSCLK_SW_STABLE);
    }

    /* Set system clock source */
    WRITE_REG8(M4_CMU->CKSWR, u8Src);

    /* Wait stable after setting system clock source */
    timeout = 0UL;
    do
    {
        timeout++;
    } while(timeout < CLK_SYSCLK_SW_STABLE);

    if (1U == u8TmpFlag)
    {
        M4_PWC->FCG0 = fcg0;
        M4_PWC->FCG1 = fcg1;
        M4_PWC->FCG2 = fcg2;
        M4_PWC->FCG3 = fcg3;
        /* Wait stable after open fcg. */
        timeout = 0UL;
        do
        {
            timeout++;
        } while(timeout < CLK_SYSCLK_SW_STABLE);
    }
}

