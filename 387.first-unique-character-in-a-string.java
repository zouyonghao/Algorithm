/*
 * @lc app=leetcode.cn id=387 lang=java
 *
 * [387] 字符串中的第一个唯一字符
 *
 * https://leetcode-cn.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (35.34%)
 * Total Accepted:    20.3K
 * Total Submissions: 57.2K
 * Testcase Example:  '"leetcode"'
 *
 * 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
 * 
 * 案例:
 * 
 * 
 * s = "leetcode"
 * 返回 0.
 * 
 * s = "loveleetcode",
 * 返回 2.
 * 
 * 
 * 
 * 
 * 注意事项：您可以假定该字符串只包含小写字母。
 * 
 */
class Solution {
    public int firstUniqChar(String s) {
        if (s.length() < 1) {
            return -1;
        }
        int letters[] = new int[26];
        int index[] = new int[26];
        for (int i = 0; i < 26; i++) {
            letters[i] = 0;
            index[i] = -1;
        }
        for (int i = 0; i < s.length(); i++) {
            letters[s.charAt(i) - 'a']++;
            index[s.charAt(i) - 'a'] = i;
        }

        int minIndex = -1;
        for (int i = 0; i < 26; i++) {
            if (1 == letters[i] && (minIndex == -1 || index[i] < minIndex)) {
                minIndex = index[i];
            }
        }

        return minIndex;
    }
}
