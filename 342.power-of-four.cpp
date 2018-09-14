/*
 * [342] Power of Four
 *
 * https://leetcode-cn.com/problems/power-of-four/description/
 *
 * algorithms
 * Easy (41.77%)
 * Total Accepted:    2.3K
 * Total Submissions: 5.5K
 * Testcase Example:  '16'
 *
 * 给定一个整数 (32 位有符号整数)，请编写一个函数来判断它是否是 4 的幂次方。
 * 
 * 示例 1:
 * 
 * 输入: 16
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: 5
 * 输出: false
 * 
 * 进阶：
 * 你能不使用循环或者递归来完成本题吗？
 * 
 */
class Solution {
public:
    bool isPowerOfFour(int num) {
        // cout << (num & 0x55555555) << num << endl;
        // // 0
        // cout << (num & num - 1 == 0) << endl;
        // // 1
        // cout << ((num & num - 1) == 0) << endl;
        return ((num & num - 1) == 0) && (num & 0x55555555) && (num > 0);
    }
};
