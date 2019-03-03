#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    const double PI = acos(-1.0);
    int n;
    scanf("%d", &n);
    printf("%lf %lf", sin(n * PI / 180.0), cos(n  * PI / 180.0));
    return 0;
}
