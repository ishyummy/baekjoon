#include <stdio.h>

int main() {
	int t, i, j, l, m, k, n;
	int ang[15][15];

	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%d %d", &k, &n);
		for (j = 0; j < n; j++) {
			ang[0][j] = j+1;
		}
		for (j = 1; j <= k; j++) {
			for (l = 0; l < n; l++) {
				ang[j][l] = 0;
				for (m = 0; m <= l; m++) {
					ang[j][l] += ang[j - 1][m];
				}
			}
		}
		printf("%d\n", ang[k][n - 1]);
	}
	return 0;
}