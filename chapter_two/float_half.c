#include <stdio.h>
#include <math.h>
typedef unsigned float_bits;

float_bits float_half(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 0x7fffff;

    if (exp == 0xff && !frac)
    {
        return f;
    }
    else if (exp == 0)
    {
        return (sign << 31) + ((frac + 1) % 4 == 0) + frac >> 1;
    }
    else
    {
        if (exp > 1)
        {
            exp -= 1;
            return (sign << 31) + (exp << 23) + frac;
        }
        else
        {
            return (sign << 31) + (exp << 22) + (frac >> 1) + ((frac + 1) % 4 == 0);
        }
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
    for (int i = 0; i < 2e32; i++)
    {
        float f = u2f(i);
        if (f2u(f * 0.5) != float_half(i))
        {
            printf("WRONG!\ti=%x\t", i);
            printf("f2u(f*0.5)=%x\tfloat_half(i)=%x\n", f2u(f * 0.5), float_half(i));
        }
    }
    return 0;
}