#include <stdio.h>
#define INF 1000000000
int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int a[] = {123,
               132,
               213,
               231,
               312,
               321};
    for (int i = 0; i < 6; i++)
    {
        printf("%d %d %d\n", a[i], a[i] * 2, a[i] * 3);
    }
#ifdef LOCAL
    fflush(stdout);
#endif
    return 0;
}