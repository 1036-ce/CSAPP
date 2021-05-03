/* Addition that saturates to TMin or TMax */

int saturating_add(int x, int y)
{
    int w = (sizeof(int) << 3) - 1;
    int mark1 = (x ^ y) >> w;
    int mark2 = ((x + y) ^ x) >> w;
    int mark = ~mark1 & mark2;
    //overflow: mark==-1; ==0 otherwise
    int pos = x >> w; //可判断为上溢还是下溢 pos==-1为下溢 pos==0为上溢
    int ans = (~mark & (x + y)) + (((unsigned)(-1) >> 1) ^ pos) - ((~mark) & (((unsigned)(-1) >> 1) ^ pos));
    return ans;
}