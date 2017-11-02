#ifndef __SYSTEM_SCHEDULER_H
#define __SYSTEM_SCHEDULER_H

#include "stm32f1xx_hal.h"

typedef struct
{
	uint8_t check_flag;//运行完毕标志
	uint8_t err_flag;//在预定周期没有运行完毕的错误计数
	
	int16_t period_cycle_2ms;
	int16_t period_cycle_5ms;
	int16_t period_cycle_10ms;
	int16_t period_cycle_20ms;
	int16_t period_cycle_50ms;
	int16_t period_cycle_100ms;

	
}task_t;

void Duty_1ms(void);
void Duty_2ms(void);
void Duty_5ms(void);
void Duty_10ms(void);
void Duty_20ms(void);
void Duty_50ms(void);
void Duty_100ms(void);
void main_task(void);
void call_task_timer(void);



#endif

















