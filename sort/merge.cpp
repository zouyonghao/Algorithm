#include <iostream>
using namespace std;

void merge(int * array, int left, int m, int right) {
    int leftLength = m - left;
    int rightLength = right - m;
    int *tmpLeft = new int[leftLength];
    int *tmpRight = new int[rightLength];
    for (int i = 0; i < leftLength; i++) {
        tmpLeft[i] = array[left + i];
    }
    for (int i = 0; i < rightLength; i++) {
        tmpRight[i] = array[m + i];
    }
    int o = left;
    int i = 0, j = 0;
    while (i < leftLength && j < rightLength) {
        if (tmpLeft[i] <= tmpRight[j]) {
            array[o] = tmpLeft[i];
            i++;
        } else {
            array[o] = tmpRight[j];
            j++;
        }
        o++;
    }
    while (i < leftLength) {
        array[o++] = tmpLeft[i++];
    }
    while (j < rightLength) {
        array[o++] = tmpRight[j++];
    }
    delete [] tmpRight;
    delete [] tmpLeft;
}

void mergeSort(int *array, int left, int right) {
    if (right - left < 2)
        return;
    int m = (left + right) >> 1;
    mergeSort(array, left, m);  // [left, m)
    mergeSort(array, m, right); // [m, right)
    if (array[m - 1] > array[m])
        merge(array, left, m, right);
}

int main() {
    int n;
    cin >> n;
    int *array = new int[n];
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        array[i] = m;
    }
    mergeSort(array, 0, n);

    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    return 0;
}