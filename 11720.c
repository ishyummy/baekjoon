#include <stdio.h>

int main() {
	int n, i, sum = 0;
	char *c;
	scanf("%d", &n);
	c = (char*)malloc(sizeof(char) * (n + 2));
	scanf("%s", c);
	for (i = 0; i < n; i++) {
		sum += c[i] - '0';
	}
	printf("%d\n", sum);

}