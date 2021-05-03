/*
 * Do rotating left shift. Assume 0 <= n< w
 * Example when x=0x1235678 and w=32:
 *      n=4 -> ox23456781 ,n=20 -> 0x67812345
*/

unsigned rotate_left(unsigned x, int n)
{
    int w = sizeof(int) << 3;
    int a=(1<<(w-n-1))-1;
    a=(a<<1)+1;
    int b = x & (~a);
    b=(unsigned)b>>(w-n-1);
    b=(unsigned)b>>1;
    x <<= n;
    x += b;
    return x;
}