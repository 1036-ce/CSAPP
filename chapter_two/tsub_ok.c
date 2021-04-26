/* determine whether arguments can be subtracted without overflow */

int tsub_ok(int x, int y)
{
    int w = (sizeof(int) << 3) - 1;
    int mark1 = (x ^ y) >> w;       //mark1==0 not overflow
    int mark2 = ((x - y) ^ x) >> w; //if(mark1!=0 && mark2!=0) the (x-y) is overflow;
    int mark = !mark1 || !mark2;
    return mark;
}
