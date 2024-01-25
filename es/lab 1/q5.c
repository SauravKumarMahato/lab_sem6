#include <reg51.h>
unsigned char loc _at_ 0x50;

void delay(int _del)
 {
 	unsigned int i,j;
 	for (i=0;i<_del;i++)
 		for (j=0;j<123;j++);
 }

 
 void main(){
	 int i;
	 unsigned char temp = 0x00;
	 unsigned char smallest = 0x00;
	 unsigned char largest = 0x00 ;
	 
	 loc[0] = 0xD6;
	 loc[1] = 0xF2;
	 loc[2] = 0xE4;
	 loc[3] = 0xA8;
	 loc[4] = 0xCE;
	 loc[5] = 0xB9;
	 loc[6] = 0xFA;
	 loc[7] = 0xAE;
	 loc[8] = 0xBA;
	 loc[9] = 0xCC;
	 
	 smallest = loc[0];
	 largest = loc[0];
	 
	 for(i = 1; i < 10; i++){
		if ( largest < loc[i])
			largest = loc[i];
		if( smallest > loc[i])
			smallest = loc[i];
	 }
	
	 while(1){
		P0 = largest;
		delay(1000);
		P0 = smallest;
		delay(1000);
	}
	 
}