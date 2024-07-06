#include <REGX52.H>

/**
  * @brief  定时器1初始化，100微秒，11.0592MHz
  * @param  无
  * @retval 无
  */
void Timer1_Init()
{
	//配置
	
	//TMOD = 0x01;  //只能配置一个定时器
	
	//TMOD = TMOD & 0xF0;  //把低四位的TMOD清零。高四位保持不变
	TMOD &= 0x0F;
	
	//TMOD = TMOD | 0x01;  //把低四位的TMOD置一，高四位保持不变
	TMOD |= 0x0;
	
	TF1 = 0;
	TR1 = 1;
	//TH1 = 64535 / 256;  //和十进制同样理解，除以10时小数点左移一位，除以256是在二进制里面小数点左移8位
	//TL1 = 64535 % 256;
	TL1 = 0xA4;		//设置定时初值
	TH1 = 0xFF;		//设置定时初值
	
	ET1 = 1;
	EA = 1;
	PT1 = 0;
}

/*定时器中断函数模板
void Timer1_Routine(void) interrupt 3 
{
	static unsigned int T1Count;

	TL1 = 0xA4;
	TH1 = 0xFF;
	T1Count++;
	if(T1Count >= 1000)
	{
		T1Count = 0;
	}
}
*/