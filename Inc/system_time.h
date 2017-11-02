#ifndef __SYSTEM_TIME_H
#define __SYSTEM_TIME_H

#include "stm32f1xx_hal.h"

extern volatile uint32_t systickbreaktime;

uint32_t GetSystemTime_us(void);	//��ȡ��ǰϵͳʱ�� ΢��
void Delay_us(uint32_t us);		//΢����ʱ
void Delay_ms(uint32_t ms);		//������ʱ
float Call_time_cycle(uint8_t item); //��ȡ���ε�ʱ��������
void Interval_Time_Init(void);



#endif



















