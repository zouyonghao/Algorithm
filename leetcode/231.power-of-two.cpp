/*
 * [231] Power of Two
 *
 * https://leetcode-cn.com/problems/power-of-two/description/
 *
 * algorithms
 * Easy (41.36%)
 * Total Accepted:    3.3K
 * Total Submissions: 8K
 * Testcase Example:  '1'
 *
 * 给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: true
 * 解释: 20 = 1
 * 
 * 示例 2:
 * 
 * 输入: 16
 * 输出: true
 * 解释: 24 = 16
 * 
 * 示例 3:
 * 
 * 输入: 218
 * 输出: false
 * 
 */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 1) return false;
        while (n > 0) {
            if (n % 2 == 0) {
                n /= 2;
            } else {
                if (n == 1) 
                    return true;
                return false;
            }
        }
    }
};
