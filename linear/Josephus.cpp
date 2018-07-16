// Josephus using array.
#include <iostream>
#include <cstring>

using namespace std;
int main() {
    int n, s, m;
    cin >> n >> s >> m;
    int * array = new int[n];
    // memset(array, 0, sizeof array);
    for (int i = 0; i < n; i++) {
        array[i] = i + 1;
    }
    int j = s;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m - 1; k++) {
            j  = (++j) % n;
            if (array[j] < 0) {
                k--;
            }
        }
        cout << array[j] << " ";
        array[j] = -1;
        int k = 0;
        while (array[j] < 0 && k++ < n) {
            j = (++j) % n;
        }
    }
    return 0;
}