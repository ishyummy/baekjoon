#include <stdio.h>

int main()
{
	int n, i, j;
	long long ang[100][10] = {0,1,1,1,1,1,1,1,1,1,}, sum = 0;
	scanf("%d", &n);
	for (i = 1; i < n; i++) {
		ang[i][0] = ang[i - 1][1];
		ang[i][9] = ang[i - 1][8];
		for (j = 1; j < 9; j++) {
			ang[i][j] = (ang[i - 1][j - 1] + ang[i - 1][j + 1]) % 1000000000;
		}
	}
	for (i = 0; i < 10; i++) {
		sum += ang[n-1][i];
	}
	printf("%d\n", sum%1000000000);
	return 0;
}