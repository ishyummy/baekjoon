#include <stdio.h>

int map[50][50];
int a, m, n, k, x, y;

void spread(int i, int j) {
	map[i][j] = 2;
	if (i > 0)
		if (map[i - 1][j] == 1) spread(i - 1, j);
	if (i < n - 1)
		if (map[i + 1][j] == 1) spread(i + 1, j);
	if (j > 0)
		if (map[i][j - 1] == 1) spread(i, j - 1);
	if (j < m - 1)
		if (map[i][j + 1] == 1) spread(i, j + 1);
}

int calc() {
	int count = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[i][j] == 1) {
				count++;
				spread(i, j);
			}

	return count;
}

int main() {
	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		scanf("%d %d %d", &m, &n, &k);
		for (int ii = 0; ii < n; ii++)
			for (int iii = 0; iii < m; iii++)
				map[ii][iii] = 0;
		for (int j = 0; j < k; j++) {
			scanf("%d %d", &x, &y);
			map[y][x] = 1;
		}
		printf("%d\n", calc());
	}
	return 0;
}