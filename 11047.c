#include <stdio.h>

int main()
{
	int coin_num, price, count = 0, i, temp;
	int coin[10];
	scanf("%d %d", &coin_num, &price);
	for (i = 0; i < coin_num; i++) {
		scanf("%d", &coin[i]);
	}
	while (price) {
		i = 0;
		while (i < coin_num - 1) {
			if (coin[i] <= price && coin[i + 1] > price) break;
			else i++;
		}
		temp = price / coin[i];
		count += temp;
		price -= coin[i] * temp;
	}
	printf("%d\n", count);
	return 0;
}