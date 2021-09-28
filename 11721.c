#include <stdio.h>

int main()
{
	char ang[101];
	fgets(ang, 100, stdin);
	for (int i = 0; ang[i] != '\0'; i++) {
		printf("%c", ang[i]);
		if (i % 10 == 9)
			printf("\n");
	}
	
	return 0;
}