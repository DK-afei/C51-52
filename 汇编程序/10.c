#include <reg52.h>
#include <intrins.h>
#define uint unsigned int
#define uchar unsigned char
sbit wel1=P2^0;
sbit wel2=P2^1;
sbit wel3=P2^2;
sbit wel4=P2^3;
sbit Beep10=P2^4;
uchar code table101[]={0xc0,0xf9,0xa4,0xb0,0x99,
										0x92,0x82,0xf8,0x80,0x90};
uchar code table102[]={0x89,0x86,0xc7,0xc0};
void delay_ms10(unsigned int ms)
{
	unsigned char k;
	while(ms--)
	{
		for (k=0;k<114;k++);
	}
}
void display102()
{
	wel1=0;
	P0=table102[0];
	delay_ms10(5);
	wel1=1;
	
	wel2=0;
	P0=table102[1];
	delay_ms10(5);
	wel2=1;

	wel3=0;
	P0=table102[2];
	delay_ms10(5);
	wel3=1;
	
	wel4=0;
	P0=table102[3];
	delay_ms10(5);
	wel4=1;
}

void display101(uint k)
{
	uchar a,b,c,d;
	a=k/1000;
	b=k/100%10;
	c=k/10%10;
	d=k%10;
	
	wel1=0;
	P0=table101[a];
	delay_ms10(5);
	wel1=1;
	
	wel2=0;
	P0=table101[b];
	delay_ms10(5);
	wel2=1;
	
	
	wel3=0;
	P0=table101[c];
	delay_ms10(5);
	wel3=1;
	
	
	wel4=0;
	P0=table101[d];
	delay_ms10(5);
	wel4=1;
	
}
void l()
{
	int n=9000;
	int m=0;
		while(1)
		{
			display101(n);
			delay_ms10(10);
			n--;
			if(n==8888)
			while(1)
							{		
										display101(8888);
										delay_ms10(100);
										P0=0x00;
										delay_ms10(100);
										P0=0xff;
										delay_ms10(100);
										Beep10=0;
										delay_ms10(100);
										Beep10=1;
										delay_ms10(100);
										m++;
										if(m==3)
										{
											while(1){display102();};
										}
									}
		}
}


