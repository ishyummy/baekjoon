#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, j, n, c, sum;
	int** ang;
	float percent, average, count;

	scanf("%d",&c);
	ang = (int**)malloc(sizeof(int*) * c);
	for (i = 0; i < c; i++) {
		scanf("%d", &n);
		ang[i] = (int*)malloc(sizeof(int) * n);
		sum = 0;
		for (j = 0; j < n; j++) {
			scanf("%d", &ang[i][j]);
			sum += ang[i][j];
		}
		average = sum / n;
		count = 0;
		for (j = 0; j < n; j++) {
			if ((float)ang[i][j] > average) count++;
		}
		percent = count / (float)n * 100;
		printf("%.3f%c\n", percent,'%');
	}
	return 0;
}