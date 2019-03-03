#include <stdio.h>

int main(int argc, char const *argv[])
{
    double f, c;
    scanf("%lf", &f);
    c = 5 * (f - 32) / 9.0;
    printf("%.3lf", c);
    return 0;
}
