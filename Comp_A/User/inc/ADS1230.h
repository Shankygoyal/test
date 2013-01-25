#ifndef __ADS1230_H
#define __ADS1230_H

/**********************************************************************
                      ADS1230
*   �ӿڶ��壺DOUT<--->P2.0; SCLK<--->P2.1; PDWN<--->P2.2   *
***********************************************************************/
//#define ADS_IE                  P2IE
//#define ADS_IFG                 P2IFG
#define ADS_REN                 P1REN
#define ADS_DIR                 P1DIR
#define ADS_OUT                 P1OUT
#define ADS_IN                  P1IN
#define ADS_DATA_BIT            BIT0  //ADS_DOUT
#define ADS_CLK_BIT             BIT5  //ADS_CLK
#define ADS_PD_BIT              BIT6  //ADS_PDWN
#define ADS_SPEED_BIT           BIT7  //ADS_speed
////    P3DIR |= BIT7; //speed
////    P3OUT|=BIT7;
//#define ADS_DATA_DIR_OUT()       ADS_DIR |= ADS_DATA_BIT;
#define ADS_DATA_DIR_IN()      ADS_DIR &= ~ADS_DATA_BIT;
// {ADS_REN |= ADS_DATA_BIT;}
#define ADS_CLK_DIR_OUT()       ADS_DIR |= ADS_CLK_BIT;
#define ADS_PD_DIR_OUT()        ADS_DIR |= ADS_PD_BIT;

#define AD_IS_ON                (ADS_OUT & ADS_PD_BIT)                  
#define AD_ON()                 ADS_OUT |=  ADS_PD_BIT;                  
#define AD_OFF()                ADS_OUT &= ~ADS_PD_BIT;

#define ADS_DATA_H()            ADS_OUT |= ADS_DATA_BIT;

#define ADS_CLK_H()             ADS_OUT |= ADS_CLK_BIT;
#define ADS_CLK_L()             ADS_OUT &= ~ADS_CLK_BIT;

#define ADS_SPEED_H()             ADS_OUT |= ADS_SPEED_BIT;
#define ADS_SPEED_L()             ADS_OUT &= ~ADS_SPEED_BIT;


#define ADS_DATA_HI             (ADS_IN & ADS_DATA_BIT)//AD_DATA���λ1
#define ADS_DATA_NOT_READY      (ADS_IN & ADS_DATA_BIT)//AD_CLK���λ1



long  ReadAD(void);    //��AD�����������϶�ȡAD���������,���ڲ�ѯ���ж��е���
void  OffsetAD(void);  //ʧ��У׼��һ������������AD�󣬽���һ��ADУ׼
void  InitADline(void);//��ʼ��AD�����ߣ�������ADǰ����
#endif
/************************************END***************************************/