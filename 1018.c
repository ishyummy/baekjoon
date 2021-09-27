#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, m, min = 1000000, temp;
	char** map;

	scanf("%d %d", &m, &n);

	map = (char**)malloc(sizeof(char*) * m);
	for (int i = 0; i < m; i++) {
		map[i] = (char*)malloc(sizeof(char) * n);
		scanf("%s", map[i]);
	}

	for (int a = 0; a <= m - 8; a++)
		for (int b = 0; b <= n - 8; b++) {
			temp = 0;
			for (int i = 0; i < 8; i++)
				for (int j = 0; j < 8; j++) {
					if (i % 2 == j % 2 && map[a + i][b + j] != 'W')
						temp++;
					else if (i % 2 != j % 2 && map[a + i][b + j] != 'B')
						temp++;
				}
			if (temp < min) min = temp;
			temp = 0;
			for (int i = 0; i < 8; i++)
				for (int j = 0; j < 8; j++) {
					if (i % 2 == j % 2 && map[a + i][b + j] != 'B')
						temp++;
					else if (i % 2 != j % 2 && map[a + i][b + j] != 'W')
						temp++;
				}
			if (temp < min) min = temp;
		}
			
	printf("%d\n", min);
}