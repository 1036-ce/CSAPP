//return 1 when any odd bit of x equals 1;0 otherwise
int any_odd_one(unsigned x)
{
    return (x & 0xaaaaaaaa)!=0;
}