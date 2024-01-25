#include <reg51.h> 

unsigned char digit[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

void delay(int _del)
 {
 	unsigned int i,j;
 	for (i=0;i<_del;i++)
 		for (j=0;j<123;j++);
 }

void main()
{
	unsigned char i; 
	P2 = 0xF8;
	while(1){
		for(i=0;i<0x0A;i++)
		{
			P0=digit[i];
			delay(1000);
		}
		for(i=8;i>0;i--)
		{
			P0=digit[i];
			delay(1000);
		}
	}
} 