/*
 * [290] Word Pattern
 *
 * https://leetcode.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (33.76%)
 * Total Accepted:    111.7K
 * Total Submissions: 330.6K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 * 
 * Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in str.
 * 
 * Example 1:
 * 
 * 
 * Input: pattern = "abba", str = "dog cat cat dog"
 * Output: true
 * 
 * Example 2:
 * 
 * 
 * Input:pattern = "abba", str = "dog cat cat fish"
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: pattern = "aaaa", str = "dog cat cat dog"
 * Output: false
 * 
 * Example 4:
 * 
 * 
 * Input: pattern = "abba", str = "dog dog dog dog"
 * Output: false
 * 
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains
 * lowercase letters separated by a single space.
 * 
 */

#include <string>
#include <vector>
#include <iostream>
using namespace std;

// kmp 思路不太对，只能通过部分结果
// kmp 是为了找前缀和后缀相同的，不是整体特征。
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if (pattern.length() < 1) return false;
        // build next
        int *next = new int[pattern.length()];
        int t = next[0] = -1;
        for (int i = 0; i < pattern.length() - 1;) {
            if (t < 0 || pattern[i] == pattern[t]) {
                i++;
                t++;
                next[i] = (pattern[i] != pattern[t] ? t : next[t]);
            } else {
                t = next[t];
            }
        }
        vector<string> v;
        while(str.find(' ') != string::npos) {
            v.push_back(str.substr(0, str.find(' ')));
            str = str.substr(str.find(' ') + 1);
        }
        v.push_back(str);
        if (v.size() != pattern.length()) {
            return false;
        }
        int *next2 = new int[pattern.length()];
        t = next2[0] = -1;
        for (int i = 0; i < pattern.length() - 1;) {
            if (t < 0 || v[i] == v[t]) {
                i++;
                t++;
                next2[i] = (v[i] != v[t] ? t : next2[t]);
            } else {
                t = next2[t];
            }
        }
        for (int i = 0; i < pattern.length(); i++) {
            if (next[i] != next2[i])
                return false;
        }
        return true;
    }
};
