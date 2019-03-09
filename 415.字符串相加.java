/*
 * @lc app=leetcode.cn id=415 lang=java
 *
 * [415] 字符串相加
 *
 * https://leetcode-cn.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (43.50%)
 * Total Accepted:    5K
 * Total Submissions: 11.6K
 * Testcase Example:  '"0"\n"0"'
 *
 * 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
 * 
 * 注意：
 * 
 * 
 * num1 和num2 的长度都小于 5100.
 * num1 和num2 都只包含数字 0-9.
 * num1 和num2 都不包含任何前导零。
 * 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。
 * 
 * 
 */
class Solution {
    public String addStrings(String num1, String num2) {
        int advance = 0;
        if (num1.length() < num2.length()) {
            String temp = num1;
            num1 = num2;
            num2 = temp;
        }
        String result = "";
        for (int i = num1.length() - 1, j = num2.length() - 1; i >= 0; i--) {
            int temp;
            if (j >= 0) {
                temp = advance + num1.charAt(i) - '0' + num2.charAt(j) - '0';
                j--;
            } else {
                temp = num1.charAt(i) - '0' + advance;
            }
            advance = temp / 10;
            temp = temp % 10;
            result = temp + result;
        }
        if (advance > 0) {
            result = advance + result;
        }
        return result;
    }

    // public static void main(String[] args) {
    //     Solution s = new Solution();
    //     System.out.println(s.addStrings("1234", "4123"));
    //     System.out.println(s.addStrings("9", "99"));
    // }
}

