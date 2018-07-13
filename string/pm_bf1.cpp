// 串匹配的第一种蛮力算法
#include <stdio.h>
#include <string.h>

int match(char *T, char *S) {
    int n = strlen(T), i = 0;
    int m = strlen(S), j = 0;
    while (i < n - m + 1 && j < m) {
        if (T[i] == S[j]) {
            i++;
            j++;
        } else {
            i = (i - j) + 1;
            j = 0;
        }
    }
    return i - j;
}

// int main() {
//     char *T = "Hello World!";
//     char *S = "lo";
//     int result = match(T, S);
//     if (result > (strlen(T) - strlen(S))) {
//         printf("不匹配\n");
//     } else
//         printf("%d\n", result);
//     return 0;
// }