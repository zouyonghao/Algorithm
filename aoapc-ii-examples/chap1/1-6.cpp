#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    printf("%d%d%d\n", n%10, n / 10 % 10, n / 100);

    return 0;
}