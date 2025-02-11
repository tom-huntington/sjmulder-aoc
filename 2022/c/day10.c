#include "common.h"

int
main(int argc, char **argv)
{
	char img[6][40], buf[16];
	int clock, reg_x=1, op_val=0, op_time=0;
	int p1=0, x,y;

	if (argc > 1)
		(void)!freopen(argv[1], "r", stdin);

	for (clock = 0; clock < 6*40; clock++, op_time--) {
		y = clock / 40;
		x = clock % 40;

		if (x == 20)
			p1 += clock * reg_x;

		if (op_time <= 0) {
			reg_x += op_val;

			if (!fgets(buf, sizeof(buf), stdin))
				op_time = INT_MAX;
			else if (sscanf(buf, "addx %d", &op_val) == 1)
				op_time = 2;
			else {
				op_time = 1;	/* nop */
				op_val = 0;
			}
		}

		img[y][x] = abs(x - reg_x) <= 1 ? '#' : ' ';
	}

	printf("10: %d\n", p1);

	for (y=0; y<6; y++)
		printf("10:  %.40s\n", img[y]);

	return 0;
}
