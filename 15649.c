#include <stdio.h>

int map[10] = {0};
int print[10];

void fun(int x, int n, int m) {
	if (x == m)
	{
		for (int i = 1; i <= m; i++)
			printf("%d ", print[i]);
		printf("\n");
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (map[i] == 0) {
			print[x + 1] = i;
			map[i] = 1;
			fun(x + 1, n, m);
			map[i] = 0;
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		print[1] = i;
		map[i] = 1;
		fun(1, n, m);
		map[i] = 0;
	}
}