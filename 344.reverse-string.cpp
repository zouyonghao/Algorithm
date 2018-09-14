/*
 * [344] Reverse String
 *
 * https://leetcode-cn.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (62.64%)
 * Total Accepted:    17.2K
 * Total Submissions: 27.6K
 * Testcase Example:  '"hello"'
 *
 * 编写一个函数，其作用是将输入的字符串反转过来。
 * 
 * 示例 1:
 * 
 * 输入: "hello"
 * 输出: "olleh"
 * 
 * 
 * 示例 2:
 * 
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: "amanaP :lanac a ,nalp a ,nam A"
 * 
 */
class Solution {
public:
    string reverseString(string s) {
        for (int i = 0; i < s.length() / 2; i++) {
            swap(s[i], s[s.length() - 1 - i]);
        }
        return s;
    }
};
