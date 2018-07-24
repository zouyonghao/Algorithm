#include <cstring>
#include <iostream>
using namespace std;

struct stack {
    char chars[100];
    int size = 0;
    void push(char c) { chars[size++] = c; }
    char pop() { return chars[--size]; }
    bool empty() { return size == 0; }
    char top() { return chars[size - 1]; }
};

// 括号匹配
int main() {
    char *t = "((()()))";
    stack s;
    bool wrong = false;
    for (int i = 0; i < strlen(t); i++) {
        if (t[i] == '(') {
            s.push(t[i]);
        } else {
            if (s.empty() || s.top() != '(') {
                cout << "wrong pattern" << endl;
                wrong = true;
                break;
            } else {
                s.pop();
            }
        }
    }
    if (!wrong) {
        cout << "pass" << endl;
    }

    return 0;
}