#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a = 0, b = 0, c = 1;
    printf("%d %d %d", a && b || c, (a && b) || c, a && (b || c));
    return 0;
}
