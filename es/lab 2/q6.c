#include <reg51.h>
unsigned char scroll_pattern[] = { 
0x3F, 0x3F, 0x07, 0xCF, 0x3F, 0x3F, 
0x07, 0xe6, 0x3F, 0x3F, 0x07, 0xed, 
0x3F, 0x3F, 0x07, 0xfd, 0x3F, 0x3F, 
0x07};
void delay(int time)
{
    unsigned int i,j;
    for (i=0; i<time; i++)
        for (j=0; j<500; j++);
}
void display(unsigned int i)
{
unsigned int j;

        P2 = 0x1;
        P0 = scroll_pattern[i-4];
        delay(80);
        P2 = 0x2;
        P0 = scroll_pattern[i-3];
        delay(80);
        P2 = 0x4;
        P0 = scroll_pattern[i-2];
        delay(80);
        P2 = 0x8;
        P0 = scroll_pattern[i-1];
        delay(80);

}
void main(void)
{
unsigned int i;
while(1)
    for(i=4; i<20; i++)
        display(i);
}
