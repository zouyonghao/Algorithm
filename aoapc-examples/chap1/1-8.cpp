#include <stdio.h>

int main(int argc, char const *argv[]) {
    int a, b, t;
    scanf("%d%d", &a, &b);
    t = a;
    a = b;
    b = t;
    printf("%d %d", a, b);
    return 0;
}
