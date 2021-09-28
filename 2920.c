#include <stdio.h>

int main()
{
	int ang[8], i;
	for (i = 0; i < 8; i++) {
		scanf("%d", &ang[i]);
	}
	if (ang[0]==1 && ang[1] == 2 && ang[2] == 3 && ang[3] == 4 && ang[4] == 5 && ang[5] == 6 && ang[6] == 7 && ang[7] == 8) printf("ascending\n");
	else if (ang[0] == 8 && ang[1] == 7 && ang[2] == 6 && ang[3] == 5 && ang[4] == 4 && ang[5] == 3 && ang[6] == 2 && ang[7] == 1) printf("descending\n");
	else printf("mixed\n");
	return 0;
}