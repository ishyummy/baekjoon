#include <stdio.h>

int prime[1000001] = { 0 };

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    for (int i = 2; i <= n; i++) {
        for (int j = i * 2; j <= n; j += i)
            prime[j] = 1;
    }

    for (int i = m; i <= n; i++)
        if (prime[i] == 0 && i != 1)
            printf("%d\n", i);

    return 0;
}