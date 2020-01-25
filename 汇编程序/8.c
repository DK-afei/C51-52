#include <reg52.h>
#include <intrins.h>
#define uchar unsigned char;
#define uint unsigned int;
sbit key8=P3^2;
sbit Beep8=P2^4;
void delay_ms8(unsigned int ms)
{
	unsigned char k;
	while(ms--)
	{
		for(k=0;k<114;k++);
	}
}

void keyscan8()
{
	if(key8==0)
	{
		delay_ms8(10);
		if(key8==0)
		{
			delay_ms8(10);
			if(key8==0)
			{
				Beep8=0;
			}
			while(!key8);
			delay_ms8(10);
			while(!key8);
		}
		else
			Beep8=1;
	}
}
void h()
{
	while(1)
	{
		keyscan8();
	}
}