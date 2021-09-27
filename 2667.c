#include <stdio.h>

int map[30][30] = { 0 };
int visit[30][30] = { 0 };
int count[500] = { 0 };
int num = 2, flag;
int r[4] = { 0,1,0,-1 };
int c[4] = { 1,0,-1,0 };

void dfs(int y, int x) {
    map[y][x] = num;
    visit[y][x] = 1;
    for(int i = 0; i < 4; i++)
        if (map[y + r[i]][x + c[i]] == 1 && !visit[y + r[i]][x + c[i]])
            dfs(y + r[i], x + c[i]);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%1d", &map[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (visit[i][j] == 0 && map[i][j] == 1) {
                dfs(i, j);
                num++;
            }
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            count[map[i][j]]++;
        }

    for(int i = 2; i < num - 1; i++)
        for(int j = 2; j < num - i + 1; j++)
            if (count[j] > count[j + 1]) {
                int t = count[j];
                count[j] = count[j + 1];
                count[j + 1] = t;
            }

    printf("%d\n", num - 2);
    for (int i = 2; i < num; i++)
        printf("%d\n", count[i]);
    return 0;
}
