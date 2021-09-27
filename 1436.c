#include <stdio.h>

int six(int n) {
	int flag1 = 0, flag2 = 0, t = n;
	while (t > 0) {
		if (t % 10 == 6) {
			if (flag1 && flag2) return 1;
			else if (flag1) flag2 = 1;
			else flag1 = 1;
		}
		else {
			flag1 = 0;
			flag2 = 0;
		}
		t /= 10;
	}
	return 0;
}

int main() {
	int n, m = 666, t = 0;
	scanf("%d", &n);

	while (t < n) {
		if (six(m))	t++;
		m++;
	}

	printf("%d\n", m - 1);
}