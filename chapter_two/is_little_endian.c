int is_little_endian(void)
{
    int a=0xff;
    unsigned char* b=(unsigned char *)&a;
    return b[0]==0xff;
}