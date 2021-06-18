#include <stdio.h>

typedef union {long i; int k[1]; char c;} DATE;
struct data { int cat; DATE cow; double dog;} too;
DATE max;


int main()
{
	printf("%d",sizeof(struct data)+sizeof(max));
}