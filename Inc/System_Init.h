#ifndef __SYSTEM_INIT_H
#define  __SYSTEM_INIT_H

#include "stm32f1xx_hal.h"
#include "usart.h"
#include "gpio.h"
#include "system_time.h"
#include "Flash_To_Eeprom.h"



extern uint8_t InitFinish;	//��ʼ����ɱ�־
void system_Init(void);


#endif











