#include <REGX52.H>

void Int0_Init(void)
{
	IT0 = 1;  //1为下降沿触发，0为低电平触发
	IE0 = 0;
	EX0 = 1;
	EA = 1;
	PX0 = 1;  //中断其他的中断程序，以达到外部中断的绝对精度
}

/*
void Init0_Routine(void) interrupt 0
{
	
}
*/
