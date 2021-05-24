long decode2(long x,long y,long z)
{
    x=x*(y-z);
    return x^((x<<63)>>63);
}