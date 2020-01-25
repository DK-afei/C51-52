#include <reg52.h>
#include <intrins.h>
#define uint unsigned int
#define uchar unsigned char
sbit wel1=P2^0;
sbit wel2=P2^1;
sbit wel3=P2^2;
sbit wel4=P2^3;
uchar code table9[]={0x05,0x05,0x05,0x05};
void delay_ms9(unsigned int ms)
{
	unsigned char k;
	while(ms--)
	{
		for (k=0;k<114;k++);
	}
}
void display9()
{
	wel1=0;
	P0=table9[0];
	delay_ms9(5);
	wel1=1;
	
	wel2=0;
	P0=table9[1];
	delay_ms9(5);
	wel2=1;

	wel3=0;
	P0=table9[2];
	delay_ms9(5);
	wel3=1;
	
	wel4=0;
	P0=table9[3];
	delay_ms9(5);
	wel4=1;
}
void k()
{
	while(1)
	{
		display9();
	}
}