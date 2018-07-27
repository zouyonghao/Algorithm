/*
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (31.77%)
 * Total Accepted:    300.4K
 * Total Submissions: 945.4K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string a;
        if (strs.size() < 1) {
            return a;
        }
        int i = 0;
        while (true) {
            int j = 0;
            char c = strs[j][i];
            for (; j < strs.size(); j++) {
                if (i >= strs[j].length() || strs[j][i] != c) {
                    return a;
                }
            }
            a.push_back(c);
            i++;
        }
    }
};
