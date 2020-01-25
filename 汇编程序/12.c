	#include <reg52.h>
	typedef unsigned char uchar;
	typedef unsigned int uint;
	sbit w1=P2^0;
	sbit w2=P2^1;
	sbit w3=P2^2;
	sbit w4=P2^3;
	uchar Count,Sec,shift,n12,m12=0;
	uchar code LEDData[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0xff};
	uchar data display120[2];
	char code reserve[3] _at_ 0x3b;
	void delay_ms12(uint ms)
	{
		uchar k;
		while(ms--)
		{
			for(k=0;k<114;k++);
		}
	}
	void display12(uint k)
	{
		uchar a,b;
		a=k/10;
		b=k%10;
		
		w1=0;
		P0=LEDData[a];
		delay_ms12(5);
		w1=1;
		
		w2=0;
		P0=LEDData[b];
		delay_ms12(5);
		w2=1;
			w3=1;
			w4=1;
		
	}
	void o()
	{
		P0=0xff;
		P2=0xff;
		Count=0x00;
		Sec=0x00;
		n12=0x00;
		shift=0xfe;
		
		TMOD=0x01;
		TH0=0x4c;
		TL0=0x00;
		ET0=1;
		
		T2CON=0x00;
		TH2=0xf8;
		TL2=0xcc;
		ET2=1;
		EA=1;
		TR2=1;
		TR0=1;
		while(1)
		{
				display12(m12);
		};
	}
	
	
	void Time0() interrupt 1
	{
		TH0=0x4c;
		TL0=0x00;
		++Count;
		if(Count==20)
		{
			Count=0;
			++Sec;
			if(Sec==60)
			{
				Sec=0;
				m12++;
				if(m12==60)
					m12=0;
			}
		}
	}
	
	
	void time2() interrupt 5
	{
		TR2=0;
		TF2=0;
		TH2=0xf8;
		TL2=0xcc;
		
		if(n12>=2)
		{
			n12=0;
			shift=0xf7;
			P2=0xff;
		}
		else
		{
			display120[0]=Sec%10;
			display120[1]=Sec/10;
			
			P0=LEDData[display120[n12++]];
			P2=shift;
			shift=(shift>>1)|0x80;
		}
		TR2=1;
	}