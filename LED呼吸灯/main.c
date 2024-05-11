#include <REGX52.H>

sbit LED = P2^0;

void Delay(unsigned int t)
{
	while(t--);
}

void main()
{
	while(1)
	{
		unsigned char Time,i;
		for(Time = 0;Time < 100;Time++)
		{
			for(i = 0;i < 20; i++)			//每个亮度延缓20次
			{
				LED = 0;
				Delay(Time);
				LED = 1;
				Delay(100-Time);
			}
		}
		for(Time = 100;Time > 0;Time--)
		{
			for(i = 0;i < 20; i++)			//每个亮度延缓20次
			{
				LED = 0;
				Delay(Time);
				LED = 1;
				Delay(100-Time);
			}
		}
	}
}