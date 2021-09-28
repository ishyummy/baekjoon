#include <stdio.h>

int main() {
	int n = 0, i, ang[26];
	char word[101] = { 0, };
	for (i = 0; i < 26; i++) {
		ang[i] = -1;
	}
	scanf("%s", word);
	while (word[n] != 0) {
		if(ang[word[n] - 'a'] == -1) ang[word[n] - 'a'] = n;
		n++;
	}
	for (i = 0; i < 26; i++) {
		printf("%d ", ang[i]);
	}
	printf("\n");
	return 0;
}