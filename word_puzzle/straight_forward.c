#include <stdio.h>
#include <stdlib.h>

int is_match(char* a, int a_size, char* b, int b_size) {
    if (a_size != b_size) {
        return 0;
    }
    for (int i = 0; i < a_size; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

char FAT[] = {'f', 'a', 't'};

int main() {
    int n, m;
    if (scanf("%d", &n) && scanf("%d", &m)) {
        char *array = (char *) malloc(sizeof(char) * m * n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!scanf("%c", &array[i * n + j])) {
                    exit(0);
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // row
                int start = i * n + j;
                int end = i * n + n;
                for (int k = start; k < end; k++) {
                    if (is_match(FAT, 3, array + start + k, k - start)) {
                        printf("row has a match");
                    }
                }
                
                // column
                for (int k = i; k < m; k++) {
                    char* column_word = (char *)malloc(sizeof(char) * (m - k));
                    for (int l = 0; l < m - k; l++) {
                        column_word[l] = array[k * n + j];
                    }
                    if (is_match(FAT, 3, column_word, m - k)) {
                        printf("column has a match");
                    }
                }
                
                // orientation right down
                
                // orientation right up
                
                // orientation left down
                
                // orientation left up
                
            }
        }
    }
}