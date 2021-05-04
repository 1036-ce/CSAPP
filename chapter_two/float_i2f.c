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
float_bits float_i2f(int i)
{
	unsigned sign = 0;
	unsigned exp = 0;
	unsigned frac = 0;
	if (i > 0)
	{
		sign = 0;
	}
	else if (i == 0)
	{
		return 0;
	}
	else
	{
		i = -i;
		sign = 1;
	}
	unsigned x = (unsigned)i;

	for (int j = 0; j < 32; j++)
	{
		if ((x >> j) == 1)
		{
			exp = j;
			break;
		}
	}
	unsigned mark;
	if (exp == 0)
	{
		mark = 0;
	}
	else
		mark = (1 << exp) - 1;
	frac = x & mark;
	if (exp <= 23)
	{
		frac = frac << (23 - exp);
	}
	else
	{
		unsigned len = exp - 23;
		mark = (1 << len) - 1;
		unsigned n = mark & frac;
		if (n > (1 << (len - 1)) || (n == (1 << (len - 1)) && (((frac >> len) & 0x1) == 1)))
		{
			frac = (frac >> len) + 1;
		}
		else
		{
			frac = frac >> len;
		}
	}
	exp += 127;
	return (sign << 31) + (exp << 23) + frac;
}
int main(void)
{
	for (int i = INT_MIN; i <= INT_MAX; i++)
	{
		
		float f = (float)i;
		unsigned a = f2u(f);
		unsigned b = float_i2f(i);
		if (a == b)
		{
			//printf("YES");
		}
		else
		{
			printf("%#x\n", a);
			printf("%#x\n", b);
			getchar();
		}
	}
	return 0;
}