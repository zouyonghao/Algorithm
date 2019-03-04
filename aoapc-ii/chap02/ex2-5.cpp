#include <stdio.h>
#include <math.h>
#define INF 1000000000
int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int a, b, c;
    int kase = 0;
    while (scanf("%d%d%d", &a, &b, &c) == 3 && (a || b || c))
    {
        double r = (double) a / b;
        int left_part = (int) r;
        double d_right_part = r - left_part;
        int right_part = (int) (d_right_part * pow(10.0, (double) c));
        printf("Case %d: %d.%d\n", ++kase, left_part, right_part);
    }
#ifdef LOCAL
    fflush(stdout);
#endif
    return 0;
}