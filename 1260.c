#include <stdio.h>

int map[1001][1001] = { 0, };
int visit[1001] = { 0, };
int visit2[1001] = { 0, };
int queue[1001];
int queue_head = 0;
int queue_tail = -1;
int n;

void DFS(int a) {
	printf("%d ", a);
	visit[a] = 1;
	for (int i = 1; i <= n; i++) {
		if (map[a][i] && !visit[i]) {
			DFS(i);
		}
	}
	return;
}

void BFS(int a) {
	printf("%d ", a);
	queue[0] = a;
	queue_tail++;
	visit2[a] = 1;

	while (queue_head <= queue_tail) {
		a = queue[queue_head++];
		for (int i = 1; i <= n; i++) {
			if (map[a][i] && !visit2[i]) {
				queue[++queue_tail] = i;
				visit2[i] = 1;
				printf("%d ", i);
			}
		}
	}
}

int main()
{
	int m, start, a, b;
	scanf("%d %d %d", &n, &m, &start);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		map[a][b] = 1;
		map[b][a] = 1;
	}
	DFS(start);
	printf("\n");
	BFS(start);
	printf("\n");
	return 0;
}