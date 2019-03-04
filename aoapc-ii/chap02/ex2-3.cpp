#include <stdio.h>
#define INF 1000000000
int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = n; i > 0; i--)
    {
        for (int j = n - i; j > 0; j--) {
            printf(" ");
        }
        for (int j = 0; j < 2 * i - 1; j++) {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}