/**
 * LAB 2 - Task B
 *
 * Compile: gcc -Wall -Wextra -std=c99 -g mult.c -o mult
 * Run: ./mult
 *
 * **/

#include <stdlib.h>
#include <stdio.h>

unsigned int mult(unsigned int x, unsigned int y)
{
    unsigned result = 0;
    unsigned int multiplicand = x;
    unsigned int multiplier = y;

    for (int i=0; i<32; i++) {
        if ((multiplier&1) == 1) {
            result = result + multiplicand;
        }
        multiplier = multiplier >> 1;
        multiplicand = multiplicand << 1;
    }
    return result;
}

/*
*TODO: In mult2(), change the for-loop to a while-loop that has at most 31 passes
* but can also take a smaller number of passes. For example, if the function is supposed to multiply
* 2 x 3 then the while-loop will take 1 or 2 passes while the for-loop will take 31 passes.
 */
unsigned int mult2(unsigned int x, unsigned int y) // Done need to check results
{
    unsigned result = 0;
    unsigned int multiplicand = x;
    unsigned int multiplier = y;
    int passes = 0;
    while (passes <= 31 && multiplier > 0) { // only allows for up to 31
        //if ((multiplier&1) == 1) {
            result = result + multiplicand;
        //}
        multiplier = multiplier >> 1;
        multiplicand = multiplicand << 1;
        passes++;
        //printf("   DEBUG: %d\n", passes);
    }/*
    for (int i=0; i<32; i++) {
        if ((multiplier&1) == 1) {
            result = result + multiplicand;
        }
        multiplier = multiplier >> 1;
        multiplicand = multiplicand << 1;
    }*/
    return result;
}

unsigned int powMod(unsigned int x, unsigned int p, unsigned int m)
{
    unsigned int result = 1;
    for (unsigned int i = 0; i < p; i++) {
        result = (result * x) % m;
    }
    return result;
}


/*
* TODO: The number of multiplies that it computes is p, the power value.
*  So if p = 100000000, powMod2() executes 100 million multiples. Change powMod2() so it
*  does at most 64 multiplies.
 */
unsigned int powMod2(unsigned int x, unsigned int p, unsigned int m)
{//need to use binary
    unsigned int result = 1;
    unsigned int multiples = 0;
    while (multiples < 64 && multiples <= p) {
        //for (unsigned int i = 0; i<p; i++) {
        result = (result * x) % m;
        multiples++;
        printf("   DEBUG: %d\n", multiples);

        //
    }

    return result;
}

int main()
{
    unsigned int i=123;
    unsigned int j=456;
    printf("%dx%d=%d: mult(%d,%d)=%d\n",i,j,i*j,i,j,mult(i,j));
    printf("%dx%d=%d: mult2(%d,%d)=%d\n",i,j,i*j,i,j,mult2(i,j));

    //other test cases
/*
     i=2;
     j=3;
    printf("%dx%d=%d: mult(%d,%d)=%d\n",i,j,i*j,i,j,mult(i,j));
    printf("%dx%d=%d: mult2(%d,%d)=%d\n",i,j,i*j,i,j,mult2(i,j));

    i=777;
    j=456;
    printf("%dx%d=%d: mult(%d,%d)=%d\n",i,j,i*j,i,j,mult(i,j));
    printf("%dx%d=%d: mult2(%d,%d)=%d\n",i,j,i*j,i,j,mult2(i,j));
*/
    unsigned int x=3;
    unsigned int p=100000000;
    unsigned int m=53;
    printf("%d^%d mod %d: powMod = %d\n", x,p,m,powMod(x,p,m));
    printf("%d^%d mod %d: powMod2 = %d\n", x,p,m,powMod2(x,p,m));
}