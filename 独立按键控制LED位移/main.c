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
			LEDNum++;//ֱ������P2_0
			
			Delay(20);
			while(P3_1 == 0);
			Delay(20);
			
			if(LEDNum >= 8)//LEDģ��λP2_0��P2_7
				LEDNum = 0;
			P2 = ~(0x01<<LEDNum);//ʮ�����ư�λ����
			
			//LEDNum++;//��Ҫ��������LED�Ʊ仯
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