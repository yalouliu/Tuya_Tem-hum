#ifndef __USER_SHT30_H__
#define __USER_SHT30_H__


#ifdef USER_SHT30_GLOBALS
#define USER_SHT30_EXT
#else
#define USER_SHT30_EXT extern 
#endif

#define uint8_t uint8
#define uint16_t uint16
/*******************************************************/
#define PERIODIC_MODE_05S 0x2032// 0.5mps
#define PERIODIC_MODE_1S  0x2130// 1mps  
#define PERIODIC_MODE_2S  0x2236// 2mps  
#define PERIODIC_MODE_4S  0x2334// 4mps  
#define PERIODIC_MODE_10S 0x2737// 10mps 
/********************************************************/

typedef struct {
	
	signed int temper;                                        //�¶�
    uint8_t humidity;                                         //ʪ��
	//uint8_t Power;                                            //����
	//uint16_t SAMPLING;                                        //����ʱ��
	//uint32_t Timer_Sec_Value;                                 //��
	//uint32_t Timer_Min_Value;                                 //��
	//uint32_t Timer_Hour_Value;                                //ʱ
	
	
} TYPE_BUFFER_S;

extern TYPE_BUFFER_S FlashBuffer;

/*****************************************************************************
�������� : SHT_Init
�������� : SHT30��ʼ��
������� : ��
���ز��� : ��
ʹ��˵�� : ��
*****************************************************************************/
void SHT_Init();
/*****************************************************************************
�������� : sht30_read
�������� : SHT30���ݶ�ȡ��ͨ��oled��ʾ
������� : ��
���ز��� : ��
ʹ��˵�� : ��
*****************************************************************************/
void sht30_read();


#endif

