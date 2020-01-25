#include<reg52.h>
#include<intrins.h>
sbit LCD_RS=P2^5; 
sbit LCD_RW=P2^6;
sbit LCD_EN =P2^7;
unsigned char codedis151[] = {"  11703990404"};
unsigned char codedis152[] = {"  dengxiaoping"};
void delay_ms15(unsigned int ms)
{
	unsigned char k;
	while(ms--)
	{
		for(k=0;k<114;k++);
	}
}
void delayNOP15()
{
    _nop_();
    _nop_();
    _nop_();
    _nop_();
}
void lcd_busy15()
{
    bit busy;
    busy=1;
    while (busy)
   {
        LCD_RS=0;
        LCD_RW= 1;
        LCD_EN=1;
        busy = (bit)(P1 &0x80); 
        delayNOP15();
    }
        LCD_EN=0;

	}
void lcd_wcmd15(unsigned char cmd)
{
    lcd_busy15(); 
    LCD_RS = 0;  
    LCD_RW= 0;
    LCD_EN= 1;
    P1= cmd;
    delayNOP15();
    LCD_EN = 0; 
}
void lcd_wdat15(unsigned char dat)
{
lcd_busy15();
LCD_RS=1;
LCD_RW= 0;
LCD_EN=1;
P1= dat;
delayNOP15();
LCD_EN=0;
} 
void lcd_init15()
{
delay_ms15(15);
LCD_RW=0;
LCD_EN= 0;

LCD_RS=1;
lcd_wcmd15(0x38);
delay_ms15(5);
lcd_wcmd15(0x0c);
delay_ms15(5);
lcd_wcmd15(0x06);

delay_ms15(5);
lcd_wcmd15(0x01);
delay_ms15(5);
}
void wr_string15(unsigned char str[])
{
unsigned char num15=0;
while (str[num15])
{
lcd_wdat15(str[num15++]);
delay_ms15(5);
}
}
void main()
{
P0 = 0xff;
P2=0xff; 
lcd_init15();
delay_ms15(100); 
while(1)
{
		lcd_wcmd15(0x80);
		wr_string15(codedis151);
		delay_ms15(0);
		lcd_wcmd15(0xc0);
		wr_string15(codedis152); 
}
}








