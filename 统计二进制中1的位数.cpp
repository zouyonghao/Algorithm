/*
 * 一个数一定可以表示为
 * xxx10000 前面xxx任意数，但是某一位开始，1后面全为0，当然0的数量可能是0
 * 此数减1后即为
 * xxx01111
 * 因此 n & (n - 1) 即为把数的最后一位1清零。
 * 时间复杂度为 O(数中1的个数)
 */
#include "stdio.h"

int main() {
    int n;
    scanf("%d", &n);
    int count = 0;
    while (n > 0) {
        count++;
        n &= n - 1;
    }
    printf("the number of one in n is: %d\n", count);
    return 0;
}