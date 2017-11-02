#include "system_time.h"

#define GET_TIME_NUM	3						//获取时间组数
#define TICK_PER_SECOND		1000		//每秒滴答次数
#define TICK_US		(1000000/TICK_PER_SECOND)							//微秒到毫秒

volatile uint32_t systickbreaktime = 0;		//系统滴答定时中断次数（要求程序不被优化，每次调用都有直接读取该值）

volatile float Interval_time[GET_TIME_NUM][3];		//计算两次调用的时间间隔

enum			//枚举时间变量
{
	NOW = 0,
	OLD,
	NEW,
};

uint32_t GetSystemTime_us(void)	//获取当前系统时间 微秒
{
	register uint32_t ms;
	uint32_t value;
	ms = systickbreaktime;
	value = ms*TICK_US+(SysTick->LOAD - SysTick->VAL)*TICK_US/SysTick->LOAD;
	return value;
	
}


void Delay_us(uint32_t us)		//微秒延时
{
	uint32_t now = GetSystemTime_us();
	while(GetSystemTime_us() - now < us);
	
}

void Delay_ms(uint32_t ms)		//毫秒延时
{
	while(ms--)Delay_us(1000);
	
}

float Call_time_cycle(uint8_t item) //获取两次的时间间隔，秒
{
	Interval_time[item][OLD] = Interval_time[item][NOW];
	Interval_time[item][NOW] = GetSystemTime_us()/1000000.0f;
	Interval_time[item][NEW] = (Interval_time[item][NOW] - Interval_time[item][OLD]);
	return Interval_time[item][NEW];
}


void Interval_Time_Init(void)
{
	for(uint8_t i =0;i<GET_TIME_NUM;i++)
	Call_time_cycle(i);
}








