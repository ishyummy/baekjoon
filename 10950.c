#include <stdio.h>

int main()
{
	int a, b, t, i;
	int **ang;
	scanf("%d", &t);
	ang = (int**)malloc(sizeof(int*) * t);
	for (i = 0; i < t; i++)
		ang[i] = (int*)malloc(sizeof(int) * 2);
	for (i = 0; i < t; i++)
		scanf("%d %d", &ang[i][0], &ang[i][1]);
	for (i = 0; i < t; i++)
		printf("%d\n", ang[i][0]+ang[i][1]);
	printf("\n");
	return 0;
}