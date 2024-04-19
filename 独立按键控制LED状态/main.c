#include <REGX52.H>

void Delay(unsigned int xms)
{
	unsigned char i, j;
	while(xms)
		
	{
		i = 12;
		j = 169;
		do
		{
			while (--j);
		} while (--i);
		xms--;
	}
}


void main()
{
	while(1)
	{
		if(P3_1 == 0)
		{
			//当按键时无变化，松手时灯亮
			
			Delay(20);//按键消抖
			while(P3_1 == 0);
			Delay(20);//松手消抖
			
			P2_0 = ~P2_0;
		}
		
	}
}