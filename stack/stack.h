struct stack {
    char chars[100];
    int size = 0;
    void push(char c) { chars[size++] = c; }
    char pop() { return chars[--size]; }
    bool empty() { return size == 0; }
    char top() { return chars[size - 1]; }
};
