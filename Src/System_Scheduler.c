#include "System_Scheduler.h"
#include "usart.h"


task_t task;

void Duty_1ms(void)
{
	
}


void Duty_2ms(void)
{
	
}

void Duty_5ms(void)
{
	
}

void Duty_10ms(void)
{
//	printf("正在运行10ms任务\r\n");
}

void Duty_20ms(void)
{
	
}

void Duty_50ms(void)
{
//	printf("正在运行50ms任务\r\n");
}

void Duty_100ms(void)
{
	printf("正在运行100ms任务\r\n");
}

void main_task(void)
{
	if(task.check_flag == 1)
	{
		Duty_1ms();
		if(task.period_cycle_2ms >= 2)
		{
			task.period_cycle_2ms = 0;
			Duty_2ms();
		}
		if(task.period_cycle_5ms >= 5)
		{
			task.period_cycle_5ms = 0;
			Duty_5ms();
		}
		if(task.period_cycle_10ms >= 10)
		{
			task.period_cycle_10ms = 0;
			Duty_10ms();
		}
		if(task.period_cycle_20ms >= 20)
		{
			task.period_cycle_20ms = 0;
			Duty_20ms();
		}
		if(task.period_cycle_50ms >= 50)
		{
			task.period_cycle_50ms = 0;
			Duty_50ms();
		}
		if(task.period_cycle_100ms >= 100)
		{
			task.period_cycle_100ms = 0;
			Duty_100ms();
		}
		task.check_flag = 0;//运行完毕标志清零
	}
}


void call_task_timer(void)
{
	task.period_cycle_2ms++;
	task.period_cycle_5ms++;
	task.period_cycle_10ms++;
	task.period_cycle_20ms++;
	task.period_cycle_50ms++;
	task.period_cycle_100ms++;
	
	if(task.check_flag == 1)
		task.err_flag++;
	else
		task.check_flag = 1;
	
}











