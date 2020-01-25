
#include <reg52.h>
#include <intrins.h>
#define uint unsigned int
#define uchar unsigned char
sbit wel1=P2^0;
sbit wel2=P2^1;
sbit wel3=P2^2;
sbit wel4=P2^3;
uchar code table11[]={0xc0,0xf9,0xa4,0xb0,0x99,
										0x92,0x82,0xf8,0x80,0x90};
void delay_ms11(unsigned int ms)
{
	unsigned char k;
	while(ms--)
	{
		for (k=0;k<114;k++);
	}
}
void display11(uint k)
{
	uchar a,b,c,d;
	a=k/1000;
	b=k/100%10;
	c=k/10%10;
	d=k%10;
	
	wel1=0;
	P0=table11[a];
	delay_ms11(5);
	wel1=1;
	
	
	wel2=0;
	P0=table11[b];
	delay_ms11(5);
	wel2=1;
	
	
	wel3=0;
	P0=table11[c];
	delay_ms11(5);
	wel3=1;
	
	
	wel4=0;
	P0=table11[d];
	delay_ms11(5);
	wel4=1;
	
}
uchar KeyScan11()
{
	uchar temh,teml,key;
	P1=0xf0;
	temh=P1;
	P1=0x0f;
	teml=P1;
	switch(temh)
	{
		case 0xe0:key=1;break;
		case 0xd0:key=2;break;
		case 0xb0:key=3;break;
		case 0x70:key=4;break;
		default: return 0;
	}
	switch(teml)
	{
		case 0x0e: return key;
		case 0x0d: return key+4;
		case 0x0b: return key+8;
		case 0x07: return key+12;
		default:return 0;
	}
}
void m()
{
	uchar result,temp=0x00;
	while(1)
	{
		result = KeyScan11();
		if(result!=0)
		{
			display11(temp*temp);
			temp=result;
		}
		else
		{
			display11(temp*temp);
		}
	}
}