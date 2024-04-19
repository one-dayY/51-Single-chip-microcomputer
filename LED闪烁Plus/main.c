#include <REGX52.H>

void Delay(xms)		//@12.000MHz
{
	while(xms)
	{
		unsigned char i, j;

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
	while(1)
	{
		P2_0 = 0;
		Delay(500);
		P2_0 = 1;
		Delay(500);
	}
}