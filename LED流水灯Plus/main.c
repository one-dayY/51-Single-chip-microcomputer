#include <REGX52.H>

void Delay1ms(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;
	
	while(xms)//��ֱ��whileѭ��500����������ѭ��������Ҫʹ�ñ������жϡ�
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		
		xms--;//ÿһ��ѭ������1ms��ֱ������500ms����ѭ����ʼ����һ���ƣ����µ��ú�����
	}
}

void main()
{
	while(1)
	{
		P2 = 0xFE;//1111 1110
		Delay1ms(500);//����ֱ�Ӵ�����Ҫ��ʱ��������
		//���Կ��Ʋ�ͬ�ĵ�֮��ʹ�ò�ͬ����ʱ����ֻ����һ������
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