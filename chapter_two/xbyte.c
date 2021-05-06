/*
 * Extract byte from word. Return as signed integer
*/

typedef unsigned packed_t;

int xbyte(packed_t word,int bytenum)
{
    return (word<<((3-bytenum)<<3))>>24;
}
