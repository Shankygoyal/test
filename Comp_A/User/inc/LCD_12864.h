/***************************************************************************************************
  * 文    件：mian.c    
  * 作    者：longwei
  * 编写日期：2012/524
  * 版    本：V1.0
  * 开 发 板：MSP430G2553 TI开发板
  * 修改时间：2012/7/15  
  * 编 译 器: IAR.5.20
  *-------------------------------------------------------------------------------------------------
  * 简    介：
  * 参    考:    
  *************************************************************************************************/  
/* 防止递归包含的定义-----------------------------------------------------------------------------*/
#ifndef __LCD_12864_H_
#define __LCD_12864_H_

#ifdef __cplusplus
 extern "C" {
#endif 

/* 包含 ------------------------------------------------------------------------------------------*/
#include  <msp430g2553.h>
#include "stdint.h"
#include "Delay.h"
/* 出口类型 --------------------------------------------------------------------------------------*/
#define LCD_IO_DIR P2DIR|= BIT3+BIT4+BIT5 
#define LCD_CS1  P2OUT |= BIT3 
#define LCD_CS0  P2OUT &= ~BIT3 
#define LCD_CLK1 P2OUT |= BIT4 
#define LCD_CLK0 P2OUT &= ~BIT4 
#define LCD_DAT1 P2OUT |= BIT5 
#define LCD_DAT0 P2OUT &= ~BIT5
#define LCD_DAT_OUT P2DIR|=BIT5
/* 出口常量---------------------------------------------------------------------------------------*/


/* 出口宏-----------------------------------------------------------------------------------------*/


/*出口函数模型------------------------------------------------------------------------------------*/
void LCD_Init(void);
void LCD_Clear(void);
void LCD_LineClear(uint8_t Line);
void LCD_Pos(uint8_t Line,uint8_t Column);
void Display_Str(uint8_t Line,uint8_t Column, uint8_t *ptr);
void LCD_DisplayNum(uint8_t Line,uint8_t Column, uint16_t num,uint8_t Size);
void LCD_Display_FloatNum(uint8_t Line,uint8_t Column, float num,uint8_t Size);

#ifdef __cplusplus
}
#endif

#endif 

/******************* (C) 版权 2012 longwei *****文件结束*******************************************/
