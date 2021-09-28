#include <stdio.h>

int n, m;
int map[10] = {0};

void fun(int x, int y) {
	if (x == m)
	{
		for (int i = 1; i <= n; i++)
			if (map[i])
				printf("%d ", i);
		printf("\n");
		return;
	}
	if (y <= n) {
		map[y] = 1;
		fun(x + 1, y + 1);
		map[y] = 0;
		fun(x, y + 1);
	}
	else return;
}

int main() {
	scanf("%d %d", &n, &m);
	fun(0, 1);
}