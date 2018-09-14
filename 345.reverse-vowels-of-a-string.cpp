/*
 * [345] Reverse Vowels of a String
 *
 * https://leetcode-cn.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (40.63%)
 * Total Accepted:    2.3K
 * Total Submissions: 5.6K
 * Testcase Example:  '"hello"'
 *
 * 编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
 * 
 * 示例 1:
 * 
 * 输入: "hello"
 * 输出: "holle"
 * 
 * 
 * 示例 2:
 * 
 * 输入: "leetcode"
 * 输出: "leotcede"
 * 
 * 说明:
 * 元音字母不包含字母"y"。
 * 
 */
#include <string>
using namespace std;
class Solution {
public:
    bool isAEIOU(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
                || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    string reverseVowels(string s) {
        string result;
        if (s.length() < 1) return result;
        int i = 0, j = s.length();
        for (; i < s.length(); i++) {
            if (isAEIOU(s[i])) {
                break;
            }
        }
        for (; j >= 0; j--) {
            if (isAEIOU(s[j])) {
                break;
            }
        }
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            while (i < s.length() && !isAEIOU(s[i])) {
                i++;
            }
            j--;
            while (j >= 0 && !isAEIOU(s[j])) {
                j--;
            }
        }
        return s;
    }
};
