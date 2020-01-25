#include <reg52.h>
#define uchar unsigned char
uchar Led1[]={0xaa,0x55,0xff};
uchar Led2[]={0x00,0xff};
sbit Beep3=P2^4;
void delay_ms3(unsigned int ms)
{
	uchar k;
	while(ms--)
	{
		for (k=0;k<114;k++);
	}
}
void c()
{
	int i=0,j=0;
	while(1)
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				P0=Led1[j];
				delay_ms3(100);
			}
			Beep3=0;
			delay_ms3(100);
			Beep3=1;
			delay_ms3(100);
		}
		for(i=0;i<3;i++)
		for(j=0;j<2;j++)
		{
			P0=Led2[j];
			delay_ms3(100);
		}
		while(1);
}
	
	
}	