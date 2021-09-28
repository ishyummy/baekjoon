#include <stdio.h>

int main() {
	int count = 0, n, i = 0, max = 0;
	scanf("%d", &n);
	while (n - i * 5 >= 0) {
		if ((n - i * 5) % 3 == 0) max = i;
		i++;
	}
	if ((n - max * 5) % 3 != 0) printf("-1\n");
	else printf("%d\n", max + (n - max * 5) / 3);
	return 0;
}