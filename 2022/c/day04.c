#include <stdio.h>

int
main()
{
	int p1=0, p2=0;
	int a0,a1, b0,b1;

	while (scanf(" %d-%d,%d-%d", &a0,&a1, &b0,&b1) == 4) {
		p1 += (a0>=b0 && a1<=b1) || (b0>=a0 && b1<=a1);
		p2 += a0<=b1 && a1>=b0;
	}
	
	printf("04: %d %d\n", p1, p2);
	return 0;
}