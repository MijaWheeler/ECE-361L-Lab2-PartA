/**
 * LAB 2 - Task B
 *
 * Compile: cc -Wall -Wextra -std=c99 -g bitOps.c -o bitOps
 * Run: ./bitOps
 *
 * **/

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

int main()
{
    char value = 0xab;
    printf("value =");
    displayBits(value);
    printf("\n");
    printf("\n");

    int position = 1;
    printf("getBit:  Bit %d = %c\n", position, getBit(value, position));
    position = 2;
    printf("getBit:  Bit %d = %c\n", position, getBit(value, position));
    printf("\n");

    position = 1;
    printf("getBit2:  Bit %d = %c\n", position, getBit2(value, position));
    position = 2;
    printf("getBit2:  Bit %d = %c\n", position, getBit2(value, position));
    printf("\n");

    position = 1;
    printf("setBit:  Bit %d; Result = ", position);
    displayBits(setBit(value, position));
    printf("\n");
    position = 2;
    printf("setBit:  Bit %d; Result = ", position);
    displayBits(setBit(value, position));
    printf("\n");
    printf("\n");

    position = 1;
    printf("clearBit:  Bit %d; Result = ", position);
    displayBits(clearBit(value, position));
    printf("\n");
    position = 2;
    printf("clearBit:  Bit %d; Result = ", position);
    displayBits(clearBit(value, position));
    printf("\n");
    printf("\n");

    position = 3;
    printf("clearMSBitsThroughK:  Bit %d, Result = ", position);
    displayBits(clearMSBitsThroughK(value, position));
    printf("\n");
    position = 1;
    printf("clearMSBitsThroughK:  Bit %d, Result = ", position);
    displayBits(clearMSBitsThroughK(value, position));
    printf("\n");
    printf("\n");

    position = 3;
    printf("clearLSBitsThroughK:  Bit %d, Result = ", position);
    displayBits(clearLSBitsThroughK(value, position));
    printf("\n");
    position = 5;
    printf("clearLSBitsThroughK:  Bit %d, Result = ", position);
    displayBits(clearLSBitsThroughK(value, position));
    printf("\n");
    printf("\n");

    position = 1;
    int bitIs1 = 0;
    printf("updateBit:  Bit %d, bitIs1=%d; Result = ", position, bitIs1);
    displayBits(updateBit(value, position, bitIs1));
    printf("\n");
    position = 2;
    bitIs1 = 1;
    printf("updateBit:  Bit %d; bitIs1=%d, Result = ", position, bitIs1);
    displayBits(updateBit(value, position, bitIs1));
    printf("\n");

    return 1;
}

char getBit(char c, int k)
{
    return '0' + ((c & (1 << k)) != 0);
}

char getBit2(char c, int k)
{
    char result = c >> k; /* Shift the bit to position 0 */
    result = result & 1;  /* Mask the bits except bit 0 */
    return '0' + result;  /* Return the bit as a char */
}

char setBit(char c, int k)
{
    return c | (1 << k);
}

char clearBit(char c, int k) // Corrected the function name from "clearBit" to "clearBit" and added the missing implementation
{
    return c & ((char)(~(1 << k)));
}

char clearMSBitsThroughK(char c, int k)
{
    char mask = (1 << k) - 1;
    return c & mask;
}

char clearLSBitsThroughK(char c, int k) // Corrected the function name from "clearLSBitsThroughK" to "clearLSBitsThroughK" and added the missing implementation
{
    char mask = (char)(~((1 << (k + 1)) - 1));
    return c & mask;
    // return c & ~((1 << (k + 1)) - 1);
}

char updateBit(char c, int k, int bitIs1) // Corrected the function name from "updateBit" to "updateBit" and added the missing implementation
{
    if (bitIs1)
    {
        return c | (1 << k);
    }
    else
    {
        return c & ~(1 << k);
    }
}

void displayBits(char c)
{
    for (int i = 0; i < 8; i++)
    {
        printf("%c", '0' + ((c >> (7 - i)) & 1));
    }
}