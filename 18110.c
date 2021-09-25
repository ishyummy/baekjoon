#include <stdio.h>
#include <stdlib.h>

int n, cut, sum = 0;
int arr[300100];

int compare(const void* a, const void* b)
{
    int num1 = *(int*)a;
    int num2 = *(int*)b;

    if (num1 < num2)
        return -1;

    if (num1 > num2)
        return 1;

    return 0;
}

int main()
{
    scanf("%d", &n);
    if (n == 0) {
        printf("0\n");
        return 0;
    }
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    qsort(arr, n, sizeof(int), compare);

    if (n * 15 % 100 / 10 >= 5)
        cut = n * 15 / 100 + 1;
    else
        cut = n * 15 / 100;

    for (int i = cut; i < n - cut; i++)
        sum += arr[i];

    if((sum*10) / (n - 2 * cut) % 10 >= 5)
         printf("%d\n", sum / (n - 2 * cut) + 1);
    else
        printf("%d\n", sum / (n - 2 * cut));

    return 0;
}