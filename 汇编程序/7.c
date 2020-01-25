#include <reg52.h>
#include <intrins.h>
#define uchar unsigned char;
#define uint unsigned int;
sbit key7=P3^2;
sbit Beep7=P2^4;
void keyscan7()
{
	if(key7==0)
	{
		Beep7=0;
		while(!key7);
	}
	else
		Beep7=1;
}
void g()
{
	while(1)
	{
		keyscan7();
	}
}
