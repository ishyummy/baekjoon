#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i;
	float sum = 0, max = 0;
	float* ang;

	scanf("%d", &n);
	ang = (float*)malloc(sizeof(float) * n);
	for (i = 0; i < n; i++) {
		scanf("%f", &ang[i]);
		if (max < ang[i]) max = ang[i];
	}
	for (i = 0; i < n; i++) {
		ang[i] = ang[i] / (float)max * 100;
		sum += ang[i];
	}
	printf("%.2f", sum / (float)n);
    
	return 0;
}