#include <iostream>
using namespace std;

void insertSort(int * array, int n) {
    if (n < 2)
        return;
    for (int i = 1; i < n; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
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
    insertSort(array, n);
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}