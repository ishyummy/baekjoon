#include <stdio.h>

int main() {
	int n, i, count = 0;
	char ang[17];
	scanf("%s", ang);
	for (i = 0; ang[i] != 0; i++) {
		if (ang[i] >= 'A' && ang[i] <= 'C') count += 3;
		else if (ang[i] >= 'D' && ang[i] <= 'F') count += 4;
		else if (ang[i] >= 'G' && ang[i] <= 'I') count += 5;
		else if (ang[i] >= 'J' && ang[i] <= 'L') count += 6;
		else if (ang[i] >= 'M' && ang[i] <= 'O') count += 7;
		else if (ang[i] >= 'P' && ang[i] <= 'S') count += 8;
		else if (ang[i] >= 'T' && ang[i] <= 'V') count += 9;
		else if (ang[i] >= 'W' && ang[i] <= 'Z') count += 10;
	}
	printf("%d\n", count);
	return 0;
}