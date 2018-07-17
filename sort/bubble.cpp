#include <iostream>
using namespace std;

void bubble(int * array, int n) {
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j <= i; j++) {
            if (array[j - 1] > array[j]) {
                swap(array[j - 1], array[j]);
            }
        }
    }
}

int main() {
    int * array = new int[7]{10, 4, 62345, 12, 65, 3, 89};
    bubble(array, 7);
    for (int i = 0; i < 7; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}