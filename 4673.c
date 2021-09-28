#include <stdio.h>

int ang[10010] = { 0, };

int self(int a) {
	int temp = 0, save = a;

	while (save / 10) {
		temp += save % 10;
		save /= 10;
	}
	temp += save % 10;

	return a + temp;
}

void work(int a) {
	if (a < 10001) {
		ang[a] = 1;
		work(self(a));
	}
	else return;
}

int main() {
	int i;

	for (i = 1; i < 10001; i++) {
		if (ang[i] == 0) {
			work(self(i));
			printf("%d\n", i);
		}
	}

	return 0;
}