#include <stdio.h>

int main()
{
	int ang[1001], i, j, n, temp,cost = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &ang[i]);
	}
	for (i = 0; i < n-1; i++) {
		for (j = 0; j < n-i-1; j++) {
			if (ang[j] > ang[j + 1]) {
				temp = ang[j]; ang[j] = ang[j + 1]; ang[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < n; i++) {
		cost += ang[i] * (n - i);
	}
	printf("%d\n", cost);
	return 0;
}