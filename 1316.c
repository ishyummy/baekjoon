#include <stdio.h>

int main() {
	int n, i, j, count = 0;
	int alphabet[26] = { 0 , };
	char ang[102];

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%s", ang);
		for (j = 0; ang[j] != 0; j++) {
			if (alphabet[ang[j] - 'a'] != 0 && alphabet[ang[j] - 'a'] - j != 0) break;
			else alphabet[ang[j] - 'a'] = j+1;
		}
		if (ang[j] == 0) count++;

		for (j = 0; j < 26; j++) {
			alphabet[j] = 0;
		}
		for (j = 0; j < 102; j++) {
			ang[j] = 0;
		}
	}
	
	printf("%d\n", count);
	return 0;
}