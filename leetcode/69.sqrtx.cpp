/*
 * [69] Sqrt(x)
 *
 * https://leetcode-cn.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (31.14%)
 * Total Accepted:    6.1K
 * Total Submissions: 19.6K
 * Testcase Example:  '4'
 *
 * 实现 int sqrt(int x) 函数。
 * 
 * 计算并返回 x 的平方根，其中 x 是非负整数。
 * 
 * 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
 * 
 * 示例 1:
 * 
 * 输入: 4
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: 8
 * 输出: 2
 * 说明: 8 的平方根是 2.82842..., 
 * 由于返回类型是整数，小数部分将被舍去。
 * 
 * 
 */
class Solution {
public:
    int mySqrt(int x) {
        double guess = 1.0;
        while (x - guess * guess > 0.01 || guess * guess - x > 0.01) {
            // cout << guess << endl;
            guess = (guess + double(x) / guess) / 2.0;
        }
        return guess;
    }
};
