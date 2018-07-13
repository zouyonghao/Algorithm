// kmp 的传统实现
// 要好好理解！！

#include <stdio.h>
#include <string.h>

int *buildnext(char *P) {
    int m = strlen(P), j = 0;
    int *N = new int[m];
    int t = N[0] = -1;
    while(j < m) {
        if (t < 0 || P[j] == P[t]) {
            N[++j] = ++t;
        } else {
            t = N[t];
        }
    }
    return N;
}

int kmp(char *T, char *S) {
    int *next = buildnext(S);
    int n = strlen(T), i = 0;
    int m = strlen(S), j = 0;
    while (i < n && j < m) {
        if (j < 0 || T[i] == S[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    delete [] next;
    return i - j;
}

// int main() {
//     char *T = "ALKSFLKNVLANSKD MAMAMMIA ALKSJDLKJCLAN";
//     char *S = "MAMAMMIA";
//     int result = kmp(T, S);
//     printf("%d\n", result);
//     return 0;
// }