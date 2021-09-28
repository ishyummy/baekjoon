#include <stdio.h>
#include <string.h>

int main()
{
	int n, i, j, length, left, right, flag;
	char ang[51];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", ang);
		length = strlen(ang);
		left = right = flag = 0;

		for (j = 0; j < length; j++) {
			if (ang[j] == '(') left++;
			else if (ang[j] == ')') right++;
			if (right > left) {
				flag = 1; break;
			}
		}
		if (left != right) flag = 1;
		if (flag) printf("NO\n");
		else printf("YES\n");

		for (j = 0; j < length; j++) {
			ang[j] == 0;
		}
	}

	return 0;
}