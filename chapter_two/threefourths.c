
int threefourths(int x)
{
    int w = ((sizeof(int)) << 3) - 1;
    int mark = x >> w;
    int a = (~mark & (x >> 2)) + (mark & ((x + (1 << 2) - 1) >> 2));
    a=a+(a<<1);
    return a;
}