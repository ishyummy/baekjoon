#include <stdio.h>

int main()
{
	char ang[101];
	while (fgets(ang, 100, stdin)) {
		printf("%s", ang);
	}
	
	return 0;
}