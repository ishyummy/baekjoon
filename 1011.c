#include <stdio.h>
#include <math.h>

int main() {
	int n, i;
	long long a, b, gap, t, count;
	double root;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%lld %lld", &a, &b);
		root = sqrt(b - a);
		t = (long long)root - 2;
		while (1) {
			if (t * (t + 1) <= b - a && (t + 2) * (t + 1) > b - a) break;
			else t++;
		}
		count = 2 * t;
		gap = b - a - t * (t + 1);
		if (gap > 0 && gap <= t + 1) count++;
		else if (gap > t + 1 && gap < 2 * t + 2) count += 2;
		printf("%lld\n", count);
	}

	return 0;
}