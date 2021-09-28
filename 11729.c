#include <stdio.h>

int count = 0, temp;

void hanoi(int n, int a, int b, int c) {
	if (n == 1) printf("%d %d\n", a, b);
	else {
		hanoi(n - 1, a, c, b);
		printf("%d %d\n", a, b);
		hanoi(n - 1, c, b, a);
	}
}

int main() {
	int n, i, count = 1;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		count *= 2;
	}
	printf("%d\n", --count);
	hanoi(n, 1, 3, 2);
	return 0;
}