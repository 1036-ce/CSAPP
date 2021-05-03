//使用算术右移来完成逻辑右移
unsigned srl(unsigned x, int k)
{
    unsigned xsra = (int)x >> k;
    int a = 0;
    int l = sizeof(int) << 3;
    a += (0x1 << (l - k)) - 1;
    return xsra & a;
}