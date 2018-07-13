// 串匹配蛮力算法的第二种写法
// 两种算法其实一样，只是写法区别

#include <stdio.h>
#include <string.h>

int match(char *T, char *S) {
    int n = strlen(T), i = 0;
    int m = strlen(S), j = 0;
    while (i < n - m + 1 && j < m) {
        if (T[i + j] == S[j]) {
            j++;
        } else {
            i++;
            j = 0;
        }
    }
    return i;
}

int main() {
    char * T = "Hello World";
    // char * S = "lo";
    char * S = "aaa";
    int result = match(T, S);
    if (result > (strlen(T) - strlen(S))) {
        printf("不匹配\n");
    } else {
        printf("%d\n", result);
    }
    return 0;
}