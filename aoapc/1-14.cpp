#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b, c, t;
    scanf("%d%d%d", &a, &b, &c);
    if (a > b) {
        t = a;
        a = b;
        b = t;
    } // now a <= b
    if (a > c) {
        t = a;
        a = c;
        c = t;
    } // now a <= c
    if (b > c) {
        t = b;
        b = c;
        c = t;
    } // a <= b <= c
    printf("%d %d %d", a, b, c);

    return 0;
}
