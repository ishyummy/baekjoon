#include <stdio.h>
#include <math.h>

int main() {
	int n, i, temp;
	double root;
	scanf("%d", &n);
	root = sqrt(2 * n);
	i = (int)root;
	while (1) {
		if (i * (i - 1) / 2 < n && i * (i + 1) / 2 >= n) break;
		else i++;
	}
	temp = n - i * (i - 1) / 2 - 1;
	if (i % 2 == 0) {
		printf("%d/%d", temp + 1, i - temp);
	}
	else {
		printf("%d/%d", i - temp, temp + 1);
	}
	return 0;
}