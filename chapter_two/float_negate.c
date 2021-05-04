#include <stdio.h>
#include <math.h>

typedef unsigned float_bits;

float_bits float_negate(float_bits f)
{
    unsigned sign=f>>31;
    unsigned exp = (f >> 23) & 0xff;
    unsigned frac = f & 0x7fffff;
    if(exp==0xff && !frac)
    {
        return f;
    }
    else
    {
        return ((sign^1)<<31)+(exp<<23)+frac;
    }
}
float u2f(unsigned x)
{
    return *(float*)&x;
}
unsigned f2u(float x)
{
    return *(unsigned*)&x;
}
int main(void)
{
    float f;
    scanf("%f",&f);
    unsigned f1=f2u(f);
    printf("%f\n",u2f(float_negate(f1)));
    printf("%f\n",u2f(float_negate(f2u(NAN)))); //NAN定义在math.h中
    return 0;
}