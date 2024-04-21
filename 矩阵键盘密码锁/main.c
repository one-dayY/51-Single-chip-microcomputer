#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum = 0;
unsigned int Password = 0;
unsigned int count = 0;

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Password");
	
	while(1)
	{
		KeyNum = MatrixKey();
		
		if(KeyNum)
		{
			if(KeyNum <= 10) //如果s1—s10按下，输入密码
			{
				if(count < 4)
				{
					Password *= 10;  //密码左移一位   //0001变成0010
					
					Password += KeyNum % 10;   //获取一位密码并且加到原密码左移后的数值上
					
					count++;	
				}
				LCD_ShowNum(2,1,Password,4);   //更新显示
			}
			if(KeyNum == 11)  //将s11定义为确认键
			{
				if(Password == 2109) //首位不可以为0
				{
					LCD_ShowString(1,10,"Success");
					Password = 0;   //密码清零
					count = 0;      //计次清零
					LCD_ShowNum(2,1,Password,4);   //更新显示
				}
				else
				{
					LCD_ShowString(1,12,"Fail");
					Password = 0;   //密码清零
					count = 0;      //计次清零
					LCD_ShowNum(2,1,Password,4);   //更新显示
				}
			}
			if(KeyNum == 12)  //将s12定义为取消键
			{
				Password = 0;   //密码清零
				count = 0;      //计次清零
				LCD_ShowNum(2,1,Password,4);   //更新显示
			}
		}
	}
}