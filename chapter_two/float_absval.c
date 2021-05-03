#include <stdio.h>
#include <math.h>
typedef unsigned float_bits;

float u2f(unsigned x)
{
    return *(float *)&x;
}
unsigned f2u(float x)
{
    return *(unsigned *)&x;
}
float_bits float_absval(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 0x7fffff;

    if (exp == 0xff && !frac)
    {
        return f;
    }
    else
    {
        return (exp << 23) + frac;
    }
}

int main(void)
{

    for(unsigned i=0;i<2e32;i++)
    {
        float f=u2f(i);
        if(u2f(float_absval(i))!=fabs(f))
        {
            printf("WRONG!!    %d   %f\n",i,f);
        }
    }

//    printf("%d\n",u2f(2139095858)==u2f(2139095859));
//    printf("%f\n",u2f(2139095858));
//    printf("%f\n",fabs(NAN));
    return 0;
}