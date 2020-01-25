#include <reg52.h>
#include <intrins.h>
sbit Led1=P0^0;
sbit Led2=P0^1;
sbit Led3=P0^2;
sbit Led4=P0^3;
sbit Led5=P0^4;
sbit Led6=P0^5;
sbit Led7=P0^6;
sbit Led8=P0^7;
sbit Beep2=P2^4;
void delay_ms2(unsigned int ms)
{
	unsigned char k;
	while(ms--)
	{
		for (k=0;k<114;k++);
	}
}
void b()
{
	int m=0,n=0;
	while(1)
	{
		Led1=0;
		Led3=0;
		Led5=0;
		Led7=0;
		delay_ms2(100);
		Led1=1;
		Led3=1;
		Led5=1;
		Led7=1;
		delay_ms2(100);
		Led2=0;
		Led4=0;
		Led6=0;
		Led8=0;
		delay_ms2(100);
		Led2=1;
		Led4=1;
		Led6=1;
		Led8=1;
		delay_ms2(100);
		Beep2=0;
		delay_ms2(100);
		Beep2=1;
		delay_ms2(100);
		m++;
		if(m==3)
			while(1)
			{
					Led1=1;
					Led2=1;
					Led3=1;
					Led4=1;
					Led5=1;
					Led6=1;
					Led7=1;
					Led8=1;
					delay_ms2(100);
					Led1=0;
					Led2=0;
					Led3=0;
					Led4=0;
					Led5=0;
					Led6=0;
					Led7=0;
					Led8=0;
					delay_ms2(100);
					n++;
					if(n==3)
					{	
						Led1=1;
						Led2=1;
						Led3=1;
						Led4=1;
						Led5=1;
						Led6=1;
						Led7=1;
						Led8=1;
						while(1);
					}
			}
	}
}

