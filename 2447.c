#include <stdio.h>

char ang[2200][2200] = { 0, };

int main() {
	int n, i, j, temp;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			temp = n;
			while (temp > 1) {
				if((i % temp >= (temp/3) && i % temp < (temp * 2/ 3)) && (j % temp >= (temp / 3) && j % temp < (temp * 2 / 3))) ang[i][j] = ' ';
				temp /= 3;
			}
			if(ang[i][j] == 0) ang[i][j] = '*';
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%c", ang[i][j]);
		}
		printf("\n");
	}

	return 0;
}