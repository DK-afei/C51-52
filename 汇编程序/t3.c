#include <reg52.h>
#define uchar unsigned char
#define uint unsigned int
sbit w1=P2^0;
sbit w2=P2^1;
sbit w3=P2^2;
sbit w4=P2^3;
uchar code table[]={0xc0,0xf9,0xa4,0xb0,0x99,
						0x92,0x82,0xf8,0x80,0x90,
						0x88,0x83,0xc6,0xa1,0x86,0x8e};
uchar flag=0;
uchar temp=0x00;
void delay_ms(uint ms)
{
	uchar k;
	while(ms--)
	{
		for(k=0;k<114;k++);
	}
}
void display(uint n)
{
	uchar a,b,c,d;
	a=n/(16*16*16);
	b=n/(16*16)%16;
	c=n/16%16;
	d=n%16;
	
	w1=0;
	P0=table[a];
	delay_ms(5);
	w1=1;
	
	w2=0;
	P0=table[b];
	delay_ms(5);
	w2=1;
	
	w3=0;
	P0=table[c];
	delay_ms(5);
	w3=1;
	
	w4=0;
	P0=table[d];
	delay_ms(5);
	w4=1;	
}

void main()
{
	SM0=0;
	SM1=1;
	REN=1;
	PCON=0x00;
	TMOD=0x20;
	TH1=250;
	TL1=250;
	TR1=1;
	
	EA=1;
	ES=1;
	while(1)
	{
		display(temp*16*16+SBUF);
		flag=1;
	}
	
}
void S_() interrupt 4
{
	if(TI)
	{
		TI=0;
	}
	else
	{
				if(flag==1)
				{
					temp=SBUF;
					flag=0;
				}
				RI=0;
			}
}
