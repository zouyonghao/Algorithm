// ex 2.3-4 in CLRS
#include <iostream>

void insertSort(int *array, int n) {
    if (n < 2)
        return;
    insertSort(array, n - 1);
    int key = array[n - 1];
    int j;
    for (j = n - 2; j >= 0; j--) {
        if (array[j] > key)
            array[j + 1] = array[j];
        else
            break;
    }
    array[j + 1] = key;
}

int main() {
    int array[]{3, 6, 9, 1, 0};
    insertSort(array, 5);
    for (int i = 0; i < 5; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}