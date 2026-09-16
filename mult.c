#include <stdlib.h>
#include <stdio.h>

unsigned int mult(unsigned int x, unsigned int y)
{
unsigned result = 0;
unsigned int multiplicand = x;
unsigned int multiplier = y;

for (int i=0; i<32; i++) {
    if (multiplier&1 == 1) {
        result = result + multiplicand;
    }
    multiplier = multiplier >> 1;
    multiplicand = multiplicand << 1;
}
return result;
}

unsigned int mult2(unsigned int x, unsigned int y)
{
unsigned result = 0;
unsigned int multiplicand = x;
unsigned int multiplier = y;

for (int i=0; i<32; i++) {
    if (multiplier&1 == 1) {
        result = result + multiplicand;
    }
    multiplier = multiplier >> 1;
    multiplicand = multiplicand << 1;
}
return result;
}

unsigned int powMod(unsigned int x, unsigned int p, unsigned int m)
{
unsigned int result = 1;
for (int i=0; i<p; i++) {
    result = (result * x) % m;
}
return result;
}

unsigned int powMod2(unsigned int x, unsigned int p, unsigned int m)
{
unsigned int result = 1;
for (int i=0; i<p; i++) {
    result = (result * x) % m;
}
return result;
}

void main()
{
unsigned int i=123;
unsigned int j=456;
printf("%dx%d=%d: mult(%d,%d)=%d\n",i,j,i*j,i,j,mult(i,j));
printf("%dx%d=%d: mult2(%d,%d)=%d\n",i,j,i*j,i,j,mult2(i,j));

unsigned int x=3;
unsigned int p=100000000;
unsigned int m=53;
printf("%d^%d mod %d: powMod = %d\n", x,p,m,powMod(x,p,m));
printf("%d^%d mod %d: powMod2 = %d\n", x,p,m,powMod2(x,p,m));
}


