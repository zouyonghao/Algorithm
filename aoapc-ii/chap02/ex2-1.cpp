#include <stdio.h>
#define INF 1000000000
int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    for (int i = 101; i < 999; i++) {
        int a = i / 100;
        int b = i / 10 % 10;
        int c = i % 10;
        if (i == a * a * a + b * b * b + c * c * c) {
            printf("%d\n", i);
        }
    }
    return 0;
}