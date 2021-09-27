#include <stdio.h>

int wine[10010];
int dp[10010];

int MAX(int a, int b) { return a > b ? a : b; }

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &wine[i]);
    dp[0] = wine[0];
    dp[1] = wine[0] + wine[1];
    dp[2] = MAX(MAX(-wine[0], -wine[1]), -wine[2]) + wine[0] + wine[1] + wine[2];
    for (int i = 3; i < n; i++) {
        dp[i] = MAX(dp[i - 3] + wine[i - 1] + wine[i], dp[i - 2] + wine[i]);
        dp[i] = MAX(dp[i], dp[i - 1]);
    }

    printf("%d\n", dp[n - 1]);
    return 0;
}
