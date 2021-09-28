#include <stdio.h>
#include <string.h>

int ang[10001], toptop = -1;

void push(int a) {
	ang[++toptop] = a;
}

void pop() {
	if (toptop == -1) printf("-1\n");
	else printf("%d\n", ang[toptop--]);
}

void top() {
	if (toptop == -1) printf("-1\n");
	else printf("%d\n", ang[toptop]);
}

void size() {
	printf("%d\n", toptop + 1);
}

void empty() {
	if (toptop == -1) printf("1\n");
	else printf("0\n");
}

int main()
{
	int i, j, n, a;
	char gang[13], temp1, temp2;
	scanf("%d", &n);
	for (i = 0; i <= n; i++) {
		a = 0;
		gets(gang);
		if (gang[0] == 'p' && gang[1] == 'u') {
			for (j = 5; j < 13; j++) {
				if (!gang[j]) break;
				else {
					a *= 10;
					a += gang[j] - '0';
				}
			}
			push(a);
		}
		else if (gang[0] == 'p') pop();
		else if (gang[0] == 's') size();
		else if (gang[0] == 'e') empty();
		else if (gang[0] == 't') top();
		for (j = 0; j < 13; j++) {
			gang[j] = NULL;
		}
	}
	return 0;
}