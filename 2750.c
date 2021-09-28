#include <stdio.h>
#define SWAP(a,b) {int t; t=a; a=b; b=t;}

int main() {
	int n;
	int arr[1000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1]) SWAP(arr[j], arr[j + 1]);

	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);
}