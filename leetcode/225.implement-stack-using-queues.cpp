/*
 * [225] Implement Stack using Queues
 *
 * https://leetcode-cn.com/problems/implement-stack-using-queues/description/
 *
 * algorithms
 * Easy (46.97%)
 * Total Accepted:    1.7K
 * Total Submissions: 3.5K
 * Testcase Example:  '["MyStack","push","push","top","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * 使用队列实现栈的下列操作：
 * 
 * 
 * push(x) -- 元素 x 入栈
 * pop() -- 移除栈顶元素
 * top() -- 获取栈顶元素
 * empty() -- 返回栈是否为空
 * 
 * 
 * 注意:
 * 
 * 
 * 你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty
 * 这些操作是合法的。
 * 你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
 * 你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。
 * 
 * 
 */
#include <vector>
using namespace std;
class MyStack {
public:
    /** Initialize your data structure here. */
    vector<int> list;
    int size;
    MyStack() {
        size = 0;
        list.resize(8);
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if (list.capacity() <= size) {
            list.resize(list.capacity() * 2);
        }
        list[size++] = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (size > 0) {
            return list[--size];
        }
        return -1;
    }
    
    /** Get the top element. */
    int top() {
        return list[size - 1];
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return size == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
