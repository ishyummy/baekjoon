#include <stdio.h>

int main()
{
	int n, i;
	int ang[1000] = {1, 2,};
	scanf("%d", &n);
	for (i = 2; i < n; i++) {
		ang[i] += (ang[i - 1] + ang[i - 2]) % 10007;
	}
	printf("%d\n", ang[n-1]%10007);
	return 0;
}