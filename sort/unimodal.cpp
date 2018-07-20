// an unimodal array should be like 1, 2, 3, 4, 5, 4, 3, 2, 1

#include <iostream>
using namespace std;

int unimodal(int *array, int left, int right) {
    while (left < right) {
        int mid = (left + right) / 2;
        if (array[mid] < array[mid + 1]) {
            left = mid + 1;
        }
        if (array[mid] > array[mid + 1]) {
            right = mid;
        }
    }
    return array[left];
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 4, 3, 1};
    cout << unimodal(array, 0, 8) << endl;
    return 0;
}