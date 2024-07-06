#include <REGX52.H>
#include "Timer0.h"
#include "Int0.h"

unsigned int IR_Time;
unsigned char IR_State;

unsigned char IR_Data[4];
unsigned char IR_pData;

unsigned char IR_DataFlag;
unsigned char IR_RepeatFlag;
unsigned char IR_Address;
unsigned char IR_Command;

void IR_Init()
{
	Timer0_Init();
	Int0_Init();
}

unsigned char IR_GetDataFlag(void)
{
	if(IR_DataFlag)
	{
		IR_DataFlag = 0;
		return 1;
	}
	return 0;
}

unsigned char IR_GetRepeatFlag(void)
{
	if(IR_RepeatFlag)
	{
		IR_RepeatFlag = 0;
		return 1;
	}
	return 0;
}

unsigned char IR_GetAddress(void)
{
	return IR_Address;
}

unsigned char IR_GetCommand(void)
{
	return IR_Command;
}

void Init0_Routine(void) interrupt 0
{
	if(IR_State == 0)
	{
		
		Timer0_SetCounter(0);	//计数器清零
		Timer0_Run(1);			//开始计时
		IR_State = 1;
	}
	else if(IR_State == 1)
	{
		IR_Time = Timer0_GetCounter();	//取出时间
		Timer0_SetCounter(0);	//立马清零，方便下一次计时
		
		if(IR_Time >= 13500-1500 && IR_Time <= 13500+1500)		//Strat
		{
			IR_State = 2;
		}
		else if(IR_Time >= 11250-1500 && IR_Time <= 11250+1500)	//Repeat
		{
			IR_RepeatFlag = 1;
			Timer0_Run(0);			//停止计时
			IR_State = 0;
		}
		else
		{
			IR_State = 1;
		}
	}
	else if(IR_State == 2)
	{
		IR_Time = Timer0_GetCounter();	//取出时间
		Timer0_SetCounter(0);	//立马清零，方便下一次计时
		
		if(IR_Time >= 1120-500 && IR_Time <= 1120+500)
		{
			//IR_Data[0] &= ~(0x01 << IR_pData)
			IR_Data[IR_pData/8] &= ~(0x01<<(IR_pData%8));	//在IR_Data数组中清除一个特定位的值
			//&与 相应位置为0不影响其他位
			//|或 相应位置为1不影响其他位
			
			//0x01<<(IR_pData%8)创建一个只有指定位为1，其他位为0的掩码
			//IR_pData%8计算出这个位在字节中的偏移量
			//IR_pData/8计算出这个位在字节数组中的索引
			//IR_Data数组中的某一位设置为0，即清楚该位的值。
			//IR_pData表示当前操作的位在数组IR_Data中的位置，即数组的索引。0-31变化
			
			IR_pData++;
		}
		else if(IR_Time >= 2250-500 && IR_Time <= 2250+500)
		{
			IR_Data[IR_pData/8] |= (0x01<<(IR_pData%8));
			IR_pData++;
			/*
			|= 两个二进制对应位都为0时，结果为0，否则结果等于1
			&= 两个二进制对应位都为1时，结果为1，否则结果等于0
			*/
		}
		else
		{
			IR_pData = 0;
			IR_State = 1;
		}
		
		if(IR_pData >= 32)
		{
			IR_pData = 0;
			if((IR_Data[0] == ~IR_Data[1]) && (IR_Data[2] == ~IR_Data[3]))	//地址码和命令码相反
			{
				IR_Address = IR_Data[0];
				IR_Command = IR_Data[2];
				IR_DataFlag = 1;
			}
			Timer0_Run(0);
			IR_State = 0;
		}
	}
}