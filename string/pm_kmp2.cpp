// kmp 算法改进

#include <stdio.h>
#include <string.h>

int * buildNext(char * P) {
    int m = strlen(P), j = 0;
    int *N = new int[m];
    // t is N[j]
    int t = N[0] = -1;
    while (j < m - 1) {
        if (t < 0 || P[j] == P[t]) {
            j++; t++; N[j] = (P[j] != P[t]) ? t : N[t];
        } else {
            t = N[t];
        }
    }
    return N;
}

int kmp(char *T, char * S) {
    int n = strlen(T), i = 0;
    int m = strlen(S), j = 0;
    int *next = buildNext(S);
    while (j < m && i < n) {
        if (j < 0 || T[i] == S[j]) {
            i++; j++;
        } else {
            j = next[j];
        }
    }
    delete [] next;
    return i - j;
}

int main() {
    char *T = "LKALKNLNKASFNKAMAMAMMIAKNVLASN";
    char *S = "MAMAMMIA";
    int result = kmp(T, S);
    printf("%d\n", result);
    return 0;
}