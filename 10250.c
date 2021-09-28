#include <stdio.h>

int main() {
	int a, i, h, w, n;
	scanf("%d", &a);
	for (i = 0; i < a; i++) {
		scanf("%d %d %d", &h, &w, &n);
		if (n % h == 0) printf("%d\n", h * 100 + n / h );
		else printf("%d\n", n % h * 100 + n / h + 1);
	}
	return 0;
}