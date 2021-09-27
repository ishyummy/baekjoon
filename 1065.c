#include <stdio.h>

int ang[1010] = { 0, };

void isit(int n) {
	int a, b, c, save;
	save = n;
	if (n < 100) ang[n] = 1;
	else if (n == 1000) return;
	else {
		a = n % 10;
		n /= 10;
		b = n % 10;
		n /= 10;
		c = n % 10;
		if (a - b == b - c) ang[save] = 1;
		else return;
	}
}


int main() {
	int n, i, sum = 0;

	scanf("%d", &n);
	for (i = 1; i <=n ; i++) {
		isit(i);
		if (ang[i] == 1) sum++;
	}
	printf("%d\n", sum);

	return 0;
}