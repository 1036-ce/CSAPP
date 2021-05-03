//计算无符号 x*y 的高 w 位


//计算有符号 x*y 的高 w 位
int signed_high_prod(int x, int y); 

unsigned unsigned_high_prod(unsigned x, unsigned y)
{
    int w = ((sizeof(int)) << 3) - 1;
    unsigned a = (unsigned)signed_high_prod(x, y);
    int x1 = (int)x >> w;
    int y1 = (int)y >> w;
    unsigned x2 = x >> w;
    unsigned y2 = y >> w;
    a += (x1 & y) + (x & y1) + (x2 & y2) << w;
    return a;
}