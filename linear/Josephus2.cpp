// Josephus using array.
// https://practice.geeksforgeeks.org/problems/game-of-death-in-a-circle/0
#include <cstring>
#include <iostream>

using namespace std;
int main() {
    int cases, n, m;
    cin >> cases;
    while (cases-- > 0) {
        cin >> n >> m;
        int *array = new int[n];
        // memset(array, 0, sizeof array);
        int safePosi;
        for (int i = 0; i < n; i++) {
            array[i] = i + 1;
        }
        int j = 0;
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < m - 1; k++) {
                j = (++j) % n;
                if (array[j] < 0) {
                    k--;
                }
            }
            safePosi = array[j];
            // cout << array[j] << " ";
            array[j] = -1;
            int k = 0;
            while (array[j] < 0 && k++ < n) {
                j = (++j) % n;
            }
        }
        cout << safePosi << endl;
    }
    return 0;
}