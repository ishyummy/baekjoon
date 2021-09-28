#include <stdio.h>

int main() {
	int M, N, x, y, i, a, temp;

	scanf("%d", &a);
	for (i = 0; i < a; i++) {
		scanf("%d %d %d %d", &M, &N, &x, &y);
		if (M >= N) {
			for (temp = x; temp <= M * N; ) {
				if (temp % N == y || temp % N + N == y) break;
				else temp += M;
			}
			if (temp <= M * N) printf("%d\n", temp);
			else printf("-1\n");
		}
		else {
			for (temp = y; temp <= M * N; ) {
				if (temp % M == x || temp % M + M == x) break;
				else temp += N;
			}
			if (temp <= M * N) printf("%d\n", temp);
			else printf("-1\n");
		}
	}
	return 0;
}