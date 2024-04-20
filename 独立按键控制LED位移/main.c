#include <REGX52.H>

void Delay(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;
	while(xms)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		xms--;
	}
}

void main()
{
	unsigned char LEDNum;
	
	while(1)
	{
		if(P3_1 == 0)
		{
			LEDNum++;//直接跳过P2_0
			
			Delay(20);
			while(P3_1 == 0);
			Delay(20);
			
			if(LEDNum >= 8)//LED模块位P2_0到P2_7
				LEDNum = 0;
			P2 = ~(0x01<<LEDNum);//十六进制按位左移
			
			//LEDNum++;//需要按键两次LED灯变化
		}
		
		if(P3_0 == 0)
		{
			Delay(20);
			while(P3_0 == 0);
			Delay(20);
			
			if(LEDNum == 0)
				LEDNum = 7;
			else
				LEDNum--;
			P2 = ~(0x01<<LEDNum);
		}
	}
}