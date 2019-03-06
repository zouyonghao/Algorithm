/*
 * @lc app=leetcode.cn id=44 lang=java
 *
 * [44] 通配符匹配
 *
 * https://leetcode-cn.com/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (20.52%)
 * Total Accepted:    3.5K
 * Total Submissions: 17.1K
 * Testcase Example:  '"aa"\n"a"'
 *
 * 给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
 * 
 * '?' 可以匹配任何单个字符。
 * '*' 可以匹配任意字符串（包括空字符串）。
 * 
 * 
 * 两个字符串完全匹配才算匹配成功。
 * 
 * 说明:
 * 
 * 
 * s 可能为空，且只包含从 a-z 的小写字母。
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * s = "aa"
 * p = "a"
 * 输出: false
 * 解释: "a" 无法匹配 "aa" 整个字符串。
 * 
 * 示例 2:
 * 
 * 输入:
 * s = "aa"
 * p = "*"
 * 输出: true
 * 解释: '*' 可以匹配任意字符串。
 * 
 * 
 * 示例 3:
 * 
 * 输入:
 * s = "cb"
 * p = "?a"
 * 输出: false
 * 解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
 * 
 * 
 * 示例 4:
 * 
 * 输入:
 * s = "adceb"
 * p = "*a*b"
 * 输出: true
 * 解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
 * 
 * 
 * 示例 5:
 * 
 * 输入:
 * s = "acdcb"
 * p = "a*c?b"
 * 输入: false
 * 
 */
class Solution {
    // public boolean isMatch(String s, String p) {
    // if (s == p) {
    // return true;
    // }
    // if (s.isEmpty()) {
    // while (!p.isEmpty() && p.charAt(0) == '*')
    // p = p.substring(1);
    // return p.isEmpty();
    // }
    // if (p.isEmpty()) {
    // return s.isEmpty();
    // }
    // boolean firstMatch = s.charAt(0) == p.charAt(0) || p.charAt(0) == '?';
    // if (p.charAt(0) == '*') {
    // return isMatch(s.substring(1), p) || isMatch(s.substring(1), p.substring(1))
    // || isMatch(s, p.substring(1));
    // } else {
    // return firstMatch && isMatch(s.substring(1), p.substring(1));
    // }
    // }
    public boolean isMatch(String s, String p) {
        if (s == p) {
            return true;
        }
        if (s.isEmpty()) {
            while (!p.isEmpty() && p.charAt(0) == '*')
                p = p.substring(1);
            return p.isEmpty();
        }
        if (p.isEmpty()) {
            return s.isEmpty();
        }
        boolean[][] dp = new boolean[p.length()][s.length()];
        // init first row
        for (int i = 0; i < s.length(); i++) {
            if (p.charAt(0) == '*') {
                dp[0][i] = true;
            } else {
                if (i == 0) {
                    dp[0][0] = s.charAt(0) == p.charAt(0) || p.charAt(0) == '?';
                } else {
                    dp[0][i] = false;
                }
            }
        }

        // init first column
        int temp = 0;
        while (temp < p.length() && p.charAt(temp) == '*') {
            dp[temp][0] = true;
            temp++;
        }
        if (temp < p.length() && (p.charAt(temp) == s.charAt(0) || p.charAt(temp) == '?')) {
            dp[temp][0] = true;
            temp++;
        }
        while (temp < p.length() && p.charAt(temp) == '*') {
            dp[temp][0] = true;
            temp++;
        }
        while (temp < p.length()) {
            dp[temp][0] = false;
            temp++;
        } // init first column end

        for (int i = 1; i < p.length(); i++) {
            for (int j = 1; j < s.length(); j++) {
                boolean match = s.charAt(j) == p.charAt(i) || p.charAt(i) == '?';
                if (match) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    if (p.charAt(i) == '*') {
                        dp[i][j] = dp[i - 1][j - 1] || dp[i - 1][j] || dp[i][j - 1];
                    } else {
                        dp[i][j] = false;
                    }
                }
            }
        }
        // for (int i = 0; i < p.length(); i++) {
        //     for (int j = 0; j < s.length(); j++) {
        //         System.out.print(dp[i][j]);
        //         System.out.print(" ");
        //     }
        //     System.out.println("");
        // }
        return dp[p.length() - 1][s.length() - 1];
    }

    // public static void main(String[] args) {
    //     Solution s = new Solution();
    //     System.out.println(s.isMatch("aa", "a"));
    //     System.out.println(s.isMatch("aa", "*"));
    //     System.out.println(s.isMatch("cb", "?a"));
    //     System.out.println(s.isMatch("adceb", "a*b"));
    //     System.out.println(s.isMatch("acdcb", "a*c?b"));
    //     System.out.println(s.isMatch("acdcb", "*a*b"));
    //     System.out.println(s.isMatch("aaabababaaabaababbbaaaabbbbbbabbbbabbbabbaabbababab",
    //     "*ab***ba**b*b*aaab*b"));
    //     System.out.println(s.isMatch("ab", "?*"));
    //     System.out.println(s.isMatch("b", "?*?"));
    // }
}
