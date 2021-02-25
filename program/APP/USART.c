/**************************Copyleft(C)LYL&BIOBASE****************************                 
**-------------------File Info-------------------------------------
**File Name:     
**Last modified Date:  2017.04.22
**MCU:           STC15W4K48S4
**Last Version:  1.0
**Descriptions:  
**Created by: LYL   
*******************************************************************/

#include "USART.h"
#include <stdio.h>
#include "STC12.h"
#include "wifi.h"


extern  uint8  eeprom_data;
idata uint8 RxBuffer[14]={0xab,1,2,3,4,5,6,7,8,9,10,11,12,0xba};
idata uint8 rebuff=0;
idata uint8 usart_RData = 0;



void USART_Init(void) 
{
	PCON &= 0x7F;		//波特率不倍速
	SCON = 0x50;		//8位数据,可变波特率
	AUXR |= 0x40;		//定时器1时钟为Fosc,即1T
	AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
	//AUXR =0x00;
	TMOD |= 0x20;        //将定时器1设置为方式2，8位自动重装模式
	TH1 = 0xD9;         //12M晶振，波特率9600
	TL1 = 0xD9;

	TR1 = 1;//开启定时器1
  	REN=1;
	SM0=0;
	SM1=1;
	//TI=1;
	EA = 1;//开启总中断
  	ES = 1;//开启串口中断
}

void sendchar(uint8 num)
{  
		ES= 0;  
		SBUF = num;
    while(!TI)
	{
	 // P52 ^= 1;
	}
		TI = 0;
		ES= 1;
		
}

/*----------------------------
Send a string to UART
Input: s (address of string)
Output:None
----------------------------*/
/* void SendString(uint8 *s)
{
  idata uint8 i=0;  
	idata uint8 j=0;
	
	while (*s)              //Check the end of the string
    {
        sendchar(*s++);     //Send current char and increment string ptr
				//&s++;
				for(i=200;i >1;i--);
    }
}
//閲嶅啓putchar鍑芥�?
char putchar(char c)
{
	sendchar(c);
	return c;
} */
 



void ser() interrupt 4	//usart receive
{
    idata uint8 temp = 0;
	//static uint8 rec_check = 0;
    //static uint8 rec_num = 0;	
    if(RI)
	{
		//RxBuffer[rec_num] = SBUF;
		temp = SBUF;
		usart_RData = temp;
		uart_receive_input(temp);
		RI =0; //?????�?????????
		
		
		
	}
	
	
}

