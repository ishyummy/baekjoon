#include <stdio.h>

int main() {
	int n;
	long long a = 0, b = 1, c = 1;
	scanf("%d", &n);
	if (n < 3) printf("1\n");
	else {
		while (n > 2) {
			a = b;
			b = c;
			c = a + b;
			n--;
		}
		printf("%lld\n", c);
	}
	return 0;
}