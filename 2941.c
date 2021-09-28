#include <stdio.h>

int main() {
	int n, i, count = 0;
	char ang[102];
	scanf("%s", ang);
	for (i = 0; ang[i] != 0; i++) {
		if (i <= 98) {
			if (i <= 97 && ang[i] == 'd' && ang[i + 1] == 'z' && ang[i + 2] == '=') {
				i += 2;
				count++;
			}
			else if (ang[i] == 'c' && ang[i + 1] == '=') {
				i++;
				count++;
			}
			else if (ang[i] == 'c' && ang[i + 1] == '-') {
				i++;
				count++;
			}
			else if (ang[i] == 'd' && ang[i + 1] == '-') {
				i++;
				count++;
			}
			else if (ang[i] == 'l' && ang[i + 1] == 'j') {
				i++;
				count++;
			}
			else if (ang[i] == 'n' && ang[i + 1] == 'j') {
				i++;
				count++;
			}
			else if (ang[i] == 's' && ang[i + 1] == '=') {
				i++;
				count++;
			}
			else if (ang[i] == 'z' && ang[i + 1] == '=') {
				i++;
				count++;
			}
			else count++;
		}
		else count++;
	}
	printf("%d\n", count);
	return 0;
}