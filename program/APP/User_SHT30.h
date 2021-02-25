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
	
	signed int temper;                                        //温度
    uint8_t humidity;                                         //湿度
	//uint8_t Power;                                            //电量
	//uint16_t SAMPLING;                                        //采样时间
	//uint32_t Timer_Sec_Value;                                 //秒
	//uint32_t Timer_Min_Value;                                 //分
	//uint32_t Timer_Hour_Value;                                //时
	
	
} TYPE_BUFFER_S;

extern TYPE_BUFFER_S FlashBuffer;

/*****************************************************************************
函数名称 : SHT_Init
功能描述 : SHT30初始化
输入参数 : 无
返回参数 : 无
使用说明 : 无
*****************************************************************************/
void SHT_Init();
/*****************************************************************************
函数名称 : sht30_read
功能描述 : SHT30数据读取，通过oled显示
输入参数 : 无
返回参数 : 无
使用说明 : 无
*****************************************************************************/
void sht30_read();


#endif

