#include "System_Init.h"

uint8_t InitFinish;	//��ʼ����ɱ�־


void system_Init(void)
{
	
	MX_GPIO_Init();
  MX_USART2_UART_Init();
	Interval_Time_Init();
	EEPROM_Init();
	
	InitFinish = 1;
	
}










