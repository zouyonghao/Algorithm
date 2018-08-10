/*
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.07%)
 * Total Accepted:    205.1K
 * Total Submissions: 639.5K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 * 
 * Example:
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 */

#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.length() < 1) return 0;
        int index = s.find_last_of(' ');
        if (index != string::npos) {
            int length = s.length() - index - 1;
            if (length > 0) return length;
            else return lengthOfLastWord(s.substr(0, index));
        }
        return s.length();
    }
};
