#include <reg51.h>

unsigned char led_pattern[10] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

void delay(int _del)
 {
 	unsigned int i,j;
 	for (i=0;i<_del;i++)
 		for (j=0;j<180;j++);
 }
 
void display(unsigned int i)
{
	unsigned int j, led1, led2;
	led1 = i / 10;
	led2 = i % 10;
	for(j=0; j<10; j++)
	{
		P2 = 0xF4;
		P0 = led_pattern[led1];
		delay(40);
		P2 = 0xF8;
		P0 = led_pattern[led2];
		delay(40);
	}
}

void main(void)
{
  unsigned int i;
	while(1)
	{
		for(i=0; i< 20; i++)
		display(i);
		
	}
}