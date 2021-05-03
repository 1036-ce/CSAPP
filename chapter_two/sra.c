//使用逻辑右移来完成算术右移
int sra(int x,int k)    
{
    int xsrl=(unsigned) x>>k;
    int l=sizeof(int)<<3;
    int a=x>>(l-1);
    a=~a+1;
    a=(a<<(l-k))-1;
    return (~a)|xsrl;
}
