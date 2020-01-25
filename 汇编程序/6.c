#include <reg52.h>
#include <intrins.h>
#define uint unsigned int
#define uchar unsigned char
sbit wel1=P2^0;
sbit wel2=P2^1;
sbit wel3=P2^2;
sbit wel4=P2^3;
sbit Beep6=P2^4;
uchar code table6[]={0xc0,0xf9,0xa4,0xb0,0x99,
										0x92,0x82,0xf8,0x80,0x90};
void delay_ms6(unsigned int ms)
{
	unsigned char k;
	while(ms--)
	{
		for (k=0;k<114;k++);
	}
}
void display6(uint k)
{
	uchar a,b,c,d;
	a=k/1000;
	b=k/100%10;
	c=k/10%10;
	d=k%10;
	
	wel1=0;
	P0=table6[a];
	delay_ms6(1000);
	wel1=1;
	Beep6=1;
	delay_ms6(100);
	Beep6=0;
	delay_ms6(100);
	
	wel2=0;
	P0=table6[b];
	delay_ms6(1000);
	wel2=1;
	Beep6=1;
	delay_ms6(100);
	Beep6=0;
	delay_ms6(100);
	
	wel3=0;
	P0=table6[c];
	delay_ms6(1000);
	wel3=1;
	Beep6=1;
	delay_ms6(100);
	Beep6=0;
	delay_ms6(100);
	
	wel4=0;
	P0=table6[d];
	delay_ms6(1000);
	wel4=1;
	Beep6=1;
	delay_ms6(100);
	Beep6=0;
	delay_ms6(100);
}
void f()
{
	while(1)
	{
		display6(4321);
	}
}