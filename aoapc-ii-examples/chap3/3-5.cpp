#include <stdio.h>
#define INF 1000000000
int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int c, q = 1;
    while ((c = getchar()) != EOF) {
        if (c == '"') {
            printf("%s", q ? "``" : "''");
            q = !q;
        } else {
            printf("%c", c);
        }
    }
    return 0;
}