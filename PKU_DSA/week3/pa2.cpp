#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void countStack(int n, int &result) {
    vector<int> original;
    stack<int> s;
    for (int i = 0; i < n; i++) {
        original.push_back(i);
        
    }
}

int main() {
    int n;
    cin >> n;
    int result = 0;
    countStack(n, result);
    cout << result;
    return 0;
}