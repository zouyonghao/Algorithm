/*
 * [367] Valid Perfect Square
 *
 * https://leetcode-cn.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (37.33%)
 * Total Accepted:    2.6K
 * Total Submissions: 7.1K
 * Testcase Example:  '16'
 *
 * 给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。
 * 
 * 说明：不要使用任何内置的库函数，如  sqrt。
 * 
 * 示例 1：
 * 
 * 输入：16
 * 输出：True
 * 
 * 示例 2：
 * 
 * 输入：14
 * 输出：False
 * 
 * 
 */
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0) return false;
        double tmp = 1.0;
        double n = num;
        while (tmp * tmp - n > 1e-6 || n - tmp * tmp > 1e-6) {
            tmp = (tmp + n / tmp) / 2.0;
        }
        // cout << tmp << endl;
        return tmp - (int) tmp < 1e-3;
    }
};
