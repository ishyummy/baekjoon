#include <stdio.h>

int main()
{
	int n, sum1, sum2, af, count = 0;
	scanf("%d", &n);
	af = n;
	do {
		if (af < 10) af *= 11;
		else {
			sum1 = af % 10;
			sum2 = ((af / 10) + (af % 10))%10;
			af = 10 * sum1 + sum2;
		}
		count++;
	} while (n != af);
	printf("%d\n", count);
	return 0;
}