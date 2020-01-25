sfr P4=0xe8;
sbit A0=P4^0;
sbit A1=P2^0;
sbit A2=P2^7;
sbit irR1=P2^1;
sbit irR2=P2^2;
sbit irR3=P2^3;
sbit irR4=P2^4;
sbit irR5=P2^5;
bit irC=0,irL=0,irR=0,irLU=0,irRU=0;
#define MOUSE_IR_ON(GROUP_NO)\
do\
{	\
	A0=(GROUP_NO)&0x01;\
	A1=(GROUP_NO)&0x02;\
	A2=(GROUP_NO)&0x04;\
}while(0)
#define uchar unsigned char
#define uint unsigned int
#define MAXSIZE 50
uchar a=0,i,j;
uchar x=0,y=0;
uchar z[8][8];
uchar ef1=1,sf1=2,wf1=3,nf1=0;
uchar ef2=1,sf2=2,wf2=3,nf2=0;
sbit s1=P4^3;
sbit s2=P4^2;
sbit beep=P3^7;
uchar code t[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8};//数码管数码
uchar code f[]={0x11,0x93,0x82,0xc6,0x44,0x6c,0x28,0x39};//左右电机同时正转
uchar code r[]={0x11,0x39,0x28,0x6c,0x44,0xc6,0x82,0x93};//左右点击同时反转
uchar code forward[]={0x11,0x33,0x22,0x66,0x44,0xcc,0x88,0x99};//右电机正转
uchar code reverse[]={0x11,0x99,0x88,0xcc,0x44,0x66,0x22,0x33};//左电机正转
typedef struct Stack {
	uchar coord[MAXSIZE][2];
	uchar top, bottom;       
}st;
idata st s;
