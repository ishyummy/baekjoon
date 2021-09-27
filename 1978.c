#include <stdio.h>

int main() {
	int t, n, count = 0, flag;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		flag = 0;
		for (int j = 2; j <= n / 2; j++)
			if (n % j == 0) flag = 1;
		if (!flag && n > 1) count++;
	}
	printf("%d\n", count);
    return 0;
}