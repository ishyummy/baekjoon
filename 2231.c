#include <stdio.h>

int sum(int n) {
	int temp, count = 0;
	temp = n;
	while (temp > 0) {
		count += temp % 10;
		temp /= 10;
	}
	return count;
}

int main() {
	int n, i;

	scanf("%d", &n);
	i = n - 9 * n / 10;
	if (i < 0) i = 0;
	while (i <= n) {
		if (i + sum(i) == n) break;
		i++;
	}
	if (i > n) printf("0\n");
	else printf("%d\n", i);

	return 0;
}