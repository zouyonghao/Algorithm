/*
 * @lc app=leetcode.cn id=32 lang=java
 *
 * [32] 最长有效括号
 *
 * https://leetcode-cn.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (25.13%)
 * Total Accepted:    6.3K
 * Total Submissions: 25K
 * Testcase Example:  '"(()"'
 *
 * 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
 * 
 * 示例 1:
 * 
 * 输入: "(()"
 * 输出: 2
 * 解释: 最长有效括号子串为 "()"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ")()())"
 * 输出: 4
 * 解释: 最长有效括号子串为 "()()"
 * 
 * 
 */
// class Solution {
//     public int longestValidParentheses(String s) {
//         if (s.isEmpty())
//             return 0;
//         int leftCount = 0;
//         int max = 0;
//         int tempMax = 0;
//         int lastMax = 0;
//         boolean lastLegal = true;
//         for (int i = 0; i < s.length(); i++) {
//             if (s.charAt(i) == '(') {
//                 leftCount++;
//             } else {
//                 leftCount--;
//                 // ilegal
//                 if (leftCount < 0) {
//                     leftCount = 0;
//                     max = Math.max(tempMax, max);
//                     tempMax = 0;
//                 } else {
//                     tempMax++;
//                     if (leftCount == 0) {
//                         if (lastLegal) {
//                             lastMax = lastMax + tempMax;
//                         } else {
//                             lastMax = Math.max(tempMax, lastMax);
//                             lastLegal = true;
//                         }
//                     }
//                 }
//             }
//         }
//         if (leftCount == 0)
//             max = Math.max(max, tempMax);
//         else {
//             max = Math.max(max, lastMax);
//         }
//         return max * 2;
//     }
// }
class Solution {
    public int longestValidParentheses(String s) {
        int n = s.length(), maxLen = 0;
        // vector<int> dp(n+1,0);
        int[] dp = new int[n + 1];
        for (int i = 0; i < n + 1; i++) {
            dp[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            int j = i - 2 - dp[i - 1];
            if (s.charAt(i - 1) == '(' || j < 0 || s.charAt(j) == ')')
                dp[i] = 0;
            else {
                dp[i] = dp[i - 1] + 2 + dp[j];
                maxLen = Math.max(maxLen, dp[i]);
            }
        }
        return maxLen;
    }
};
