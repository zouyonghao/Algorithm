/*
 * @lc app=leetcode.cn id=389 lang=java
 *
 * [389] 找不同
 *
 * https://leetcode-cn.com/problems/find-the-difference/description/
 *
 * algorithms
 * Easy (53.94%)
 * Total Accepted:    6.3K
 * Total Submissions: 11.6K
 * Testcase Example:  '"abcd"\n"abcde"'
 *
 * 给定两个字符串 s 和 t，它们只包含小写字母。
 * 
 * 字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
 * 
 * 请找出在 t 中被添加的字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入：
 * s = "abcd"
 * t = "abcde"
 * 
 * 输出：
 * e
 * 
 * 解释：
 * 'e' 是那个被添加的字母。
 * 
 * 
 */
class Solution {
    public char findTheDifference(String s, String t) {
        int lettersInS[] = new int[26];
        int lettersInT[] = new int[26];
        for (int i = 0; i < 26; i++) {
            lettersInS[i] = 0;
            lettersInT[i] = 0;
        }

        for (int i = 0; i < s.length(); i++) {
            lettersInS[s.charAt(i) - 'a']++;
        }

        for (int i = 0; i < t.length(); i++) {
            lettersInT[t.charAt(i) - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (lettersInS[i] < lettersInT[i]) {
                return (char) (i + 'a');
            }
        }

        throw new RuntimeException("This line can never be touched");
    }
}
