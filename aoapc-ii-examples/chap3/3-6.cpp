#include <stdio.h>
#define INF 1000000000
char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int i, c;
    while ((c = getchar()) != EOF) {
        for (i = 1; s[i] && s[i] != c; i++);
        if (s[i]) {
            putchar(s[i - 1]);
        } else {
            putchar(c);
        }
    }
    return 0;
}