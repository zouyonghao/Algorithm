#include <stdio.h>

int main(int argc, char const *argv[]) {
    int n, m;
    scanf("%d", &n);
    m = (n % 10) * 100 + (n / 10 % 10) * 10 + n / 100;
    // printf("%03d\n", m); // if 250 print 052
    printf("%d", m); // 52
    return 0;
}