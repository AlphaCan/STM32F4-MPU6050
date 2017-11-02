#ifndef __SYSTEM_TIME_H
#define __SYSTEM_TIME_H

#include "stm32f1xx_hal.h"

extern volatile uint32_t systickbreaktime;

uint32_t GetSystemTime_us(void);	//获取当前系统时间 微秒
void Delay_us(uint32_t us);		//微秒延时
void Delay_ms(uint32_t ms);		//毫秒延时
float Call_time_cycle(uint8_t item); //获取两次的时间间隔，秒
void Interval_Time_Init(void);



#endif



















