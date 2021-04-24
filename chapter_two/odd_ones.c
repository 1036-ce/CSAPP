//return 1 when x contains an odd number of 1s; 0 otherwise
int odd_ones(unsigned x)
{
	x ^= x>>1;
	x ^= x>>2;
	x ^= x>>4;
	x ^= x>>8;
	x ^= x>>16;
	x&=0x1;
	return x;
 
}