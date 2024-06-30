#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "Timer0.h"
#include "Nixie.h"

unsigned char Counter,Compare;
unsigned char KeyNum,Speed;

sbit Motor = P1^0;

void main()
{
	Timer0_Init();
	Compare = 5;
	while(1)
	{
		KeyNum = Key();
		if(KeyNum == 1)
		{
			Speed++;
			Speed %= 4;
        if(Speed == 0){Compare = 0;}
		if(Speed == 1){Compare = 50;}
		if(Speed == 2){Compare = 75;}
		if(Speed == 3){Compare = 90;}
		}
		Nixie(1,Speed);
	}
}

void Timer0_Routine(void) interrupt 1 
{
	TL0 = 0xA4;
	TH0 = 0xFF;
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