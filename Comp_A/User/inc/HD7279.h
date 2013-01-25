/***************************************************************************************************
  * 文    件：7279.h    
  * 作    者：longwei
  * 编写日期：
  * 版    本：V1.0
  * 开 发 板：MSP430G2553 TI开发板
  * 修改时间：无 
  * 编 译 器: IAR.5.20
  *-------------------------------------------------------------------------------------------------
  * 简    介：HD7279硬件配置 
  * 参    考:    
  *************************************************************************************************/  
/* 防止递归包含的定义-----------------------------------------------------------------------------*/

#ifndef __HD7279_H_
#define __HD7279_H_ 
#ifdef __cplusplus
 extern "C" {
#endif 
/* 包含 ------------------------------------------------------------------------------------------*/
#include  <msp430g2553.h>
#include "stdint.h"
#include "Delay.h"
/*定义键盘数据类型--------------------------------------------------------------------------------*/
typedef struct
{
  volatile uint8_t Key_Flag;
  volatile uint8_t Keynum;
} KEY_TypeDef;

/*数码管显示配置控制------------------------------------------------------------------------------*/
#define __USER_DISNUM__ 1 /*1 enable and 0 disable*/
/*出口变量----------------------------------------------------------------------------------------*/
extern KEY_TypeDef KEY;
/*出口宏------------------------------------------------------------------------------------------*/
#define HD7279_CMD_Reset  	0xa4       //复位
#define HD7279_CMD_R_Key	0x15	   //读取键值
#if __USER_DISNUM__
/*HD7279 控制命令字(常用的)-----------------------------------------------------------------------*/

#define HD7279_CMD_Test     0xbf       //测试指令 
#define	HD7279_CMD_Left     0xa1       //左移
#define HD7279_CMD_Right    0xa0       //右移
#define HD7279_CMD_Cleft    0xa3       //循环左移
#define HD7279_CMD_Cright   0xa2       //循环右移
#endif
/*硬件连接线--------------------------------------------------------------------------------------*/
#define HD7279_IO_DIR P2DIR|= BIT3+BIT4+BIT5
#define HD7279_CS1       P2OUT |= BIT3 
#define HD7279_CS0       P2OUT &= ~BIT3
#define HD7279_CLK1      P2OUT |= BIT4
#define HD7279_CLK0      P2OUT &= ~BIT4 
#define HD7279_DAT_W1    P2OUT |= BIT5 
#define HD7279_DAT_W0    P2OUT &= ~BIT5
#define	HD7279_DAT_R     ((P2IN&BIT5)<<5)

#define HD7279_DAT_OUT P2DIR|=BIT5
#define HD7279_DAT_IN  P2DIR&=~BIT5

#define HD7279_KEYIO_IN  P2DIR&=~BIT2
#define HD7279_KEYIO_OUT P2DIR|= BIT2
/*出口函数模型------------------------------------------------------------------------------------*/
//按键中断使能
#define KEY_In_Enable()  P2IE |= BIT2//中断使能
//按键中断失能
#define KEY_In_Disable() P2IE &=~BIT2;//中断失能

void HD7279_Init(void);
void HD7279_CMD(uint8_t cmd);
#if __USER_DISNUM__
void  LED_Display(uint8_t Location,uint8_t Number,uint8_t Dp);
#endif
#ifdef __cplusplus
}
#endif

#endif 
/******************* (C) 版权 2012 longwei *****文件结束*******************************************/
