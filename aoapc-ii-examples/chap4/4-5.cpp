// ERROR
#include <stdio.h>
#define INF 1000000000
void swap(int a, int b) {
    int t = a;
    a = b;
    b = t;
}
int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int a = 3, b = 4;
    swap(3, 4);
    printf("%d %d\n", a, b);
    return 0;
}