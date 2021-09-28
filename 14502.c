#include <stdio.h>

int n, m;
int map[10][10];
int zero[100][2];

int ang() {
    int temp[10][10];
    int count = 0;

    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
            temp[i][j] = map[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (temp[i][j] == 0 && (temp[i][j + 1] == 2 || temp[i][j - 1] == 2 || temp[i + 1][j] == 2 || temp[i - 1][j] == 2))
                temp[i--][j--] = 2;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (temp[i][j] == 0)
                count++;

    return count;
}

int main()
{
    int max = -1, a = 0, t;
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
            map[i][j] = 1; //initialize

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 0) {
                zero[a][0] = i;
                zero[a++][1] = j;
            }
        }

    for(int i = 0; i < a-2; i++)
        for(int j = i + 1; j < a - 1; j++) 
            for (int k = j + 1; k < a; k++) {
                map[zero[i][0]][zero[i][1]] = 1;
                map[zero[j][0]][zero[j][1]] = 1;
                map[zero[k][0]][zero[k][1]] = 1;
                t = ang();
                if (max < t)
                    max = t;
                map[zero[i][0]][zero[i][1]] = 0;
                map[zero[j][0]][zero[j][1]] = 0;
                map[zero[k][0]][zero[k][1]] = 0;
            }
            

    printf("%d\n", max);

    return 0;
}