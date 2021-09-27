#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char map[60][60];
int visit[60][60];
int q[4000][2];
int y[4] = { 0,1,0,-1 };
int x[4] = { 1,0,-1,0 };
int n, m, max = -1, head, tail;

void fun() {
	int r, c, tr, tc, start = 0, end = 0, count = 0;

	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= m + 1; j++)
			visit[i][j] = 0;

	while (tail >= head) {
		if (head > end) {
			count++;
			start = head;
			end = tail;
		}
		r = q[head][0];
		c = q[head++][1];
		visit[r][c] = 1;
		for (int i = 0; i < 4; i++) {
			tr = r + y[i];
			tc = c + x[i];
			if (map[tr][tc] == 'L' && !visit[tr][tc]) {
				q[++tail][0] = tr;
				q[tail][1] = tc;
				visit[tr][tc] = 1;
			}
		}
	}

	if (count > max)
		max = count;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= m + 1; j++)
			map[i][j] = 'W';
	getchar();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			scanf("%c", &map[i][j]);
		getchar();
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 'L') {
				head = 0, tail = 0;
				q[0][0] = i;
				q[0][1] = j;
				fun();
			}
		}

	printf("%d\n", max);

	return 0;
}