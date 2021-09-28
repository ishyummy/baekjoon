#include <stdio.h>

int main()
{
	int a[42] = {0,};
	int n, i, count = 0;
	for (i = 0; i < 10; i++) {
		scanf("%d", &n);
		a[n % 42] = 1;
	}
	for (i = 0; i < 42; i++) if (a[i]) count++;
	printf("%d\n", count);
	return 0;
}