#include <stdio.h>

int map[200][200] = { 0 };
int r[4] = { 0,1,0,-1 };
int c[4] = { 1,0,-1,0 };
int com[200][2];
int snake[20000][2], head = 0, tail = 0;
int n, k, l, time = 0, dir = 0;

int main()
{
    int y, x;
    char t;
    scanf("%d", &n);
    scanf("%d", &k);

    for (int i = 0; i < k; i++) {
        scanf("%d %d", &y, &x);
        map[y - 1][x - 1] = 2;;
    }
    scanf("%d", &l);
    for (int i = 0; i < l; i++) {
        scanf("%d %c", &x, &t);
        com[i][0] = x;
        if (t == 'D')
            com[i][1] = 0;
        else
            com[i][1] = 1;
    }
    snake[0][0] = 0, snake[0][1] = 0;
    map[0][0] = 1;
    while (1) {
        for (int i = 0; i < l; i++)
            if (time == com[i][0]) {
                if (!com[i][1])
                    dir = (dir + 1) % 4;
                else
                    dir = (dir + 3) % 4;
            }
        time++;
        int new_y = snake[head][0] + r[dir];
        int new_x = snake[head][1] + c[dir];

        if (map[new_y][new_x] == 1 || new_y < 0 || new_y >= n || new_x < 0 || new_x >= n)
            break;
        else if (map[new_y][new_x] == 2) {
            map[new_y][new_x] = 1;
            snake[++head][0] = new_y;
            snake[head][1] = new_x;
        }
        else {
            map[new_y][new_x] = 1;
            snake[++head][0] = new_y;
            snake[head][1] = new_x;
            map[snake[tail][0]][snake[tail++][1]] = 0;
        }
    }
    printf("%d\n", time);
    return 0;
}