/*
 * @lc app=leetcode.cn id=409 lang=java
 *
 * [409] 最长回文串
 *
 * https://leetcode-cn.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (45.64%)
 * Total Accepted:    3.8K
 * Total Submissions: 8.1K
 * Testcase Example:  '"abccccdd"'
 *
 * 给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
 * 
 * 在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
 * 
 * 注意:
 * 假设字符串的长度不会超过 1010。
 * 
 * 示例 1: 
 * 
 * 
 * 输入:
 * "abccccdd"
 * 
 * 输出:
 * 7
 * 
 * 解释:
 * 我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
 * 
 * 
 */
class Solution {
    public int longestPalindrome(String s) {
        int[] alphabet1 = new int[26];
        int[] alphabet2 = new int[26];
        for (int i = 0; i < 26; i++) {
            alphabet1[i] = 0;
            alphabet2[i] = 0;
        }
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) >= 'a' && s.charAt(i) <= 'z')
                alphabet1[s.charAt(i) - 'a']++;
            if (s.charAt(i) >= 'A' && s.charAt(i) <= 'Z')
                alphabet2[s.charAt(i) - 'A']++;
        }

        int odd = 0;
        int maxLength = 0;
        for (int i = 0; i < 26; i++) {
            // System.out.println((char) (i + 'a'));
            // System.out.println(alphabet1[i]);
            if (alphabet1[i] % 2 == 0) {
                maxLength += alphabet1[i];
            } else {
                // maxOdd = Math.max(maxOdd, alphabet1[i]);
                maxLength += alphabet1[i] - 1;
                odd = 1;
            }
            if (alphabet2[i] % 2 == 0) {
                maxLength += alphabet2[i];
            } else {
                maxLength += alphabet2[i] - 1;
                odd = 1;
            }
        }
        return maxLength + odd;
    }

    // public static void main(String[] args) {
    //     Solution s = new Solution();
    //     System.out.println(s.longestPalindrome("abccccdd"));
    //     System.out.println(s.longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth"));
    // }
}
