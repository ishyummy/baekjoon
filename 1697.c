#include <stdio.h>

int visit[300000] = { 0 };
int q[300000];
int q_head = 0, q_tail = -1, start, end;

int main()
{
    int n, k, count = 0, x;
    scanf("%d %d", &n, &k);

    q[++q_tail] = n;
    start = q_head, end = q_tail;

    while (q_head <= q_tail) {
        if (q_head > end) {
            start = q_head, end = q_tail;
            count++;
        }
        x = q[q_head++];
        if (x == k)
            break;
        if (x < 0)
            continue;
        if (visit[x] == 1)
            continue;
        visit[x] = 1;
        if (x * 2 <= 100000)
            q[++q_tail] = x * 2;
        if (x + 1 <= 100000)
            q[++q_tail] = x + 1;
        if (x > 0)
            q[++q_tail] = x - 1;
    }

    printf("%d\n", count);
    return 0;
}
