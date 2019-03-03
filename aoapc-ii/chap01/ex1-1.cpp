#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b, c;
    double average;
    scanf("%d%d%d", &a, &b, &c);
    average = (a + b + c) / 3.0;
    printf("%.3f", average);
    return 0;
}
