#include <stdio.h>
#define INF 1000000000
int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    double i;
    // for (i = 0; i != 10; i += 0.1)
    for (i = 0; i < 10; i += 0.1)
        printf("%.1f\n", i);
#ifdef LOCAL
    fflush(stdout);
#endif
    return 0;
}