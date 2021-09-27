#include <stdio.h>

long long int c, ang[1000001],sum[1000001], tree[3000000][3] = { 0 }, start, end;
int a, b, n, m, k, x = 1, left, right;

void change(int b, long long int c) {
    long long int gap = c - ang[b];
    int t = 1;
    ang[b] = c;
    while (tree[t][1] != b || tree[t][2] != b) {
        tree[t][0] += gap;
        if (b > (tree[t][1] + tree[t][2]) / 2)
            t = t * 2 + 1;
        else
            t *= 2;
    }
    tree[t][0] += gap;
}

long long int print(int t, int b, int c) {
    if (b > tree[t][2] || c < tree[t][1])
        return 0;
    if (b <= tree[t][1] && c >= tree[t][2])
        return tree[t][0];
    return print(t * 2, b, c) + print(t * 2 + 1, b, c);
}

int main()
{
    sum[0] = 0;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &ang[i]);
        sum[i] = sum[i - 1] + ang[i];
    }
    // segment tree
    tree[1][0] = sum[n];
    tree[1][1] = 1;
    tree[1][2] = n;
    while (1) {
        if (tree[x][1] == 0)
            break;

        start = tree[x][1];
        end = tree[x][2];
        if (start < end) {
            tree[2 * x][1] = start;
            tree[2 * x][2] = (start + end) / 2;
            tree[2 * x + 1][1] = (start + end) / 2 + 1;
            tree[2 * x + 1][2] = end;

            tree[2 * x][0] = sum[tree[2 * x][2]] - sum[tree[2 * x][1] - 1];
            tree[2 * x + 1][0] = sum[tree[2 * x + 1][2]] - sum[tree[2 * x + 1][1] - 1];
        }
        x++;
    }
    for (int i = 0; i < m + k; i++) {
        scanf("%d %d %lld", &a, &b, &c);
        if (a == 1)
            change(b, c);
        else if(a == 2)
            printf("%lld\n", print(1, b, (int)c));
    }

    return 0;
}