/***************************************************************************************************
  * ��    ����BCSC.C    
  * ��    �ߣ�longwei
  * ��д���ڣ�2012/5/24
  * ��    ����V1.0
  * �� �� �壺MSP430G2553 TI������
  * �޸�ʱ�䣺�� 
  * �� �� ��: IAR.5.20
  *-------------------------------------------------------------------------------------------------
  * ��    �飺MSP430����ʱ�ӵ�����     
  *************************************************************************************************/
/*����--------------------------------------------------------------------------------------------*/
#include "BCSC.h"
/* ˽�ж���ṹ�� --------------------------------------------------------------------------------*/
/* ˽�к�-----------------------------------------------------------------------------------------*/
/* ˽�б��� --------------------------------------------------------------------------------------*/

/***************************************************************************************************
  * ����   : DCOCLKʱ������
  * ����   : DCO_Bool:ʱ��Ƶ��
  * ����   : ��
  * ע��   : DCOCLK���Ƶ���빤����ѹ�����Թ�ϵ������ע�⹤����ѹ�Ƿ�����
  *          ʱ�����øú���Ӧ�ȵ��ã������Ӱ������ʱ�����ú����ĵ���
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
  * ����   : ACLKʱ������
  * ����   : ACLK_Bool: ACLK Source ACLK_DIV��Divider
  * ����   : ��
  * ע��   : ���������ø�ͷ�ļ�����Ĳ���
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
  * ����   : MCLKʱ������
  * ����   : MCLK_Bool: ACLK Source SMCLK_DIV��Divider
  * ����   : ��
  * ע��   : ���������ø�ͷ�ļ�����Ĳ���
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
  * ����   : SMCLKʱ������
  * ����   : SMCLK_Bool: SMCLK Source SMCLK_DIV��Divider
  * ����   : ��
  * ע��   : ���������ø�ͷ�ļ�����Ĳ���
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
/******************* (C) ��Ȩ 2012 longwei *****�ļ�����*******************************************/
