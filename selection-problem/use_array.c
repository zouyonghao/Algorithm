#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    if (scanf("%d", &n) && scanf("%d", &k)) {
        int *array = (int *)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) {
            if (!scanf("%d", &array[i])) {
                exit(0);
            }
        }
        
        int *k_array = (int *)malloc(sizeof(int) * k);
        for (int i = 0; i < k; i++) {
            k_array[i] = 0;
        }
        
        for (int i = 0; i < n; i++) {
            int a = array[i];
            for (int j = 0; j < k; j++) {
                if (k_array[j] < a) {
                    for (int h = k-1; h > j; h--) {
                        k_array[h] = k_array[h-1];
                    }
                    k_array[j] = a;
                    break;
                }
            }
        }
        
        printf("%d", k_array[k-1]);
    }
}