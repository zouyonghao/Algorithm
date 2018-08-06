/*
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (29.58%)
 * Total Accepted:    299.2K
 * Total Submissions: 1M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */

class Solution {
public:
    int* buildNext(string pattern) {
        int *next = new int[pattern.length()];
        int t = next[0] = -1;
        for (int i = 0; i < pattern.length() - 1;) {
            if (t < 0 || pattern[i] == pattern[t]) {
                i++;
                t++;
                next[i] = t;
            } else {
                t = next[t];
            }
        }
        return next;
    }
    int strStr(string haystack, string needle) {
        if (needle.length() < 1) return 0;
        int * next = buildNext(needle);
        int i = 0, j = 0;
        int m = haystack.length();
        int p = needle.length();
        while((i < m) && (j < p)) {
            if (j < 0 || haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }
        delete [] next;
        if (j == p) {
            return i - j;
        }
        return -1;
    }
};
