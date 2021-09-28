#include <stdio.h>

int map[100][100];
int temp[100][100];
int r, c, t, count = 0, r1, r2, flag = 0;
int y[4] = { 1,0,-1,0 };
int x[4] = { 0,1,0,-1 };


void fun() {
	int s, t1, t2;
	for (int i = 1; i <= r; i++) // initialize
		for (int j = 1; j <= c; j++)
			temp[i][j] = 0;
	for (int i = 1; i <= r; i++) // spread
		for (int j = 1; j <= c; j++) {
			if (map[i][j] == -1)
				continue;
			s = map[i][j] / 5;
			for (int k = 0; k < 4; k++)
				if (map[i + y[k]][j + x[k]] != -1) {
					map[i][j] -= s;
					temp[i + y[k]][j + x[k]] += s;
				}
		}
	for (int i = 1; i <= r; i++) // after the spread
		for (int j = 1; j <= c; j++)
			map[i][j] += temp[i][j];

	t1 = map[r1][c]; // upper AC
	for (int i = c; i >= 3; i--)
		map[r1][i] = map[r1][i - 1];
	map[r1][2] = 0;

	t2 = map[1][c];
	for (int i = 1; i <= r1 - 2; i++)
		map[i][c] = map[i + 1][c];
	map[r1 - 1][c] = t1;

	t1 = map[1][1];
	for (int i = 1; i <= c - 2; i++)
		map[1][i] = map[1][i + 1];
	map[1][c-1] = t2;

	for (int i = r1 - 1; i >= 3; i--)
		map[i][1] = map[i - 1][1];
	map[2][1] = t1;


	t1 = map[r2][c]; // lower AC
	for (int i = c; i >= 3; i--)
		map[r2][i] = map[r2][i - 1];
	map[r2][2] = 0;

	t2 = map[r][c];
	for (int i = r; i >= r2 + 2; i--)
		map[i][c] = map[i - 1][c];
	map[r2 + 1][c] = t1;

	t1 = map[r][1];
	for (int i = 1; i <= c - 2; i++)
		map[r][i] = map[r][i + 1];
	map[r][c - 1] = t2;

	for (int i = r2 + 1; i <= r - 2; i++)
		map[i][1] = map[i + 1][1];
	map[r - 1][1] = t1;
}

int main()
{
	scanf("%d %d %d\n", &r, &c, &t);
	for (int i = 0; i <= r + 1; i++)
		for (int j = 0; j <= c + 1; j++) {
			map[i][j] = -1;
			temp[i][j] = -1;
		}
			
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == -1 && flag == 0) {
				r1 = i;
				flag = 1;
			}
			else if (map[i][j] == -1)
				r2 = i;
		}
			

	for (int i = 0; i < t; i++)
		fun();

	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			count += map[i][j];

	printf("%d\n", count + 2);
}