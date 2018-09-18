/*
 * [371] Sum of Two Integers
 *
 * https://leetcode-cn.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Easy (54.72%)
 * Total Accepted:    3.5K
 * Total Submissions: 6.4K
 * Testcase Example:  '1\n2'
 *
 * 不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和。
 * 
 * 示例 1:
 * 
 * 输入: a = 1, b = 2
 * 输出: 3
 * 
 * 
 * 示例 2:
 * 
 * 输入: a = -2, b = 3
 * 输出: 1
 * 
 */
class Solution {
public:
    int getSum(int a, int b) {
        int sum = a ^ b;
        int carry = (a & b) << 1;
        if (carry != 0) {
            return getSum(sum, carry);
        }
        return sum;
    }
};
