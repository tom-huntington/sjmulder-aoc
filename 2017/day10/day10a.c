#define _CRT_SECURE_NO_WARNINGS
#define N 256

#include <stdio.h>

int
main(int argc, char **argv)
{
	int list[N];
	int pos=0, skip=0, length;
	int i, *p, *q, temp;

	for (i=0; i<N; i++)
		list[i] = i;

	while (scanf(" %d", &length) == 1) {
		for (i=0; i < length/2; i++) {
			p = list + (pos+i) % N;
			q = list + (pos+length-i-1) % N;
			temp = *p; *p = *q; *q = temp;
		}

		pos += length + skip++;
		scanf(" ,");
	}

	printf("%d\n", list[0] * list[1]);
	return 0;
}
