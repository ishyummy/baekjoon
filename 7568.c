#include <stdio.h>

int main() {
	int n, i, j, temp;
	int ang[3][50];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &ang[0][i], &ang[1][i]);
	}
	for (i = 0; i < n; i++) {
		temp = 1;
		for (j = 0; j < n; j++) {
			if (ang[0][i] < ang[0][j] && ang[1][i] < ang[1][j]) temp++;
		}
		ang[2][i] = temp;
	}
	for (i = 0; i < n; i++) {
		printf("%d ", ang[2][i]);
	}
	printf("\n");
	return 0;
}