/* Addition that saturates to TMin or TMax */

int saturating_add(int x, int y)
{
    int l = sizeof(int) << 3;
    int a = x + y;
    int b = !((a & x >> (l - 1)) || (a & y >> (l - 1)));
    a = a - !((x + y) >> (l - 1));
    int c = (b << (l - 1));
    c = c >> (l - 2);
    c = (unsigned)c >> 1;

    return c | a + !((x + y) >> (l - 1));
}