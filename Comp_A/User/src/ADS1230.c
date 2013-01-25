/*******************************************************************************
// 说明: 头文件声明
*******************************************************************************/
#include "main.h"

#define _nop_() asm("nop");


void delay_ms(uint16_t ms);
/*****************************************************************************
函数名称：ReadAD(void)
功    能：读AD
入口参数：无
返回参数：AD的转换结果，为long型
使用资源：无
******************************************************************************/
long ReadAD(void)
{
    long ADdatatemp=0;                      //设置AD转换的初始值为0
    for(uint8_t i = 0;i < 20;i ++)            //获取20位数据
    {
        ADS_CLK_H();
        delay_us(5);
        ADS_CLK_L();
        ADdatatemp = ADdatatemp << 1;
        if(ADS_DATA_HI)                     //AD输出的数据位是1？
        {
            ADdatatemp ++;
        }
    }    
    for(uint8_t i = 0;i < 4;i ++)             //为下一次转换准备
    {
        ADS_CLK_H();                        //ADS_OUT |= ADS_CLK_BIT;
         delay_us(5);
        ADS_CLK_L();                        //ADS_OUT &= ~ADS_CLK_BIT;
    }
    return(ADdatatemp); 
}


/*****************************************************************************
函数名称：void OffsetAD()
功    能：一个补偿函数，补偿AD1230的标尺误差
入口参数：无
返回参数：无
使用资源：无
******************************************************************************/
void OffsetAD()
{
    while(ADS_DATA_NOT_READY);  //AD数据转换好？(ADS_IN & ADS_DATA_BIT)//AD_CLK输出位1
    for(uint8_t i = 0;i < 26;i ++)            //发送26个CLK
    {
        ADS_CLK_H();
         delay_us(5);
        ADS_CLK_L();
    }   
}


/*****************************************************************************
函数名称：void InitADline(void)
功    能：初始化AD控制线
入口参数：无
返回参数：无
使用资源：port2
******************************************************************************/
void InitADline(void)
{
    ADS_PD_DIR_OUT();        //   ADS_DIR |= ADS_PD_BIT;
    AD_OFF()//先拉低         //  ADS_OUT &= ~ADS_PD_BIT;
    ADS_DATA_DIR_IN();       //   ADS_DIR &= ~ADS_DATA_BIT;
    ADS_CLK_DIR_OUT();       //   ADS_DIR |= ADS_CLK_BIT;
    ADS_CLK_L();             //   ADS_OUT &= ~ADS_CLK_BIT;             
    ADS_SPEED_L();
    delay_us(26);
    AD_ON();  
    delay_us(10);
    //启动转换
}