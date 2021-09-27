#include <stdio.h>

int L, C;
int sel[20] = { 0 };
char c[20];

void fun(int a, int n, int mo, int ja) {
    if (n == 0 && mo >= 1 && ja >= 2) {
        for (int i = 0; i < C; i++)
            if (sel[i])
                printf("%c", c[i]);
        printf("\n");
        return;
    }
    else if (a < C && n > 0) {
        int x = 0, y = 0;
        if (c[a] == 'a' || c[a] == 'e' || c[a] == 'i' || c[a] == 'o' || c[a] == 'u')
            x = 1;
        else
            y = 1;
        sel[a] = 1;
        fun(a + 1, n - 1, mo + x, ja + y);
        sel[a] = 0;
        fun(a + 1, n, mo, ja);
    }
    else
        return;
}

int main()
{
    scanf("%d %d\n", &L, &C);
    for (int i = 0; i < C; i++) {
        scanf("%c", &c[i]);
        if (i < C - 1)
            scanf("\n");
    }
    for (int i = 0; i < C - 1; i++)
        for (int j = 0; j < C - i - 1; j++)
            if (c[j] > c[j + 1]) {
                int t = c[j];
                c[j] = c[j + 1];
                c[j + 1] = t;
            }

    fun(0, L, 0 ,0);
    return 0;
}
