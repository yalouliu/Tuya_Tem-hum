#ifndef __MYIIC_H
#define __MYIIC_H
//#include "STC12.h"
#include "init.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEKս��STM32������
//IIC���� ����	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/9
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////

//IO��������
 
/* #define SDA_IN()  {GPIOB->CRL&=0X0FFFFFFF;GPIOB->CRL|=(u32)8<<28;}
#define SDA_OUT() {GPIOB->CRL&=0X0FFFFFFF;GPIOB->CRL|=(u32)3<<28;} */
#define SDA_IN()  _nop_()
#define SDA_OUT() _nop_()

//IO��������	 
/* #define IIC_SCL    PBout(6) //SCL
#define IIC_SDA    PBout(7) //SDA	 
#define READ_SDA   PBin(7)  //����SDA  */
sbit IIC_SCL  =  P1^2 ; //SCL
sbit IIC_SDA  =  P1^0 ; //SDA	 
sbit READ_SDA =  P1^0 ; //����SDA 
//IIC���в�������
void IIC_Init(void);                //��ʼ��IIC��IO��				 
void IIC_Start(void);				//����IIC��ʼ�ź�
void IIC_Stop(void);	  			//����IICֹͣ�ź�
void IIC_Send_Byte(uint8 txd);			//IIC����һ���ֽ�
uint8 IIC_Read_Byte(unsigned char ack);//IIC��ȡһ���ֽ�
//uint8 IIC_Wait_Ack(void); 				//IIC�ȴ�ACK�ź�
void IIC_Ack(void);					//IIC����ACK�ź�
//void IIC_NAck(void);				//IIC������ACK�ź�

//void IIC_Write_One_Byte(uint8 daddr,uint8 addr,uint8 data);
//uint8 IIC_Read_One_Byte(uint8 daddr,uint8 addr);	  
#endif
















