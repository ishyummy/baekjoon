#include <stdio.h>
#include <math.h>

int main() {

	int n, i;
	double root;
	scanf("%d", &n);

	root = sqrt(n/3);
	i = (int)root;
	while (1) {
		if (n == 1) break;
		else if (i * (i - 1) * 3 + 1 < n && i * (i + 1) * 3 + 1 >= n) break;
		else i++;
	}
	printf("%d\n", i+1);
	return 0;
}