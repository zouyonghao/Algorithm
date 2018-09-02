/*
 * [205] Isomorphic Strings
 *
 * https://leetcode-cn.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (38.50%)
 * Total Accepted:    1.9K
 * Total Submissions: 5K
 * Testcase Example:  '"egg"\n"add"'
 *
 * 给定两个字符串 s 和 t，判断它们是否是同构的。
 * 
 * 如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
 * 
 * 所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。
 * 
 * 示例 1:
 * 
 * 输入: s = "egg", t = "add"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "foo", t = "bar"
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: s = "paper", t = "title"
 * 输出: true
 * 
 * 说明:
 * 你可以假设 s 和 t 具有相同的长度。
 * 
 */
#include<string>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int tmp = -1;
        int* pattern = new int[s.length()];
        pattern[0] = -1;
        for (int i = 0; i < s.length(); ) {
            if (tmp < 0 || s[i] == s[tmp]) {
                i++;
                tmp++;
                pattern[i] = tmp;
            } else {
                tmp = pattern[tmp];
            }
        }
        tmp = -1;
        int* pattern2 = new int[t.length()];
        pattern2[0] = -1;
        for (int i = 0; i < t.length(); ) {
            if (tmp < 0 || t[i] == t[tmp]) {
                i++;
                tmp++;
                pattern2[i] = tmp;
            } else {
                tmp = pattern2[tmp];
            }
        }
        for (int i = 0; i < t.length(); i++) {
            if (pattern[i] != pattern2[i])
                return false;
        }
        return true;
    }
};
