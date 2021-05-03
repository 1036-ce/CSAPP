#include <stdio.h>
#include <math.h>

typedef unsigned float_bits;

float_bits float_twice(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 0x7fffff;

    if (exp == 0xff && !frac)
    {
        return f;
    }
    else if(exp==0)
    {
        return (sign<<31)+(frac<<1);
    }
    else
    {
        exp += 1;
        return (sign << 31) + (exp << 23) + frac;
    }
}
float u2f(unsigned x)
{
    return *(float *)&x;
}
unsigned f2u(float x)
{
    return *(unsigned *)&x;
}
int main(void)
{
    for(unsigned i=0;i<2e32;i++)
    {
        float f=u2f(i);
        if(f2u(f*2.0)!=float_twice(i))
        {
            printf("%u\n",f2u(f*2.0));
            printf("%u\n",float_twice(i));
            printf("WRONG!!     %d\n",i);
        }
    }
    return 0;
}