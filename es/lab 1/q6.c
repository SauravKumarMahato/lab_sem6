#include <reg51.h>
unsigned char loc[1] _at_ 0x60;

void delay(int _del)
 {
 	unsigned int i,j;
 	for (i=0;i<_del;i++)
 		for (j=0;j<123;j++);
 }

 /*
 void bubbleSort(unsigned char arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                unsigned char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
*/
 
 void main(){
	 int i,j, temp;
	 loc[1] = 0xA5;
	 loc[2] = 0xFD;
	 loc[3] = 0x67;
	 loc[4] = 0x42;
	 loc[5] = 0xDF;
	 loc[6] = 0x9A;
	 loc[7] = 0x84;
	 loc[8] = 0x1B;
	 loc[9] = 0xC7;
	 loc[10] = 0x31;
	 
   // bubbleSort(loc, 11);
	 
	 for (i = 1; i < 10; i++) {
        for (j = 1; j < 9; j++) {
            if (loc[j] > loc[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                temp = loc[j];
                loc[j] = loc[j + 1];
                loc[j + 1] = temp;
            }
        }
    }
	
	 while(1){
		 
		for (i = 1; i <= 10; i++) {
			P0 = loc[i];
			delay(10000);
    }
		
	}
	 
}