#include <stdio.h>
#include <math.h>

int map[100][100];
int visit[100][100];
int q[3000][2];
int n, L, R, count = 0, head = 0; tail = -1;
int y[4] = { 0, 1, 0, -1 };
int x[4] = { 1, 0, -1, 0 };

void bfs() {
    int yy, xx, r, c, sum = 0;
    while (tail >= head) {
        yy = q[head][0];
        xx = q[head++][1];
        for (int k = 0; k < 4; k++) {
            r = yy + y[k];
            c = xx + x[k];
            if (visit[r][c] != 1 && map[r][c] != -1 && abs(map[yy][xx] - map[r][c]) >= L && abs(map[yy][xx] - map[r][c]) <= R) {
                visit[r][c] = 1;
                q[++tail][0] = r;
                q[tail][1] = c;
            }
        }
    }
    for (int i = 0; i <= tail; i++)
        sum += map[q[i][0]][q[i][1]];
    for (int i = 0; i <= tail; i++)
        map[q[i][0]][q[i][1]] = sum / (tail + 1);
}

int fun() {
    int r, c, flag = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            visit[i][j] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (visit[i][j])
                continue;
            visit[i][j] = 1;
            for (int k = 0; k < 4; k++) {
                r = i + y[k];
                c = j + x[k];
                if (map[r][c] != -1 && abs(map[i][j] - map[r][c]) >= L && abs(map[i][j] - map[r][c]) <= R) {
                    flag = 1, head = 0, tail = -1;
                    q[++tail][0] = i;
                    q[tail][1] = j;
                    bfs();
                    break;
                }
            }
        }
    return flag;
}

int main()
{
    scanf("%d %d %d", &n, &L, &R);
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= n + 1; j++)
            map[i][j] = -1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &map[i][j]);

    while (1) {
        if (fun())
            count++;
        else
            break;
    }

    printf("%d\n", count);
    return 0;
}