#include <stdio.h>

int main()
{
	int n, m, i, min, max;
	scanf("%d", &n);
	scanf("%d", &min);
	max = min;
	for (i = 1; i < n; i++) {
		scanf("%d", &m);
		if (m > max) max = m;
		if (m < min) min = m;
	}
	printf("%d %d\n", min, max);
	return 0;
}