#include <stdio.h>

int map[20];
int n, count = 0;

void queen(int level) {
    int flag;

    if (level == 0) {
        count++;
        return;
    }
    for (int i = 0; i < n; i++) {
        flag = 0;
        for (int j = 0; j < n - level; j++)
            if (map[j] == i || n - level - j == map[j] - i || j + level - n == map[j] - i) {
                flag = 1;
                break;
            }
        if (flag)
            continue;
        map[n - level] = i;
        queen(level - 1);
    }
}

int main()
{
    scanf("%d", &n);
    queen(n);
    printf("%d\n", count);
    return 0;
}