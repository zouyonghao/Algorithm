#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string a;
    getline(std::cin, a);
    while (n-- > 0) {
        getline(std::cin, a);
        for (int i = 0; i < a.length(); i++) {
            if (a[i] == 'z') {
                a[i] = 'a';
            } else if (a[i] == 'Z') {
                a[i] = 'A';
            } else if (a[i] >= 'a' && a[i] <= 'y' ||
                       a[i] >= 'A' && a[i] <= 'Y') {
                a[i]++;
            }
        }
        cout << a << endl;
    }
}