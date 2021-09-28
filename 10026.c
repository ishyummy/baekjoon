#include <stdio.h>

char map[200][200] = { 0 };
int visit[200][200] = { 0 };
int count = 0, count2 = 0;
int r[4] = { 0,1,0,-1 };
int c[4] = { 1,0,-1,0 };

void dfs(int y, int x, char RGB) {
    visit[y][x] = 1;
    for (int i = 0; i < 4; i++)
        if (!visit[y + r[i]][x + c[i]] && map[y + r[i]][x + c[i]] == RGB)
            dfs(y + r[i], x + c[i], RGB);
}

int main()
{
    int n;
    char c;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%s", &map[i][1]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!visit[i][j]) {
                count++;
                dfs(i, j, map[i][j]);
            }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            visit[i][j] = 0;
            if (map[i][j] == 'R')
                map[i][j] = 'G';
        }


    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!visit[i][j]) {
                count2++;
                dfs(i, j, map[i][j]);
            }

    printf("%d %d\n", count, count2);
    return 0;
}