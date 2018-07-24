#include <iostream>
using namespace std;

struct stack {
    char chars[100];
    int size = 0;
    void push(char c) { chars[size++] = c; }

    char pop() { return chars[--size]; }
};

// 进制转换
void convert(int num, int base) {
    static char nums[] = {'0', '1', '2', '3', '4', '5', '6', '7',
                          '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    stack s;
    while (num > 0) {
        s.push(nums[num % base]);
        num = num / base;
    }
    while (s.size > 0) {
        cout << s.pop();
    }
    cout << endl;
}

int main() {
    convert(100, 16);
    return 0;
}