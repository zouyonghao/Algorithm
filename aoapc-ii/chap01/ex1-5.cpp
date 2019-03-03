#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    if (n <= 3) {
        printf("%.2f", 95.0 * n);
    } else {
        printf("%.2f", 95.0 * 0.85 * n);
    }
    return 0;
}
