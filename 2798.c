#include <stdio.h>

int main()
{
	int n, m, i, j, k, temp, ang[101], result = 0;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d", &ang[i]);
	}
	for (i = 0; i < n - 2; i++) {
		for (j = i + 1; j < n - 1; j++) {
			for (k = j + 1; k < n; k++) {
				if (ang[i] + ang[j] + ang[k] <= m && ang[i] + ang[j] + ang[k] >= result) {
					result = ang[i] + ang[j] + ang[k];
				}
			}
		}
	}
	printf("%d\n", result);
	return 0;
}