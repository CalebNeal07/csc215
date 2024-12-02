#include <stdio.h>

#define EXIT_SUCCESS 0;
#define EXIT_ERROR 1;

int is_all_zeroes(str)
char *str;
{
	if (!str) return 0;
	while (*str) {
		if (*str != '0') {
			return 0;
		}
		str++;
	}
	return 1;
}

int main(argc, argv)
int	 argc;
char *argv[];
{
	int i;
	int sum;
	sum = 0;	

	for (i = 1; i < argc; i++) {
		int val;
		val = atoi(argv[i]);
		if (val == 0 && !is_all_zeroes(argv[i])) {
			printf("OOPS! %s is not a number", argv[i]);
			return EXIT_ERROR;
		}
		sum += val;
	}

	printf("%d", sum);
	return 0;
}
