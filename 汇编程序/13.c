#include <reg52.h>
#include <intrins.h>

	#define uint unsigned int
	#define uchar unsigned char
sbit wel1=P2^0;
sbit wel2=P2^1;
sbit wel3=P2^2;
sbit wel4=P2^3;
sbit Beep13=P2^4;
	uchar code table13[]={0xc0,0xf9,0xa4,0xb0,0x99,
										0x92,0x82,0xf8,0x80,0x90};
		uint n13=0;
	
		void delay_ms13(unsigned int ms)
{
	unsigned char k;
	while(ms--)
	{
		for (k=0;k<114;k++);
	}
}
void display13(uint k)
{
	uchar a,b,c,d;
	a=k/1000;
	b=k/100%10;
	c=k/10%10;
	d=k%10;
	
	wel1=0;
	P0=table13[a];
	delay_ms13(5);
	wel1=1;
	
	wel2=0;
	P0=table13[b];
	delay_ms13(5);
	wel2=1;
	
	
	wel3=0;
	P0=table13[c];
	delay_ms13(5);
	wel3=1;
	
	
	wel4=0;
	P0=table13[d];
	delay_ms13(5);
	wel4=1;
	
}
	void p()
	{
		int i;
		EA=1;
		EX0=1;
		IT0=0;
		while(1)
		{
			for(i=0;i++;i<15)
			display13(n13);
			delay_ms13(0);
			n13++;
		}
	}
	
	void exter0() interrupt 0
	{
		  int i;
			while(1)
			{		
				for(i=0;i++;i<15)
				display13(n13);
				if(n13==0)
				{
						Beep13=0;
						delay_ms13(500);
						Beep13=1;
						break;
				}
				delay_ms13(0);
				n13--;
			}
	}