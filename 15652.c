#include <stdio.h>

int n, m;
int map[10] = { 1, };

void fun(int x) {
	if (x == m)
	{
		for (int i = 1; i <= x; i++)
			printf("%d ", map[i]);
		printf("\n");
		return;
	}
	for (int i = map[x]; i <= n; i++) {
		map[x + 1] = i;
		fun(x + 1);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	fun(0);
}