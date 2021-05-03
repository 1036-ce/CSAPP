/* Divide by power 0f 2. Assume 0 <= k < w-1 */


int divide_power2(int x, int k)
{
    int w = ((sizeof(int)) << 3) - 1;
    int mark=x>>w;  //mark==0 : x>=0  otherwise x<0
    unsigned m = (unsigned)(~x + 1);
    m = (1==m >> k);
    int ans = x >> k;
    int a = ~ans;
    a = !!a;
    a = (a << w) >> w;
    return (a & ans) - (mark & (!!m));
}
