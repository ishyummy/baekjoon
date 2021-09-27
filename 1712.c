#include <stdio.h>

int main()
{
	long long a, b, c;
	scanf("%lld %lld %lld", &a, &b, &c);
	if (c <= b) printf("-1\n");
	else printf("%lld\n", a / (c - b) + 1);
	return 0;
}