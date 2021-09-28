#include <stdio.h>

int n, m, map[10][10], min = 987654321;
int r[4] = { 0,1,0,-1 };
int c[4] = { 1,0,-1,0 };

void fill(int y, int x, int rot) {
    y += r[rot];
    x += c[rot];
    while (1 <= y && y <= n && 1 <= x && x <= m) {
        if (map[y][x] == 6)
            break;
        if (map[y][x] == 0 || map[y][x] >= 9)
            map[y][x] += 9;
        y += r[rot];
        x += c[rot];
    }
}

void erase(int y, int x, int rot) {
    y += r[rot];
    x += c[rot];
    while (1 <= y && y <= n && 1 <= x && x <= m) {
        if (map[y][x] == 6)
            break;
        if (map[y][x] >= 9)
            map[y][x] -= 9;
        y += r[rot];
        x += c[rot];
    }
}

int fun() {
    int count = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (map[i][j] == 0)
                count++;
    return count;
}

void dfs(int y, int x) {
    if (y == n + 1) {
        if (fun() < min)
            min = fun();
        return;
    }
    if (map[y][x] == 0 || map[y][x] == 5 || map[y][x] == 6 || map[y][x] >= 9) {
        if (x == m)
            dfs(y + 1, 1);
        else
            dfs(y, x + 1);
    }
    else if (map[y][x] == 1) {
        for (int i = 0; i < 4; i++) {
            fill(y, x, i);
            if (x == m)
                dfs(y + 1, 1);
            else
                dfs(y, x + 1);
            erase(y, x, i);
        }
    }
    else if (map[y][x] == 2) {
        for (int i = 0; i < 2; i++) {
            fill(y, x, i);
            fill(y, x, i + 2);
            if (x == m)
                dfs(y + 1, 1);
            else
                dfs(y, x + 1);
            erase(y, x, i);
            erase(y, x, i + 2);
        }
    }
    else if (map[y][x] == 3) {
        for (int i = 0; i < 4; i++) {
            fill(y, x, i);
            fill(y, x, (i + 1) % 4);
            if (x == m)
                dfs(y + 1, 1);
            else
                dfs(y, x + 1);
            erase(y, x, i);
            erase(y, x, (i + 1) % 4);
        }
    }
    else if (map[y][x] == 4) {
        for (int i = 0; i < 4; i++) {
            fill(y, x, i);
            fill(y, x, (i + 1) % 4);
            fill(y, x, (i + 2) % 4);
            if (x == m)
                dfs(y + 1, 1);
            else
                dfs(y, x + 1);
            erase(y, x, i);
            erase(y, x, (i + 1) % 4);
            erase(y, x, (i + 2) % 4);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            map[i][j] = 6;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &map[i][j]);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (map[i][j] == 5)
                for (int k = 0; k < 4; k++)
                    fill(i, j, k);

    dfs(1, 1);

    printf("%d\n", min);
    return 0;
}