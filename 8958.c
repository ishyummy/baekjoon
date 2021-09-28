#include <stdio.h>
#include <string.h>

int main()
{
	int n, i, j, count, sum, length;
	char ang[81];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		count = 0;
		sum = 0;
		scanf("%s", ang);
		length = strlen(ang);
		for (j = 0; j < length; j++) {
			if(ang[j] == 'O') {
				count++;
				sum += count;
			}
			else count = 0;
		}
		for (j = 0; j < length; j++) {
			ang[j] == 0;
		}
		printf("%d\n", sum);
	}

	return 0;
}