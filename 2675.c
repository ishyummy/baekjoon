#include <stdio.h>

int main() {
	int n, m, i, j, k;
	char ang[21] = { 0, };

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %s", &m, ang);
		j = 0;
		while (ang[j] != 0) {
			for (k = 0; k < m; k++) {
				printf("%c", ang[j]);
			}
			j++;
		}
		printf("\n");
	}
	return 0;
}