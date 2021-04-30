/*
*将浮点数的位表达式看做无符号数的位表达式，它们的相对大小是相同的
*/

/*
*假定 f2u() 返回一个无符号32位数字
*/

unsigned f2u(float x)
{
    return *(unsigned *)&x;
}
int float_le(float x, float y)
{
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    return (((ux << 1) >= (uy << 1)) & (sx == 0)) || (ux == 0x80000000 && uy == 0x0) || (((ux << 1) <= (uy << 1)) & (sx == 1));
}
