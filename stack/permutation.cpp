#include <iostream>
#include "stack.h"
using namespace std;

// 甄别一个序列是否是一个合法的出栈次序
bool stackPermutation(int * array, int n) {
    stack s;
    int i = 1;
    for (int k = 0; k < n; k++) {
        while (s.empty() || array[k] != s.top()) {
            if (array[k] < int(s.top())) {
                return false;
            }
            s.push(i++);
        }
        s.pop();
    }
    return true;
}

int main() {
    int array[]{3, 4, 2, 1};
    cout << stackPermutation(array, 4) << endl;
    return 0;
}


