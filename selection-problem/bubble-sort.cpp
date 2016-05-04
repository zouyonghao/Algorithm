#include<iostream>

using namespace std;

void bubble_sort(unsigned int *a, int size) {
    if (size <= 1) {
        return;
    }
    for (int i = 0; i < size - 1; i++) {
        if (a[i] > a[i+1]) {
            unsigned int temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
        }
    }
    bubble_sort(a, size - 1);
}

int main() {
    int n;
    cin>>n;
    unsigned int *array = new unsigned int[n];
    for (int i = 0; i < n; i++) {
        cin>>array[i];
    }
    int k;
    cin>>k;
    // for (int i = 0; i < n; i++) {
    //     cout<<array[i] << " ";
    // }
    // cout << endl;
    bubble_sort(array, n);
    // for (int i = 0; i < n; i++) {
    //     cout<<array[i]<<" ";
    // }
    // cout << endl;
    cout << "the k-th number is:" << array[k-1] << endl;
}