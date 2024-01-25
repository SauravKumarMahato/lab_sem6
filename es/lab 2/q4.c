#include <reg51.h>

unsigned long int N _at_ 0x40;

unsigned char led_pattern[10] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

void delay(int _del)
 {
 	unsigned int i,j;
 	for (i=0;i<_del;i++)
 		for (j=0;j<125;j++);
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
  unsigned int i ;
	unsigned int temp = 0 ;
	while(1)
	{
		N = 5;
		for(i=0; i<10  ; i++){
			temp = N*(i+1) ;
			display(temp);
		}
	}
}