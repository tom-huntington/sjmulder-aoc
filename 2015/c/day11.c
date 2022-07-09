#include <stdio.h>
#include <string.h>
#include <err.h>

int
main(int argc, char **argv)
{
	char *s;
	int i, len, inc, npr;

	if (argc != 2)
		errx(1, "usage: solve <pass>");

	s = argv[1];
	len = strlen(s);
	while (1) {
		inc=0; npr=0;
		for (i=0; i<len; i++) {
			if (strchr("iol", s[i]))
				break;
			inc |= i>1 && s[i-2]+1==s[i-1]
				   && s[i-1]+1==s[i];
			npr += (i==2 && s[i-1]==s[i])
			    || (i>=3 && s[i-1]==s[i] && s[i-2]!=s[i-1]);
		}
		if (inc && npr>=2 && i==len) {
			printf("11: %s\n", s);
			return 0;
		}
		for (i=len-1; i>=0 && s[i]=='z'; i--)
			;
		if (i == -1) {
			puts("11: no solution");
			return 0;
		}
		memset(&s[i+1], 'a', len-i-1);
		s[i]++;
	}
}
