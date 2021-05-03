
int mul3div4(int x)
{
    int w = ((sizeof(int)) >> 3) - 1;
    int mark = x >> w;
    int a = x + (x << 1);
    a = (~mark & (a >> 2)) + (mark & ((a + (1 << 2) - 1) >> 2));
    return a;
}