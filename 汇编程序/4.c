#include<reg52.h>
#include<intrins.h>
sbit LCD_RS=P2^5; 
sbit LCD_RW=P2^6;
sbit LCD_EN =P2^7;
unsigned char codedis1[] = {"hello world 123"};
int i=0;
int j=0;
void delay_ms4(unsigned int z)
{
	_nop_();
	  i=2;
	  j=199;
	    do
			{
				while(--j);
			}while(--i);
}
void delayNOP()
{
    _nop_();
    _nop_();
    _nop_();
    _nop_();
}
void lcd_busy()
{
    bit busy;
    busy=1;
    while (busy)
   {
        LCD_RS=0;
        LCD_RW= 1;
        LCD_EN=1;
        busy = (bit)(P1 &0x80); 
        delayNOP();
    }
        LCD_EN=0;

	}
void lcd_wcmd(unsigned char cmd)
{
    lcd_busy(); 
    LCD_RS = 0;  
    LCD_RW= 0;
    LCD_EN= 1;
    P1= cmd;
    delayNOP();
    LCD_EN = 0; 
}
void lcd_wdat(unsigned char dat)
{
lcd_busy();
LCD_RS=1;
LCD_RW= 0;
LCD_EN=1;
P1= dat;
delayNOP();
LCD_EN=0;
} 
void lcd_init()
{
delay_ms4(15);
LCD_RW=0;
LCD_EN= 0;

LCD_RS=1;
lcd_wcmd(0x30);
delay_ms4(5);
lcd_wcmd(0x0c);
delay_ms4(5);
lcd_wcmd(0x06);

delay_ms4(5);
lcd_wcmd(0x01);
delay_ms4(5);
}
void wr_string(unsigned char str[])
{
unsigned char num=0;
while (str[num])
{
lcd_wdat(str[num++]);
delay_ms4(5);
}
}
void d()
{
P0 = 0xff;
P2=0xff; 
lcd_init();
delay_ms4(100); 
while(1)
{
    lcd_wcmd(0x80);
    wr_string(codedis1);
}
}





