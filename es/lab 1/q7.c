#include <reg51.h>
void msdelay(unsigned int time) {
unsigned int i, j;
for (i = 0; i < time; i++)
for (j = 0; j < 113; j++); // 1ms delay
}
void main() {
unsigned int * prime;
unsigned int i, j, div, rem, count, flag;
unsigned int count2 = 0x00;
prime = 0x40;
count = 0;
for (i = 0x00; i <= 0x20; i++) {
div = i / 2;
flag = 0;
for (j = 2; j <= div; j++) {
rem = i % j;
if (rem == 0) {
flag = 1;
break;
}
}
if (flag == 0) {
prime[count] = i;
count += 1;
}
}
while (1) {
	for (i = 0; i < count; i++) {
P0 = prime[i];
msdelay(2000);
}
}
}