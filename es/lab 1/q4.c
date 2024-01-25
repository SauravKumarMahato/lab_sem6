#include <reg51.h>
unsigned char loc _at_ 0x3E;

void delay(int _del)
 {
 	unsigned int i,j;
 	for (i=0;i<_del;i++)
 		for (j=0;j<123;j++);
 }

void main(){
	unsigned char dividend, quotient = 0x00, remainder = 0x00;
	loc = 0xAF;
	dividend = loc;
	
	while(dividend >= 0x12){
		dividend = dividend - 0x12;
		quotient++;
	}
	
	remainder = dividend;
	
	while(1){
		P0 = quotient;
		delay(1000);
		P0 = remainder;
		delay(1000);
	}
}
	