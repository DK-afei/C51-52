	#include <reg52.h>
	#include <intrins.h>
	unsigned char temp14;		
#define uint unsigned int
#define uchar unsigned char
sbit wel1=P2^0;
sbit wel2=P2^1;
sbit wel3=P2^2;
sbit wel4=P2^3;
uchar code table14[]={0xc0,0xf9,0xa4,0xb0,0x99,
										0x92,0x82,0xf8,0x80,0x90,
										0x88,0x83,0xc6,0xa1,0x86,0x8e};
uchar temp14=0x00;
uint flag14=0;
void delay_ms14(unsigned int ms)
{
	unsigned char k;
	while(ms--)
	{
		for (k=0;k<114;k++);
	}
}
void display14(uint k)
{
	uchar a,b,c,d;
	a=k/(16*16*16);
	b=k/(16*16)%16;
	c=k/16%16;
	d=k%16;
	
	wel1=0;
	P0=table14[a];
	delay_ms14(5);
	wel1=1;

	
	wel2=0;
	P0=table14[b];
	delay_ms14(5);
	wel2=1;
	
	
	wel3=0;
	P0=table14[c];
	delay_ms14(5);
	wel3=1;
	
	wel4=0;
	P0=table14[d];
	delay_ms14(5);
	wel4=1;

}

	void q()
	{
		SM0=0;
		SM1=1;
		REN=1;
		PCON=0x00;
		TMOD=0x20;
		TH1=250;
		TL1=250;
		TR1=1;
		ES=1;
		EA=1;
		while(1)
		{
				display14(temp14*16*16+SBUF);
				flag14=1;
		}
	}	
		
		void T1_() interrupt 4
		{
			if(TI)
			{
				
				TI=0;
			}
			else
			{
				if(flag14==1)
				{
					temp14=SBUF;
					flag14=0;
				}
				RI=0;
	
			}
		}