#include <stdio.h>
#include <math.h>
#include <limits.h>

typedef unsigned float_bits;
float u2f(unsigned x)
{
    return *(float *)&x;
}
unsigned f2u(float x)
{
    return *(unsigned *)&x;
}
int float_f2i(float_bits f)
{
    unsigned sign = f >> 31;
    int exp = f >> 23 & 0xff;
    unsigned frac = f & 0x7fffff;
    if (exp == 0xff)
    {
        return 0x80000000;
    }
    if (sign == 0)
    {
        if (exp > 30 + 127)
        {
            return 0x80000000;
        }
        else
        {
            if (exp < 127)
                return 0;
            exp -= 127;
            frac = frac + (1 << 23);
            if (exp <= 23)
            {
                int ret = (int)(frac >> (23 - exp));
                return ret;
            }
            else
            {
                return (int)(frac << (exp - 23));
            }
        }
    }
    else
    {
        if (exp > 31 + 127 || (exp == 31 + 127 && frac > 0))
        {
            return 0x80000000;
        }
        else
        {
            if (exp < 127)
                return 0;
            exp -= 127;
            frac = frac + (1 << 23);
            if (exp <= 23)
            {
                return -((int)(frac >> (23 - exp)));
            }
            else
            {
                return -((int)(frac << (exp - 23)));
            }
        }
    }
}

int main(void)
{
    for (unsigned i=0x0; i < (unsigned)(2e32); i++)
    {
        float f = u2f(i);
        if ((int)f != float_f2i(i))
        {
            printf("%x\t%x\t", (int)f, float_f2i(i));
            printf("%x\n", i);
            getchar();
        }
    }
    return 0;
}