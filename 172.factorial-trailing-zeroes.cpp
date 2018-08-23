/*
 * [172] Factorial Trailing Zeroes
 *
 * https://leetcode-cn.com/problems/factorial-trailing-zeroes/description/
 *
 * algorithms
 * Easy (34.95%)
 * Total Accepted:    2.6K
 * Total Submissions: 7.5K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，返回 n! 结果尾数中零的数量。
 * 
 * 示例 1:
 * 
 * 输入: 3
 * 输出: 0
 * 解释: 3! = 6, 尾数中没有零。
 * 
 * 示例 2:
 * 
 * 输入: 5
 * 输出: 1
 * 解释: 5! = 120, 尾数中有 1 个零.
 * 
 * 说明: 你算法的时间复杂度应为 O(log n) 。
 * 
 */
class Solution {
public:
    int trailingZeroes(int n) {
        if (n < 5) return 0;
        int result = 0;
        while (n >= 5) {
            result += n / 5;
            n /= 5;
        }
        return result;
    }
};
