#include <stdio.h>
#include <string.h>

char a[2000];
char b[2000];
int dp[1010][1010] = { 0 };

int MAX(int a, int b) { return a > b ? a : b; }

int main()
{
    scanf("%s", a);
    scanf("%s", b);

    for (int i = 0; i < strlen(a); i++) {
        for (int j = 0; j < strlen(b); j++) {
            if (a[i] == b[j])
                dp[i + 1][j + 1] = dp[i][j] + 1;
            else
                dp[i + 1][j + 1] = MAX(dp[i][j + 1], dp[i + 1][j]);
        }
    }

    printf("%d\n", dp[strlen(a)][strlen(b)]);

    return 0;
}