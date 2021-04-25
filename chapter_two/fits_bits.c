/*
 * Return 1 when x can be represented as an n-bit, 2's-complement
 * number; 0 otherwise
 *  Assume 1 <= n <= w
*/

int fits_bits(int x, int n)
{
    int a = ~2 + 1;
    int b = (1 << (n - 1)) - 1;
    b += 1 << (n - 1);
    a = a & b;
    return x == a;
}