#include <stdio.h>

int main()
{
	int a;
	scanf("%d", &a);
	if (a % 4) printf("0\n");
	else {
		if (!(a % 400)) printf("1\n");
		else if (!(a % 100)) printf("0\n");
		else printf("1\n");
	}

	return 0;
}