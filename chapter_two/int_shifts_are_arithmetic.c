//判断机器使用算术右移还是逻辑右移，使用算术右移返回1，否则返回0
int int_shifts_are_arithmetic(void)
{
    int a=~(0x0^0xf);
    a>>=4;
    unsigned char *b=(unsigned char*)&a;
    return b[0]==0xff;
}