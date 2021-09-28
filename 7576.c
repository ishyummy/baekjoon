#include <stdio.h>

int map[1010][1010];
int visit[1010][1010] = { 0 };
int q[1000010][2];
int q_head = 0, q_tail = -1, start, end;
int r[4] = { 0,1,0,-1 };
int c[4] = { 1,0,-1,0 };
int count = 0;

int main()
{
    int n, m, y, x, flag = 0;
    scanf("%d %d", &n, &m);

    for (int i = 0; i <= m + 1; i++)
        for (int j = 0; j <= n + 1; j++)
            map[i][j] = -1;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &map[i][j]);

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            for(int k = 0; k < 4; k++)
                if (map[i][j] == 1 && map[i + r[k]][j + c[k]] == 0) {
                    q[++q_tail][0] = i;
                    q[q_tail][1] = j;
                    break;
                }
    start = q_head, end = q_tail;
    while (q_head <= q_tail) {
        if (q_head > end) {
            start = q_head, end = q_tail;
            count++;
        }
        y = q[q_head][0];
        x = q[q_head++][1];
        if (visit[y][x] == 1)
            continue;
        visit[y][x] = 1;
        for (int i = 0; i < 4; i++) {
            if (map[y + r[i]][x + c[i]] == 0) {
                map[y + r[i]][x + c[i]] = 1;
                q[++q_tail][0] = y + r[i];
                q[q_tail][1] = x + c[i];
            }
        }
    }

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (map[i][j] == 0)
                flag = 1;
    if (flag)
        printf("-1\n");
    else
        printf("%d\n", count);

    return 0;
}
