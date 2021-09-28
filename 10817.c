#include <stdio.h>

int main()
{
	int a, b, c, i, j;
	scanf("%d %d %d", &a, &b, &c);
	for (i = 0; i < 2; i++) {
		if (a > b) {
			j = a; a = b; b = j;
		}
		if (b > c) {
			j = b; b = c; c = j;
		}
	}
	printf("%d\n", b);
	return 0;
}