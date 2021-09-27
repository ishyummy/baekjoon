#include <stdio.h>

int house[2000][3];
int DP[2000][3];

int MIN(int a, int b) { return a > b ? b : a; }

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &house[i][0], &house[i][1], &house[i][2]);
    for (int i = 0; i < 3; i++)
        DP[0][i] = house[0][i];
    for (int i = 1; i < n; i++)
        for (int j = 0; j < 3; j++)
            DP[i][j] = MIN(DP[i - 1][(j + 1) % 3] + house[i][j], DP[i - 1][(j + 2) % 3] + house[i][j]);

    if (DP[n - 1][0] <= DP[n - 1][1] && DP[n - 1][0] <= DP[n - 1][2])
        printf("%d\n", DP[n - 1][0]);
    else if (DP[n - 1][1] <= DP[n - 1][0] && DP[n - 1][1] <= DP[n - 1][2])
        printf("%d\n", DP[n - 1][1]);
    else
        printf("%d\n", DP[n - 1][2]);
    return 0;
}
