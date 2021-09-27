#include <stdio.h>

int ang[100010], tree[300000][4] = { 0 };
int n, m, a, b, min, max, x = 1;

int fmin(int a, int b) { return a > b ? b : a; }
int fmax(int a, int b) { return a > b ? a : b; }

void init(int t) {
    int start = tree[t][0], end = tree[t][1];
    if (start == end) {
        tree[t][2] = ang[start];
        tree[t][3] = ang[start];
        return;
    }

    tree[t * 2][0] = start;
    tree[t * 2][1] = (start + end) / 2;
    tree[t * 2 + 1][0] = (start + end) / 2 + 1;
    tree[t * 2 + 1][1] = end;

    init(t * 2);
    init(t * 2 + 1);
    
    tree[t][2] = fmin(tree[t * 2][2], tree[t * 2 + 1][2]);
    tree[t][3] = fmax(tree[t * 2][3], tree[t * 2 + 1][3]);
}

void fun(int t, int start, int end) {
    if (start > tree[t][1] || end < tree[t][0])
        return;
    if (start <= tree[t][0] && tree[t][1] <= end) {
        if (tree[t][2] < min)
            min = tree[t][2];
        if (tree[t][3] > max)
            max = tree[t][3];
        return;
    }
    fun(t * 2, start, end);
    fun(t * 2 + 1, start, end);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &ang[i]);
    tree[1][0] = 1, tree[1][1] = n;
    init(1);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        min = 1987654321, max = -1;
        fun(1, a, b);
        printf("%d %d\n", min, max);
    }
    return 0;
}