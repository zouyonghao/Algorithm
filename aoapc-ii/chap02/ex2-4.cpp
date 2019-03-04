#include <stdio.h>
#define INF 1000000000
int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int m, n;
    int kase = 0;
    while (scanf("%d%d", &n, &m) == 2 && (m || n))
    {
        double sum = 0;
        for (long i = n; i <= m; i++)
        {
            // sum += 1.0f / (double)(i * i);  // i * i overflow
            sum += 1.0 / i / i;
        }
        printf("Case %d: %.5f\n", ++kase, sum);
    }

    return 0;
}