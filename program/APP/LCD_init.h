
/**************************Copyleft(C)liuyalou******************                
**-------------------File Info-------------------------------------
**File Name:     main.c
**Last modified Date:  2017.04.22
**MCU:           STC15W4K48S4
**Last Version:  1.0
**Descriptions:  
**Created by: LYL   
*******************************************************************/
#ifndef __LCD_INIT_H_
#define __LCD_INIT_H_


//#include "intrins.h"
//#include "USART.h"
#include "init.h" 



//uint8 code dian[];
uint8 code dian2[];
uint8 code no_dian[];


void delay(uint16 xdata i);
void Delay1(uint8  xdata i);
void initial_lcd();
void clear_screen();
void transfer_command(uint16 data1)	;
void transfer_data(uint16 data1);


//void address(uint8 page,uint8 column);

//void display_8x8(uint8 page,uint8 column,uint8 reverse,uint8 *dp);
//void display_graphic(uint8 page,uint8 column,uint8 *dp);
//void display_32x32(uint8 page,uint8 column,uint8 reverse,uint8 *dp);
//void display_32x32(uint8 page,uint8 column,uint8 *dp) ;
void display_16x16(uint8 page,uint8 column,uint8 *dp);
//void display_8x16(uint8 page,uint8 column,uint8 reverse,uint8 *dp);
//void display_string_8x16(uint16 page,uint16 column,uint8 *text);
//void display_string_5x8(uint16 page,uint16 column,uint8 *text);

//void display_data_12x24(uint8 page,uint8 column,uint8 dat);

void display_data_8x20(uint8 page,uint8 column,uint8 dat);
void TY_display(void);
//void display_data_20x40(uint8 page,uint8 column,uint8 dat);


#endif

