#include <reg52.h>
#include <mouse.h>
//延时函数
void delay_ms(uint ms)
{
	uchar k;
	while(ms--)
	{
		for(k=0;k<114;k++);
	}
}
//左数码管显示
void T_1(uchar c)
{
	
	s1=1;
	s2=0;
	P0=t[c];
	delay_ms(5);
}
//右数码管显示
void T_2(uchar c)
{
	s1=0;
	s2=1;
	P0=t[c];
	delay_ms(5);
}
/*//栈初始化
uint init_s() {
	for (i = 0; i < MAXSIZE; i++) {
		for (j = 0; j < 3; j++) {
			s.coord[i][j] = 0;
		}
	}
	s.top = s.bottom = -1;
	return 1;
}
//判断栈是否空
uint empty() {
	if (s.top == s.bottom) {
		return 0;
	}
	else {
		return 1;
	}
}
//入栈
uint push(uint c[3]) {
	s.top++;
	if (s.top >= MAXSIZE) {
		s.top--;
		return 0;
	}
for (i = 0; i < 3; i++) {
		s.coord[s.top][i] = c[i];
	}
	return 1;
}
//出栈
uint pop(uint b[3]) {
	if (empty() == 0) {
		return 0;
	}
	else {
		for (i = 0; i < 3; i++) {
			b[i] = s.coord[s.top][i];
		}
		s.top--;
		return 1;
	}
}*/

//右转
void tr()
{
	for(j=0;j<49;j++)
	{
		for(i=0;i<8;i++)
		{
			P1=forward[i];
			delay_ms(3);
		}
	}
	delay_ms(50);
	nf1=(nf1+ef2)%4;
	ef1=(ef1+ef2)%4;
	sf1=(sf1+ef2)%4;
	wf1=(wf1+ef2)%4;
	
}
//左转
void tl()
{
	for(j=0;j<49;j++)
	{
		for(i=0;i<8;i++)
		{
			P1=reverse[i];
			delay_ms(3);
		}
	}
	delay_ms(50);
	nf1=(nf1+wf2)%4;
	ef1=(ef1+wf2)%4;
	sf1=(sf1+wf2)%4;
	wf1=(wf1+wf2)%4;
}
//回转
void r180 ()
{
	for(j=0;j<98;j++)
	{
		for(i=0;i<8;i++)
		{
			P1=reverse[i];
			delay_ms(3);
		}
	}
	delay_ms(50);
	nf1=(nf1+sf2)%4;
	ef1=(ef1+sf2)%4;
	sf1=(sf1+sf2)%4;
	wf1=(wf1+sf2)%4;
}
//左电机正转,左偏右调
void RM()
{
		for(j=0;j<1;j++)
		{
			for(i=0;i<8;i++)
			{
				P1=(forward[i]|0xf0);
				delay_ms(3);
			}
		}
}
//右电机正转，右偏左调
void LM()
{
		for(j=0;j<1;j++)
	{
		for(i=0;i<8;i++)
		{
			P1=(reverse[i]|0x0f);
			delay_ms(3);
		}
	}
}
//直走一格
void gf()
 {
	for(j=0;j<110;j++)
	{
		if(irLU && !irC)
		{
			while(irLU && !irC){
			RM();
			j++;}
		}
		else if(irRU && !irC)
		{
			while(irRU && !irC){
			LM();
			j++;}
		}
		else
		for(i=0;i<8;i++)
		{
			P1=f[i];
			delay_ms(2);
		}
	}
	if(nf1==0)
		y++;
	if(nf1==1)
		x++;
	if(nf1==2)
		y--;
	if(nf1==3)
		x--;
	delay_ms(200);
}

void setTime2(uint us)
{
	TH2=(65535-us)/256;
	RCAP2H=(65536-us)/256;
	TL2=(65536-us)%256;
	RCAP2L=(65536-us)%256;
}
void initTime2()
{
	EA=1;
	ET2=1;
	setTime2(5000);
	TR2=1;
}
void main()
{
	initTime2();
	//init_s();
	while(1)
	{
			//T_1(x);
			//T_2(y);
			
			//T_1(x);
			//T_2(y);
			/*	gf();
				if(irL == 1 && irC == 1 && irR == 0)
					tr();
				if(irL == 0 && irC == 1 && irR == 1)
					tl();
				if(irL == 1 && irC == 1 && irR == 1)
				{
					r180();
				}
				if(x==0&&y==0)
				{
					beep=0;
					while(1);
				}*/
					
				gf();
					if(irR == 0)
				{
					tr();
				}
				if(irL == 0 && irC == 1 && irR == 1)
					tl();
				if(irL == 1 && irC == 1 && irR == 1)
				{
					r180();
				}
			if(x==7&&y==0)
			while(1)
			{
				
				 gf();
				if(irL == 0)
				{
					tl();
				}
				if(irL == 1 && irC == 1 && irR == 0)
					tr();
				if(irL == 1 && irC == 1 && irR == 1)
				{
					r180();
				}
					if(x==0&&y==0)
						while(1){beep=0;while(1);}
			}
	}
}
void time2() interrupt 5
{
	static bit ir=0;
	TF2=0;
	if(!ir)
		MOUSE_IR_ON(a);
	else
	{
		switch(a++)
		{
			case 0: if(!irR1)irC=1;else irC=0;break;
			case 1: if(!irR2)irLU=1;else irLU=0;break;
			case 2: if(!irR3)irL=1;else irL=0;break;
			case 3: if(!irR4)irR=1;else irR=0;break;
			case 4: if(!irR5)irRU=1;else irRU=0;break;
			default:a=0;break;
		}
	}
	ir=~ir;
}
