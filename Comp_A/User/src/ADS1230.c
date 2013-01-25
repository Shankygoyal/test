/*******************************************************************************
// ˵��: ͷ�ļ�����
*******************************************************************************/
#include "main.h"

#define _nop_() asm("nop");


void delay_ms(uint16_t ms);
/*****************************************************************************
�������ƣ�ReadAD(void)
��    �ܣ���AD
��ڲ�������
���ز�����AD��ת�������Ϊlong��
ʹ����Դ����
******************************************************************************/
long ReadAD(void)
{
    long ADdatatemp=0;                      //����ADת���ĳ�ʼֵΪ0
    for(uint8_t i = 0;i < 20;i ++)            //��ȡ20λ����
    {
        ADS_CLK_H();
        delay_us(5);
        ADS_CLK_L();
        ADdatatemp = ADdatatemp << 1;
        if(ADS_DATA_HI)                     //AD���������λ��1��
        {
            ADdatatemp ++;
        }
    }    
    for(uint8_t i = 0;i < 4;i ++)             //Ϊ��һ��ת��׼��
    {
        ADS_CLK_H();                        //ADS_OUT |= ADS_CLK_BIT;
         delay_us(5);
        ADS_CLK_L();                        //ADS_OUT &= ~ADS_CLK_BIT;
    }
    return(ADdatatemp); 
}


/*****************************************************************************
�������ƣ�void OffsetAD()
��    �ܣ�һ����������������AD1230�ı�����
��ڲ�������
���ز�������
ʹ����Դ����
******************************************************************************/
void OffsetAD()
{
    while(ADS_DATA_NOT_READY);  //AD����ת���ã�(ADS_IN & ADS_DATA_BIT)//AD_CLK���λ1
    for(uint8_t i = 0;i < 26;i ++)            //����26��CLK
    {
        ADS_CLK_H();
         delay_us(5);
        ADS_CLK_L();
    }   
}


/*****************************************************************************
�������ƣ�void InitADline(void)
��    �ܣ���ʼ��AD������
��ڲ�������
���ز�������
ʹ����Դ��port2
******************************************************************************/
void InitADline(void)
{
    ADS_PD_DIR_OUT();        //   ADS_DIR |= ADS_PD_BIT;
    AD_OFF()//������         //  ADS_OUT &= ~ADS_PD_BIT;
    ADS_DATA_DIR_IN();       //   ADS_DIR &= ~ADS_DATA_BIT;
    ADS_CLK_DIR_OUT();       //   ADS_DIR |= ADS_CLK_BIT;
    ADS_CLK_L();             //   ADS_OUT &= ~ADS_CLK_BIT;             
    ADS_SPEED_L();
    delay_us(26);
    AD_ON();  
    delay_us(10);
    //����ת��
}