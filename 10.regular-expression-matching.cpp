/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 *
 * https://leetcode-cn.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (20.80%)
 * Total Accepted:    9.1K
 * Total Submissions: 43.7K
 * Testcase Example:  '"aa"\n"a"'
 *
 * 给定一个字符串 (s) 和一个字符模式 (p)。实现支持 '.' 和 '*' 的正则表达式匹配。
 *
 * '.' 匹配任意单个字符。
 * '*' 匹配零个或多个前面的元素。
 *
 *
 * 匹配应该覆盖整个字符串 (s) ，而不是部分字符串。
 *
 * 说明:
 *
 *
 * s 可能为空，且只包含从 a-z 的小写字母。
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
 *
 *
 * 示例 1:
 *
 * 输入:
 * s = "aa"
 * p = "a"
 * 输出: false
 * 解释: "a" 无法匹配 "aa" 整个字符串。
 *
 *
 * 示例 2:
 *
 * 输入:
 * s = "aa"
 * p = "a*"
 * 输出: true
 * 解释: '*' 代表可匹配零个或多个前面的元素, 即可以匹配 'a' 。因此, 重复 'a'
 * 一次, 字符串可变为 "aa"。
 *
 *
 * 示例 3:
 *
 * 输入:
 * s = "ab"
 * p = ".*"
 * 输出: true
 * 解释: ".*" 表示可匹配零个或多个('*')任意字符('.')。
 *
 *
 * 示例 4:
 *
 * 输入:
 * s = "aab"
 * p = "c*a*b"
 * 输出: true
 * 解释: 'c' 可以不被重复, 'a' 可以被重复一次。因此可以匹配字符串 "aab"。
 *
 *
 * 示例 5:
 *
 * 输入:
 * s = "mississippi"
 * p = "mis*is*p*."
 * 输出: false
 *
 * aaa
 * a*a
 *
 * cpp solution failed, see java version.
 * 
 */
#include <string>
using namespace std;
class Solution {
  public:
    bool isMatch(string s, string p) {
        return isMatch(s, 0, p, 0);
    }
    bool isMatch(string s, int i, string p, int j) {
        if (i == s.length() && j == p.length()) {
            return true;
        }

        if (i != s.length() && j == p.length()) {
            return false;
        }

        while (i == s.length() && j < p.length()) {
            if (j + 1 < p.length() && p[j + 1] == '*') {
                j += 2;
            } else {
                return false;
            }
        }

        bool match = false;
        if (s[i] == p[j] || p[j] == '.') {
            match = true;
        }
        if (j + 1 < p.length() && p[j + 1] == '*') {
            return isMatch(s, i, p, j + 2) ||
                   (match && isMatch(s, i + 1, p, j);
        } else {
            return match && isMatch(s, i + 1, p , j + 1);
        }
    }
};
