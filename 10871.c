#include <stdio.h>

int main()
{
	int n, i, j=0, s, m;
	int* a;
	scanf("%d %d", &n, &s);
	a = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		scanf("%d", &m);
		if (m < s) a[j++] = m;
	}
	for (i = 0; i < j; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}