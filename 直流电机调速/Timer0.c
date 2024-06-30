#include <REGX52.H>

/**
  * @brief  定时器0初始化，100微秒，11.0592MHz
  * @param  无
  * @retval 无
  */
void Timer0_Init()
{
	//配置
	
	//TMOD = 0x01;  //只能配置一个定时器
	
	//TMOD = TMOD & 0xF0;  //把低四位的TMOD清零。高四位保持不变
	TMOD &= 0xF0;
	
	//TMOD = TMOD | 0x01;  //把低四位的TMOD置一，高四位保持不变
	TMOD |= 0x01;
	
	TF0 = 0;
	TR0 = 1;
	//TH0 = 64535 / 256;  //和十进制同样理解，除以10时小数点左移一位，除以256是在二进制里面小数点左移8位
	//TL0 = 64535 % 256;
	TL0 = 0xA4;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	
	ET0 = 1;
	EA = 1;
	PT0 = 0;
}

/*定时器中断函数模板
void Timer0_Routine(void) interrupt 1 
{
	static unsigned int T0Count;

	TL0 = 0xA4;
	TH0 = 0xFF;
	T0Count++;
	if(T0Count >= 1000)
	{
		T0Count = 0;
	}
}
*/