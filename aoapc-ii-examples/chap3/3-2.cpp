#include <stdio.h>
#include <string.h>
#define maxn 1010
int a[maxn];
#define INF 1000000000
int main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int n, k, first = 1;
    memset(a, 0, sizeof(a));
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            if (j % i == 0)
                a[j] = !a[j];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i]) {
            if (first) {
                first = 0;
            } else {
                printf(" ");
            }
            printf("%d", i);
        }
    }
    return 0;
}