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
	unsigned int j,  led1, led2, led3, led4;
	
	led1 = i / 1000;
	led2 = ( i / 100) % 10;
	led3 = (( i / 10) % 100)% 10;
	led4 = (( i  % 1000)% 100)%10;
	

for ( j = 0 ; j<10;j++){
		P2 = 0xF1;
		P0 = led_pattern[led1];
		delay(35);
		
		P2 = 0xF2;
		P0 = led_pattern[led2];
		delay(35);
		
		P2 = 0xF4;
		P0 = led_pattern[led3];
		delay(35);
		
		P2 = 0xF8;
		P0 = led_pattern[led4];
		delay(35);
}
}

void main(void)
{
  unsigned int i ;
	unsigned int temp = 0 ;
	while(1)
	{
		N = 49;
		temp = N;
		for(i=0; i<24  ; i++){
			display(temp);
			temp = temp + 1 ;
		}
	}
}