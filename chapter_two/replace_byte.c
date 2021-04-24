//replace_byte(0x12345678,2,0xAB) --> 0x12AB5678
//replace_byte(ox12345678,0,0xAB) --> 0x123456AB
unsigned replace_byte(unsigned x,int i,unsigned char b)
{
    unsigned char *s=(unsigned char*)&x;
    s[i]=b;
    return x;
}