#include <stdio.h>

int map[501][501];
int dp[501][501];

int max(int a, int b) { return a > b ? a : b; }

int main()
{
	int n, result = -1;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			scanf("%d", &map[i][j]);

	dp[0][0] = map[0][0];
	for (int i = 1; i < n; i++)
		for (int j = 0; j <= i; j++) {
			int left, right;
			if (!j)
				left = -1;
			else
				left = dp[i - 1][j - 1];
			if (j == i)
				right = -1;
			else
				right = dp[i - 1][j];

			dp[i][j] = max(map[i][j] + left, map[i][j] + right);
		}

	for (int i = 0; i < n; i++)
		if (result < dp[n - 1][i])
			result = dp[n - 1][i];

	printf("%d\n", result);

	return 0;
}