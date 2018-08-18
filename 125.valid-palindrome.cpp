/*
 * [125] Valid Palindrome
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (34.06%)
 * Total Accepted:    8.4K
 * Total Submissions: 24.6K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 * 
 * 示例 1:
 * 
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "race a car"
 * 输出: false
 * 
 * 
 */
class Solution {
public:
    bool isPalindrome(string s) {
        string trim;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                trim += s[i];
                continue;
            }
            if (s[i] >= 'A' && s[i] <= 'Z') {
                trim += s[i] - 'A' + 'a';
                continue;
            }
            if (s[i] >= '0' && s[i] <= '9') {
                trim += s[i];
            }
        }
        for (int i = 0; i < trim.size() / 2; i ++) {
            if (trim[i] != trim[trim.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};
