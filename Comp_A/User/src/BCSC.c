/***************************************************************************************************
  * 文    件：BCSC.C    
  * 作    者：longwei
  * 编写日期：2012/5/24
  * 版    本：V1.0
  * 开 发 板：MSP430G2553 TI开发板
  * 修改时间：无 
  * 编 译 器: IAR.5.20
  *-------------------------------------------------------------------------------------------------
  * 简    介：MSP430基础时钟的配置     
  *************************************************************************************************/
/*包含--------------------------------------------------------------------------------------------*/
#include "BCSC.h"
/* 私有定义结构体 --------------------------------------------------------------------------------*/
/* 私有宏-----------------------------------------------------------------------------------------*/
/* 私有变量 --------------------------------------------------------------------------------------*/

/***************************************************************************************************
  * 描述   : DCOCLK时钟设置
  * 参数   : DCO_Bool:时钟频率
  * 返回   : 无
  * 注意   : DCOCLK最大频率与工作电压成线性关系，设置注意工作电压是否满足
  *          时钟配置该函数应先调用，否则会影响其他时钟设置函数的调用
   *************************************************************************************************/
void DCOCLK_Set(DCO_Bool DCO_MHz)
{
  switch (DCO_MHz)
  {
	case _1MHZ:
         {
            if (CALBC1_1MHZ ==0xFF || CALDCO_1MHZ == 0xFF)                                     
            {  
              while(1);                               // If calibration constants erased
                                                      // do not load, trap CPU!!
            }   
            BCSCTL1 = CALBC1_1MHZ;                    // Set DCO to 8MHz
            DCOCTL = CALDCO_1MHZ;
            break;
         }
	case _8MHZ:
         {
            if (CALBC1_8MHZ ==0xFF || CALDCO_8MHZ == 0xFF)                                     
            {  
              while(1);                               // If calibration constants erased
                                                      // do not load, trap CPU!!
            }   
            BCSCTL1 = CALBC1_8MHZ;                    // Set DCO to 8MHz
            DCOCTL = CALDCO_8MHZ;
            break;
         }
    case _12MHZ:
         {
            if (CALBC1_12MHZ ==0xFF || CALDCO_12MHZ == 0xFF)                                     
            {  
              while(1);                               // If calibration constants erased
                                                      // do not load, trap CPU!!
            }   
            BCSCTL1 = CALBC1_12MHZ;                    // Set DCO to 8MHz
            DCOCTL = CALDCO_12MHZ;
            break;
         }
    case _16MHZ:
         {
            if (CALBC1_16MHZ ==0xFF || CALDCO_16MHZ == 0xFF)                                     
            {  
              while(1);                               // If calibration constants erased
                                                      // do not load, trap CPU!!
            }   
            BCSCTL1 = CALBC1_16MHZ;                    // Set DCO to 8MHz
            DCOCTL = CALDCO_16MHZ;
            break;
         }	         
    default:
		break;
  }
}
/***************************************************************************************************
  * 描述   : ACLK时钟设置
  * 参数   : ACLK_Bool: ACLK Source ACLK_DIV：Divider
  * 返回   : 无
  * 注意   : 参数：请用该头文件定义的参数
   *************************************************************************************************/
void ACLK_Set(ACLK_Bool ACLK_S,uint8_t ACLK_DIV)
{
  switch (ACLK_S)
  {
	case LF:
         {
	       BCSCTL1 &=~BIT6;
           BCSCTL3 &=0XCF;
           break;
         }
	case HF:
         {
	       BCSCTL1 |=BIT6;
           BCSCTL3 &=0XCF;
           BCSCTL3 |=0X30;
           break;
         }
    case VLO:
         {
           BCSCTL1 &=~BIT6;
           BCSCTL3 &=0XCF;
	       BCSCTL3 |=0X20;
           break;
         }	
    default:
		break;
  }
  BCSCTL1 &= ACLK_DIV_mask;
  BCSCTL1 |= ACLK_DIV;
}
/***************************************************************************************************
  * 描述   : MCLK时钟设置
  * 参数   : MCLK_Bool: ACLK Source SMCLK_DIV：Divider
  * 返回   : 无
  * 注意   : 参数：请用该头文件定义的参数
   *************************************************************************************************/
void MCLK_Set(MCLK_Bool MCLK_S,uint8_t MCLK_DIV)
{
  switch (MCLK_S)
  {
	case M_DCO_CLK:
         {
	       BCSCTL2 &=0x3F;
           break;
         }
	case M_XT2_CLK:
         {
           BCSCTL2 &=0x3F;
           BCSCTL2 |=BIT7;
           break;
         }
    case M_LF_CLK:
         {
           BCSCTL2 &=0x3F;
           BCSCTL2 |=0xC0;
           break;
         }
    default:
		break;
  }
  BCSCTL2 &= MCLK_DIV_mask;
  BCSCTL2 |= MCLK_DIV;
}
/***************************************************************************************************
  * 描述   : SMCLK时钟设置
  * 参数   : SMCLK_Bool: SMCLK Source SMCLK_DIV：Divider
  * 返回   : 无
  * 注意   : 参数：请用该头文件定义的参数
   *************************************************************************************************/
void SMCLK_Set(SMCLK_Bool SMCLK_S,uint8_t SMCLK_DIV)
{
  switch (SMCLK_S)
  {
	case SM_DCO_CLK:
         {
	       BCSCTL2 &=~BIT3;
           break;
         }
	case SM_XT2_CLK:
         {
           BCSCTL2 |=BIT3;
           break;
         }
    default:
		break;
  }
  BCSCTL2 &= SMCLK_DIV_mask;
  BCSCTL2 |= SMCLK_DIV;
}
/******************* (C) 版权 2012 longwei *****文件结束*******************************************/
