#include <stdio.h>

int main()
{
    int n, t, max = 0, MAX = 0, minus = -9999;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        if (t > minus)
            minus = t;
        max += t;
        if (max > MAX)
            MAX = max;
        if (max < 0)
            max = 0;
    }
    if (MAX != 0)
        printf("%d\n", MAX);
    else
        printf("%d\n", minus);

    return 0;
}