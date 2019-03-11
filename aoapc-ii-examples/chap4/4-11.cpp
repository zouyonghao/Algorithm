#include <stdio.h>
#include <string.h>
#define maxn 100
#define INF 1000000000
int left, chance;
char s[maxn], s2[maxn];
int win, lose;

void guess(char ch) {

    // in 4-12.cpp
}
int main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int rnd;
    while ((scanf("%d%s%s", &rnd, s, s2)) == 3 && rnd != -1) {
        printf("Round %d\n", rnd);
        win = lose = 0;
        left = strlen(s);
        chance = 7;
        for (int i = 0; i < strlen(s2); i++) {
            guess(s2[i]);
            if (win | lose)
                break;
        }

        if (win)
            printf("You win.\n");
        else if (lose)
            printf("You lose.\n");
        else
            printf("You chickend out.\n");
    }

    return 0;
}
