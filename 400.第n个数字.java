/*
 * @lc app=leetcode.cn id=400 lang=java
 *
 * [400] 第N个数字
 *
 * https://leetcode-cn.com/problems/nth-digit/description/
 *
 * algorithms
 * Easy (30.17%)
 * Total Accepted:    2.1K
 * Total Submissions: 7.1K
 * Testcase Example:  '3'
 *
 * 在无限的整数序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...中找到第 n 个数字。
 * 
 * 注意:
 * n 是正数且在32为整形范围内 ( n < 231)。
 * 
 * 示例 1:
 * 
 * 
 * 输入:
 * 3
 * 
 * 输出:
 * 3
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入:
 * 11
 * 
 * 输出:
 * 0
 * 
 * 说明:
 * 第11个数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是0，它是10的一部分。
 * 
 * 
 */
class Solution {
    public int findNthDigit(int n) {
        long i = 1, j = 9;
        long realNum = 0;
        long h = i * j;
        while (h < n) {
            realNum += j;
            i++;
            j *= 10;
            h += i * j;
        }

        h -= i * j;

        // System.out.println(h);

        realNum += (double) (n - h) / i + 0.5;

        // System.out.println(realNum);

        return String.valueOf(realNum).charAt((int) ((n - h - 1) % i)) - '0';
    }
}
