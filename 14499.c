#include <stdio.h>

int map[30][30];
int dice[7] = { 0 };
int dice2[7];
int r[4] = { 0, 0, -1, 1 };
int c[4] = {1, -1, 0, 0};

void east() {
    dice2[1] = dice[4];
    dice2[3] = dice[1];
    dice2[4] = dice[6];
    dice2[6] = dice[3];
}

void west() {
    dice2[1] = dice[3];
    dice2[3] = dice[6];
    dice2[4] = dice[1];
    dice2[6] = dice[4];
}

void south() {
    dice2[1] = dice[2];
    dice2[2] = dice[6];
    dice2[5] = dice[1];
    dice2[6] = dice[5];
}

void north() {
    dice2[1] = dice[5];
    dice2[2] = dice[1];
    dice2[5] = dice[6];
    dice2[6] = dice[2];
}

int main()
{
    int n, m, x, y, k, t;
    scanf("%d %d %d %d %d\n", &n, &m, &x, &y, &k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &map[i][j]);
    for (int i = 0; i < k; i++) {
        scanf("%d", &t);
        if (x + r[t - 1] < 0 || x + r[t - 1] >= n || y + c[t - 1] < 0 || y + c[t - 1] >= m)
            continue;
        else {
            x += r[t - 1];
            y += c[t - 1];
            switch (t) {
            case 1 : 
                east();
                break;
            case 2:
                west();
                break;
            case 3 :
                north();
                break;
            case 4 :
                south();
                break;
            }
            for (int i = 1; i <= 6; i++)
                dice[i] = dice2[i];
            if (map[x][y] == 0)
                map[x][y] = dice[6];
            else {
                dice[6] = map[x][y];
                map[x][y] = 0;
            }
            printf("%d\n", dice[1]);
        }
    }
        
    return 0;
}