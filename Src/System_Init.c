#include "System_Init.h"

uint8_t InitFinish;	//初始化完成标志


void system_Init(void)
{
	
	MX_GPIO_Init();
  MX_USART2_UART_Init();
	Interval_Time_Init();
	EEPROM_Init();
	
	InitFinish = 1;
	
}










