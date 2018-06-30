#include "stdio.h"
#define POW(c) (1 << (c))
#define MASK(c) (((unsigned long ) -1) / (POW(POW(c)) + 1))
#define ROUND(n, c) (((n) & MASK(c)) + ((n) >> POW(c) & MASK(c)))

int main() {
    int n;
    scanf("%d", &n);
    n = ROUND(n, 0);
    n = ROUND(n, 1);
    n = ROUND(n, 2);
    n = ROUND(n, 3);
    n = ROUND(n, 4);
    printf("%d\n", n);
    return 0;
}