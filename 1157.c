#include <stdio.h>

int main() {
	int ang[26] = { 0, }, max = 0, overlap = -1, i;
	char c[1000010] = { 0, };

	scanf("%s", c);
	for(i=0; c[i] != 0; i++) {
		if (c[i] >= 'a' && c[i] <= 'z') ang[c[i] - 'a']++;
		else if (c[i] >= 'A' && c[i] <= 'Z') ang[c[i] - 'A']++;
	}

	for (i = 0; i < 26; i++) {
		if (ang[i] > ang[max]) max = i;
	}
	for (i = 0; i < 26; i++) {
		if (ang[i] == ang[max]) overlap++;
	}
	if (overlap) printf("?\n");
	else printf("%c\n", max + 'A');
	return 0;
}