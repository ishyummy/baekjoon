#include <stdio.h>

char ang[1000010] = { 0, };

int main() {
	int count = 0, i;
	scanf("%[^\n]s", ang);
	for (i = 0; ang[i] != 0; i++) {
		if (i == 0 && ang[i] != ' ') count++;
		else if (i > 0 && ang[i] != ' ' && ang[i - 1] == ' ') count++;
	}
	printf("%d\n", count);
	return 0;
}