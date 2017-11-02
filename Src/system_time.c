#include "system_time.h"

#define GET_TIME_NUM	3						//��ȡʱ������
#define TICK_PER_SECOND		1000		//ÿ��δ����
#define TICK_US		(1000000/TICK_PER_SECOND)							//΢�뵽����

volatile uint32_t systickbreaktime = 0;		//ϵͳ�δ�ʱ�жϴ�����Ҫ����򲻱��Ż���ÿ�ε��ö���ֱ�Ӷ�ȡ��ֵ��

volatile float Interval_time[GET_TIME_NUM][3];		//�������ε��õ�ʱ����

enum			//ö��ʱ�����
{
	NOW = 0,
	OLD,
	NEW,
};

uint32_t GetSystemTime_us(void)	//��ȡ��ǰϵͳʱ�� ΢��
{
	register uint32_t ms;
	uint32_t value;
	ms = systickbreaktime;
	value = ms*TICK_US+(SysTick->LOAD - SysTick->VAL)*TICK_US/SysTick->LOAD;
	return value;
	
}


void Delay_us(uint32_t us)		//΢����ʱ
{
	uint32_t now = GetSystemTime_us();
	while(GetSystemTime_us() - now < us);
	
}

void Delay_ms(uint32_t ms)		//������ʱ
{
	while(ms--)Delay_us(1000);
	
}

float Call_time_cycle(uint8_t item) //��ȡ���ε�ʱ��������
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








