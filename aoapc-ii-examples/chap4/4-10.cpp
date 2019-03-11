#include <stdio.h>
#define INF 1000000000
int f(int n) {
    return n == 0 ? 1 : f(n - 1) * n;
}

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    printf("%d\n", f(3));
    // segment fault
    // printf("%d\n", f(100000000));
    return 0;
}