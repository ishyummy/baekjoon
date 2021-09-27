#include <stdio.h>

int main()
{
	int n, m, i, max = 0;
	for (i = 1; i <= 9; i++) {
		scanf("%d", &n);
		if (n > max) {
			max = n;
			m = i;
		}
	}
	printf("%d\n%d", max, m);
	return 0;
}