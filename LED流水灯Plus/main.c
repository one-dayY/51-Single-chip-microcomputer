#include <REGX52.H>

void Delay1ms(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;
	
	while(xms)//若直接while循环500，则会进入死循环。必须要使用变量来判断。
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		
		xms--;//每一次循环都减1ms，直到超过500ms结束循环开始亮下一个灯，重新调用函数。
	}
}

void main()
{
	while(1)
	{
		P2 = 0xFE;//1111 1110
		Delay1ms(500);//可以直接传参需要延时的秒数。
		//可以控制不同的灯之间使用不同的延时。且只定义一个函数
		P2 = 0xFD;//1111 1101
		Delay1ms(100);
		P2 = 0xFB;//1111 1011
		Delay1ms(500);
		P2 = 0xF7;//1111 0111
		Delay1ms(1000);
		P2 = 0xEF;//1110 1111
		Delay1ms(500);
		P2 = 0xDF;//1101 1111
		Delay1ms(200);
		P2 = 0xBF;//1011 1111
		Delay1ms(400);
		P2 = 0x7F;//0111 1111
		Delay1ms(500);
	}
}