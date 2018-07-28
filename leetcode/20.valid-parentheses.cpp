/*
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (34.33%)
 * Total Accepted:    368K
 * Total Submissions: 1.1M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 *
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 *
 *
 * Note that an empty string is also considered valid.
 *
 * Example 1:
 *
 *
 * Input: "()"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: "()[]{}"
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: "(]"
 * Output: false
 *
 *
 * Example 4:
 *
 *
 * Input: "([)]"
 * Output: false
 *
 *
 * Example 5:
 *
 *
 * Input: "{[]}"
 * Output: true
 *
 *
 */
class Solution {
  public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                st.push(s[i]);
            else if (s[i] == '[')
                st.push(s[i]);
            else if (s[i] == '{')
                st.push(s[i]);
            else if (s[i] == ')') {
                if (st.empty() || st.top() != '(') {
                    return false;
                }
                st.pop();
            } else if (s[i] == ']') {
                if (st.empty() || st.top() != '[') {
                    return false;
                }
                st.pop();
            } else if (s[i] == '}') {
                if (st.empty() || st.top() != '{') {
                    return false;
                }
                st.pop();
            }
        }
        if (!st.empty())
            return false;
        return true;
    }
};
