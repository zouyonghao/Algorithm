#include <iostream>
using namespace std;

// 0 1 1 2 3 5 8
int fib(int n) {
    int i = 0, j = 1;
    while (n -- > 2) {
        j = i + j;
        i = j - i;
    }
    return j;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}
