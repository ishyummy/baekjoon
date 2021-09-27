#include <stdio.h>

int main()
{
	int ang[10] = { 0, }, i, a, b, c, n;
	scanf("%d %d %d", &a, &b, &c);
	n = a * b * c;
	while (n / 10 != 0) {
		ang[n % 10]++;
		n /= 10;
	}
	ang[n % 10]++;
	for (i = 0; i < 10; i++) {
		printf("%d\n", ang[i]);
	}

	return 0;
}