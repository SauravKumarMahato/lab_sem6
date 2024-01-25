#include <reg51.h>
unsigned char loc1 _at_ 0x22;
unsigned char loc2 _at_ 0x15;

unsigned char low_byte _at_ 0x19;
unsigned char high_byte _at_ 0x1A;

void delay(int _del)
 {
 	unsigned int i,j;
 	for (i=0;i<_del;i++)
 		for (j=0;j<123;j++);
 }

void main(){
	unsigned char temp = 0x00, i;
	unsigned short sum = 0x00;
	//P0 = 0x00;
	low_byte = 0x00;
	high_byte = 0x00;
	loc1 = 0xFF;
	loc2 = 0xDE;
	
	for(i = 0x00; i<loc2; i++)
		sum += loc1;
	
	low_byte = (sum & 0x00FF);
	high_byte = (sum & 0xFF00)/0x100;
	
	while(1){
		P0 = low_byte;
		delay(1000);
		P0 = high_byte;
		delay(1000);
	}
}
	