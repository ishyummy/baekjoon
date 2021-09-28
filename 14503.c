#include <stdio.h>

int map[60][60];
int visit[60][60] = { 0 };
int tx[4] = { 0, 1, 0, -1 }; // N, E, S, W // rotate -> index--;
int ty[4] = { -1, 0, 1, 0 };
int n, m, r, c, d, count = 0;

int main()
{
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &r, &c, &d);
    r++, c++;
    for (int i = 0; i < n + 2; i++)
        for (int j = 0; j < m + 2; j++)
            map[i][j] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &map[i][j]);

    while (1) {
        int flag = 0;
        int x, y;
        visit[r][c] = 1;
        count++;
        for (int i = 0; i < 4; i++) {
            x = c + tx[(d + 3 - i) % 4];
            y = r + ty[(d + 3 - i) % 4];
            if (map[y][x] == 0 && visit[y][x] == 0) {
                d = d + 3 - i;
                r = y;
                c = x;
                break;
            }
            if (i == 3 && map[r - ty[d % 4]][c - tx[d % 4]] == 1)
                flag = 1;
            else if (i == 3 && map[r - ty[d % 4]][c - tx[d % 4]] == 0) {
                r -= ty[d % 4];
                c -= tx[d % 4];
                i = -1;
            }
        }
        if (flag)
            break;
    }

    printf("%d\n", count);

    return 0;
}