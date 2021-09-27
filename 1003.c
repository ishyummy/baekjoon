#include <stdio.h>

int main()
{
	int n, i, temp, ang[41];
	scanf("%d", &n);
	ang[0] = ang[1] = 1;
	for (i = 2; i < 41; i++) {
		ang[i] = ang[i - 1] + ang[i - 2];
	}
	for (i = 0; i < n; i++) {
		scanf("%d", &temp);
		if (!temp) printf("1 0\n");
		else if (temp == 1) printf("0 1\n");
		else printf("%d %d\n", ang[temp-2], ang[temp-1]);
	}
	return 0;
}