#include <stdio.h>
#define INF 1000000000
int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int a, b, c;
    int kase = 0;
    while (scanf("%d%d%d", &a, &b, &c) == 3) {
        int i = 10;
        printf("Case %d: ", ++kase);
        for (; i <= 100; i++) {
            if (i % 3 == a && i % 5 == b && i % 7 == c) {
                printf("%d\n", i);
                break;
            }
        }
        if (i > 100) {
            printf("No answer\n");
        }
    }
    return 0;
}