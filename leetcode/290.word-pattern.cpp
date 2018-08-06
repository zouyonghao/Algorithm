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
using namespace std;

class Solution {
public:
    int findInPrefix(vector<string> v, int i, string p) {
        for (int j = 0; j < i; j++) {
            if (v[j] == p) {
                return j;
            }
        }
        return string::npos;
    }
    bool wordPattern(string pattern, string str) {
        if (pattern.length() < 1) {
            return false;
        }
        int* mode1 = new int[pattern.length()];
        for (int i = 0; i < pattern.length(); i++) {
            int index = pattern.find(pattern[i]);
            // cout << index << endl;
            if (index >= i) {
                mode1[i] = string::npos;
            } else {
                mode1[i] = index;
            }
        }
        // for (int i = 0; i < pattern.length(); i++) {
        //     cout << mode1[i];
        // }
        // cout << endl;
        vector<string> v;
        while(str.find(' ') != string::npos) {
            v.push_back(str.substr(0, str.find(' ')));
            str = str.substr(str.find(' ') + 1);
        }
        v.push_back(str);
        if (v.size() != pattern.length()) {
            return false;
        }
        int* mode2 = new int[pattern.length()];
        for (int i = 0; i < pattern.length(); i++) {
            mode2[i] = findInPrefix(v, i, v[i]);
        }
        // for (int i = 0; i < pattern.length(); i++) {
        //     cout << mode2[i];
        // }
        // cout << endl;
        for (int i = 0; i < pattern.length(); i++) {
            if (mode1[i] != mode2[i]) {
                return false;
            }
        }
        return true;
    }
};
