/*
 * [155] Min Stack
 *
 * https://leetcode-cn.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (43.96%)
 * Total Accepted:    4K
 * Total Submissions: 9K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
 * 
 * 
 * push(x) -- 将元素 x 推入栈中。
 * pop() -- 删除栈顶的元素。
 * top() -- 获取栈顶元素。
 * getMin() -- 检索栈中的最小元素。
 * 
 * 
 * 示例:
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> 返回 -3.
 * minStack.pop();
 * minStack.top();      --> 返回 0.
 * minStack.getMin();   --> 返回 -2.
 * 
 * 
 */
class MinStack {
public:
    /** initialize your data structure here. */
    long min;
    int size;
    int* array;
    int capacity;
    MinStack() {
        capacity = 8;
        min = INT_MAX;
        size = 0;
        array = new int[capacity];
    }
    
    void push(int x) {
        if (size == capacity) {
            int* tmp = new int[2 * capacity];
            capacity *= 2;
            for (int i = 0; i < size; i++) {
                tmp[i] = array[i];
            }
            delete [] array;
            array = tmp;
        }
        array[size++] = x;
        if (min > x) {
            min = x;
        }
    }
    
    void pop() {
        if (size < 1) return;
        size--;
        if (size == 0) {
            min = INT_MAX;
        } else {
            min = array[0];
            for (int i = 1; i < size; i++) {
                if (array[i] < min) {
                    min = array[i];
                }
            }
        }
    }
    
    int top() {
        return array[size - 1];
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
