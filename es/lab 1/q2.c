#include <reg51.h>

void delay(int _del)
 {
 	unsigned int i,j;
 	for (i=0;i<_del;i++)
 		for (j=0;j<123;j++);
 }
 
 void swap(unsigned long int num){
	unsigned long int temp, num1, num2;
	 
	num1 = (num & 0x0F);
	num2 = (num & 0xF0);
	temp = (num2/0x10 + num1*0x10);
	
	while(1){
		P0 = num;
		delay(1000);
		P0 = temp;
		delay(1000);
	}
}

void main(){
	unsigned long int num;
	P0 = 0x00;
	num = 0x6B;
	
	swap(num);
}