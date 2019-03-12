#include <algorithm>
#include <cstdio>
using namespace std;

const int maxn = 10000;

int main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int n, q, x, a[maxn], kase = 0;
    while (scanf("%d%d", &n, &q) == 2 && n) {
        printf("CASE# %d:\n", ++kase);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        while (q--) {
            scanf("%d", &x);
            int p = lower_bound(a, a + n, x) - a;
            // printf("lower_bound test %d\n", lower_bound(a, a + n, x));
            if (a[p] == x)
                printf("%d found at %d\n", x, p + 1);
            else
                printf("%d not found\n", x);
        }
    }
}