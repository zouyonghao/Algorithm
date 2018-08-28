/*
 * [190] Reverse Bits
 *
 * https://leetcode-cn.com/problems/reverse-bits/description/
 *
 * algorithms
 * Easy (29.74%)
 * Total Accepted:    3.6K
 * Total Submissions: 12.2K
 * Testcase Example:  '    43261596 (00000010100101000001111010011100)'
 *
 * 颠倒给定的 32 位无符号整数的二进制位。
 * 
 * 示例:
 * 
 * 输入: 43261596
 * 输出: 964176192
 * 解释: 43261596 的二进制表示形式为 00000010100101000001111010011100 ，
 * 返回 964176192，其二进制表示形式为 00111001011110000010100101000000 。
 * 
 * 进阶:
 * 如果多次调用这个函数，你将如何优化你的算法？
 * 
 */
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; i++) {
            result += (((n >> i) & 1) << (31 - i));
        }
        return result;
    }
};
