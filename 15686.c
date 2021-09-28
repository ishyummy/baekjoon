#include <stdio.h>
#include <math.h>

int map[100][100];
int chicken[100][2];
int house[110][2];
int dist[110][100];
int sel[100] = { 0 };
int c_top = -1, h_top = -1, ang = 999999999;

void dfs(int a, int n) {
    if (n == 0) {
        int sum = 0, min;
        for (int i = 0; i <= h_top; i++) { // dist table 에서 전체 치킨 거리 합 구함
            min = 999999999;
            for (int j = 0; j <= c_top; j++) {
                if (sel[j] == 1 && dist[i][j] < min)
                    min = dist[i][j];
            }
            sum += min;
        }
        if (sum < ang)
            ang = sum;
        // 전체 치킨 거리 계산, min update
    }
    else if (a <= c_top && n > 0) {
        sel[a] = 1;
        dfs(a + 1, n - 1);
        sel[a] = 0;
        dfs(a + 1, n);
    }
    else
        return;
}

int main()
{
    int n, m, sum = 0;
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1) {
                house[++h_top][0] = i;
                house[h_top][1] = j;
            }
            else if (map[i][j] == 2) {
                chicken[++c_top][0] = i;
                chicken[c_top][1] = j;
            }
        }
    for (int i = 0; i <= h_top; i++) {
        for (int j = 0; j <= c_top; j++)
            dist[i][j] = abs(house[i][0] - chicken[j][0]) + abs(house[i][1] - chicken[j][1]);
    } // 각 집에서 각 치킨 집까지의 distance 계산해놓음

    dfs(0, m);

    printf("%d\n", ang);

    return 0;
}