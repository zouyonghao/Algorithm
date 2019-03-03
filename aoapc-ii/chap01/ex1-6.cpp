#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a + b > c && a + c > b && b + c > a)
    {
        if (a *a + b *b == c *c ||
                          b *b + c *c == a *a ||
                                        a *a + c *c == b * b)
            printf("yes");
        else
            printf("no");
    }
    else
    {
        printf("not a triangle");
    }
    return 0;
}
