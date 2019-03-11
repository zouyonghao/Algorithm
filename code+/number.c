#include <stdio.h>

int fun(int i) {
    while (i > 0) {
        if (i % 10 < i / 10 % 10) {
            break;
        }
        i /= 10;
    }
    return i <= 0;
}
int main() {
    int n;
    scanf("%d", &n);
    int haveFunNumber = 0;
    for (int i = 10; i <= n; i++) {
        if (fun(i)) {
            printf("%d\n", i);
            haveFunNumber = 1;
        }
    }
    if (!haveFunNumber) {
        printf("%d", -1);
    }
    return 0;
}