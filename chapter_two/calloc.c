/* 
 *函数 calloc 为一个数组分配内存，该数组有nmemb个元素，每个元素为size字节。
 *内存设置为 0，如果nmemb 或size 为0，则calloc返回NULL
*/
typedef unsigned int size_t;

void *calloc(size_t nmemb,size_t size)
{
    void *ret=malloc(nmemb*size);
    memset(ret,0,size*nmemb);
    return ret;
}