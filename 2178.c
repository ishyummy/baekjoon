#include <stdio.h>

int n, m;
int count[102][102] = { 0 };
int maze[102][102] = { 0 };
int visit[102][102] = { 0 };
int queue[20000][2];
int q_head = 0;
int q_tail = -1;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void BFS(int a, int b) {
	queue[++q_tail][0] = a;
	queue[q_tail][1] = b;
	visit[a][b] = 1;
	count[a][b] = 1;

	int x, y, tx, ty;

	while (q_head <= q_tail) {
		x = queue[q_head][0];
		y = queue[q_head++][1];

		if (x == n && y == m)
			break;
		for (int i = 0; i < 4; i++) {
			tx = x + dx[i], ty = y + dy[i];
			if (maze[tx][ty] && !visit[tx][ty]) {
				queue[++q_tail][0] = tx;
				queue[q_tail][1] = ty;
				count[tx][ty] = count[x][y] + 1;
				visit[tx][ty] = 1;
			}
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%1d", &maze[i][j]);

	BFS(1, 1);
	printf("%d\n", count[n][m]);

	return 0;
}