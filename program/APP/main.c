/**************************Copyleft(C)LYL&BIOBASE******************                
**-------------------File Info-------------------------------------
**File Name:     main.c
**Last modified Date:  2017.04.22
**MCU:           STC15W4K48S4
**Last Version:  1.0
**Descriptions:  
**Created by: LYL   
*******************************************************************/

//#include "STC15W.h"
#include "STC12.h"
#include "wifi.h"
#include "USART.h"
#include "myiic.h"
//#include "EEPROM.h"
#include "LCD_init.h"
#include "User_SHT30.h"
//#include "LCD.h"
//#include "control.h"
//#include <stdio.h>
//#include "DS1302.h"
//#include<intrins.h>

extern idata uint8 usart_RData;
uint8 usert_temp;

void delay_2(unsigned int z)//1ms延时 
{ 
	unsigned char x,x1; 
	for(;z>0;z--) 
	{ 
		for(x=0;x<114;x++) 
		{ 
			for(x1=0;x1<1;x1++); 
		} 
	} 
}

 
void PortInit(void)
{
   
 
	P1M1=0xD5;
	P1M0=0x23;
	P2M1=0xBF; 
	P2M0= 0x40;
	P3M1=0xA0; 
	P3M0= 0x00;

	IT0 = 1;                        //set INT0 int type (1:Falling 0:Low level)	
    EX0 = 0;                        //enable INT0 interrupt
	IT1 = 1;                        //set INT1 int type (1:Falling 0:Low level)
	EX1 = 0;                        //enable INT0 interrupt
    EA = 1;                         //open global interrupt switch
}

void LED_CTR(void)
{
	static uint8 i = 0;
	i++;
	if(i < 30)
	{
		LED_TEST = 0;
	}
	else if( i < 60)
	{
		LED_TEST = 1;
	}
	else i =0;
}
void main(void)
{
	delay_2(50);
	PortInit();
	IIC_Init();
	initial_lcd();
	clear_screen();
	SHT_Init();
	USART_Init();
	wifi_protocol_init();
	while(1)
	{  
		wifi_uart_service();
		//sht30_read();
		mcu_dp_value_update(DPID_TEMP_CURRENT,300);     //VALUE型数据上报;
		mcu_dp_value_update(DPID_HUMIDITY_VALUE,98); //VALUE型数据上报;
		TY_display();
		//LED_TEST = 0;
//		if(usert_temp != usart_RData)
//		{
//			sendchar(usart_RData);
//			usert_temp = usart_RData;
//		}
		
		// sendchar(0x55);
		// sendchar(0x44);
		// sendchar(0x33);
		LED_CTR();
	}
}


