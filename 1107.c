#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N, M, mal[10] = { 0 };

int MIN(int a, int b) { return a > b ? b : a; }

int check(int n) {
    int flag = 0;
    do {
        if (mal[n % 10] == 1) {
            flag = 1;
            break;
        }
        n /= 10;
    } while (n > 0);
    if (flag)
        return 1;
    else
        return 0;
}

int main()
{
    int t, min = 987654321;
    scanf("%d", &N);
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &t);
        mal[t] = 1;
    }
    
    for (int i = 0; i < 1000000; i++) {
        int temp = (int)log10(i) + 1;
        if (i == 0) temp = 1;
        if (check(i))
            continue;

        if (temp + abs(N - i) < min) {
            min = temp + abs(N - i);
        }
    }
    
    printf("%d\n", MIN(abs(N - 100), min));

    return 0;
}