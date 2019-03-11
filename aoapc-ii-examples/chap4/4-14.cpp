// sample 4-4 p83
#include <stdio.h>
#include <string.h>
#define INF 1000000000
int readchar() {
    for(;;) {
        int ch = getchar();
        if (ch != '\n' && ch != '\r') {
            return ch;
        }
    }
}
int readint(int c) {
    int v = 0;
    while (c--) {
        v = v * 2 + readchar() - '0';
    }
    return v;
}
int code[8][1 << 8];
int readcodes() {
    memset(code, 0, sizeof(code));
    code[1][0] = readchar();
    for (int len = 2; len <= 7; len++) {
        for (int i = 0; i < (1 << len) - 1; i++) {
            int ch = getchar();
            if (ch == EOF) return 0;
            if (ch == '\n' || ch == '\r') return 1;
            code[len][i] = ch;
        }
    }
    return 1;
}

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    while(readcodes()) {
        for(;;) {
            int len = readint(3);
            if (len == 0) break;
            for (;;) {
                int v = readint(len);
                if (v == (1 << len) - 1) break;
                putchar(code[len][v]);
            }
        }
        putchar('\n');
    }
    return 0;
}