#include <REGX52.H>

void Timer0_Init()
{
	//配置
	
	//TMOD = 0x01;  //只能配置一个定时器
	
	//TMOD = TMOD & 0xF0;  //把低四位的TMOD清零。高四位保持不变
	TMOD &= 0xF0;
	
	//TMOD = TMOD | 0x01;  //把低四位的TMOD置一，高四位保持不变
	TMOD |= 0x01;
	
	//TH0 = 64535 / 256;  //和十进制同样理解，除以10时小数点左移一位，除以256是在二进制里面小数点左移8位
	//TL0 = 64535 % 256;
	TL0 = 0;		//设置定时初值
	TH0 = 0;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 0;		//定时器0不计时
}

void Timer0_SetCounter(unsigned int Value)
{
	TH0 = Value / 256;
	TL0 = Value % 256;
}

unsigned int Timer0_GetCounter(void)
{
	return (TH0 << 8)|TL0;
}

void Timer0_Run(unsigned char Flag)
{
	TR0 = Flag;
}