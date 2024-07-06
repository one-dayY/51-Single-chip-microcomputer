#include <REGX52.H>
#include "Timer1.h"

unsigned char Counter,Compare;

sbit Motor = P1^0;

void Motor_Init()
{
	Timer1_Init();
}

void Motor_SetSpeed(unsigned char Speed)
{
	Compare = Speed;
}

void Timer1_Routine(void) interrupt 3 
{
	TL1 = 0xA4;
	TH1 = 0xFF;
	Counter++;
	Counter %= 100;     // if(Counter >= 100)  Counter = 0;
	
	if(Counter < Compare)
	{
		Motor = 1;
	}
	else
	{
		Motor = 0;
	}
}