#include <stdlib.h>
#include <stdio.h>

void displayBits(char c);
char getBit(char c, int k);
char getBit2(char c, int k);
char setBit(char c, int k);
char clearBit(char c, int k);
char clearMSBitsThroughK(char c, int k);
char clearLSBitsThroughK(char c, int k);
char updateBit(char c, int k, int bitIs1);

void main()
{
char value = 0xab;
printf("value =");
displayBits(value);
printf("\n");
printf("\n");

int position = 1;
printf("getBit:  Bit %d = %c\n", position, getBit(value,position));
position = 2;
printf("getBit:  Bit %d = %c\n", position, getBit(value,position));
printf("\n");

position = 1;
printf("getBit2:  Bit %d = %c\n", position, getBit2(value,position));
position = 2;
printf("getBit2:  Bit %d = %c\n", position, getBit2(value,position));
printf("\n");

position = 1;
printf("setBit:  Bit %d; Result = ", position);
displayBits(setBit(value,position));
printf("\n");
position = 2;
printf("setBit:  Bit %d; Result = ", position);
displayBits(setBit(value,position));
printf("\n");
printf("\n");

position = 1;
printf("clearBit:  Bit %d; Result = ", position);
displayBits(clearBit(value,position));
printf("\n");
position = 2;
printf("clearBit:  Bit %d; Result = ", position);
displayBits(clearBit(value,position));
printf("\n");
printf("\n");

position = 3;
printf("clearMSBitsThroughK:  Bit %d, Result = ", position);
displayBits(clearMSBitsThroughK(value,position));
printf("\n");
position = 1;
printf("clearMSBitsThroughK:  Bit %d, Result = ", position);
displayBits(clearMSBitsThroughK(value,position));
printf("\n");
printf("\n");

position = 3;
printf("clearLSBitsThroughK:  Bit %d, Result = ", position);
displayBits(clearLSBitsThroughK(value,position));
printf("\n");
position = 5;
printf("clearLSBitsThroughK:  Bit %d, Result = ", position);
displayBits(clearLSBitsThroughK(value,position));
printf("\n");
printf("\n");

position = 1;
int bitIs1 = 0;
printf("updateBit:  Bit %d, bitIs1=%d; Result = ", position,bitIs1);
displayBits(updateBit(value,position,bitIs1));
printf("\n");
position = 2;
bitIs1 = 1;
printf("updateBit:  Bit %d; bitIs1=%d, Result = ", position,bitIs1);
displayBits(updateBit(value,position,bitIs1));
printf("\n");
}

char getBit(char c, int k)
{
return '0' + ((c & (1 << k))!=0);
}

char getBit2(char c, int k)
{
char result = c >> k;      /* Shift the bit to position 0 */
result = result & 1;       /* Mask the bits except bit 0 */
return '0' + result;       /* Return the bit as a char */
}

char setBit(char c, int k)
{
return c | (1 << k);
}

char clearBit(char c, int k)
{
return 0; 
}
	
char clearMSBitsThroughK(char c, int k)
{
char mask = (1<<k)-1;
return c & mask;
}

char clearLSBitsThroughK(char c, int k)
{
return 0;
}

char updateBit(char c, int k, int bitIs1)
{
return 0;
}

void displayBits(char c)
{
for (int i=0; i<8; i++) {
    printf("%c",'0'+((c>>(7-i))&1));
}
}


