#include <reg52.h>
#include <intrins.h>
sbit Beep1=P2^4;
void delay_ms1(unsigned int z)
{
	unsigned char i,j;
	while(--z)
	{
		_nop_();
		i=2;
		j=199;
		do
		{
			while(--j);
		}while(--i);
	}
}
void a()
{
	int m=0,n=0;
	P0=0xff;
	while(1)
	{
		P0=0xaa;
		delay_ms1(100);
		P0=0x55;
		delay_ms1(100);
		Beep1=0;
		delay_ms1(100);
		Beep1=1;
		delay_ms1(100);
		m++;
		if(m==3)
			while(1)
			{
					P0=0x00;
					delay_ms1(100);
					P0=0xff;
					delay_ms1(100);
					n++;
					if(n==3)
					while(1);
						
			};
	
	}
	
}