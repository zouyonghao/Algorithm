/*
 * [150] Evaluate Reverse Polish Notation
 *
 * https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/description/
 *
 * algorithms
 * Medium (37.25%)
 * Total Accepted:    1.1K
 * Total Submissions: 3K
 * Testcase Example:  '["2","1","+","3","*"]'
 *
 * 根据逆波兰表示法，求表达式的值。
 * 
 * 有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
 * 
 * 说明：
 * 
 * 
 * 整数除法只保留整数部分。
 * 给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
 * 
 * 
 * 示例 1：
 * 
 * 输入: ["2", "1", "+", "3", "*"]
 * 输出: 9
 * 解释: ((2 + 1) * 3) = 9
 * 
 * 
 * 示例 2：
 * 
 * 输入: ["4", "13", "5", "/", "+"]
 * 输出: 6
 * 解释: (4 + (13 / 5)) = 6
 * 
 * 
 * 示例 3：
 * 
 * 输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
 * 输出: 22
 * 解释: 
 * ⁠ ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 * 
 */

#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() < 1) return 0;
        stack<int> nums;
        for (int i = 0; i < tokens.size(); i++) {
            string current = tokens[i];
            switch(current[0]) {
                case '+': {
                    int num1 = nums.top();
                    nums.pop();
                    int num2 = nums.top();
                    nums.pop();
                    nums.push(num1 + num2);
                    break;
                }
                case '/': {
                    int num1 = nums.top();
                    nums.pop();
                    int num2 = nums.top();
                    nums.pop();
                    nums.push(num2 / num1);
                    break;
                }
                case '*': {
                    int num1 = nums.top();
                    nums.pop();
                    int num2 = nums.top();
                    nums.pop();
                    nums.push(num1 * num2);
                    break;
                }
                case '-': {
                    if (current.length() > 1) {
                        nums.push(atoi(current.c_str()));
                        break;
                    } else {
                        int num1 = nums.top();
                        nums.pop();
                        int num2 = nums.top();
                        nums.pop();
                        nums.push(num2 - num1);
                        break;
                    }
                }
                default: {
                    nums.push(atoi(current.c_str()));
                    break;
                }
            }
        }
        return nums.top();
    }
};
