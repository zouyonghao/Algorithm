/*
 * [13] Roman to Integer
 *
 * https://leetcode.com/problems/roman-to-integer/description/
 *
 * algorithms
 * Easy (48.88%)
 * Total Accepted:    258.7K
 * Total Submissions: 529K
 * Testcase Example:  '"III"'
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D
 * and M.
 *
 *
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 *
 * For example, two is written as II in Roman numeral, just two one's added
 * together. Twelve is written as, XII, which is simply X + II. The number
 * twenty seven is written as XXVII, which is XX + V + II.
 *
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is
 * written as IV. Because the one is before the five we subtract it making
 * four. The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 *
 *
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 *
 *
 * Given a roman numeral, convert it to an integer. Input is guaranteed to be
 * within the range from 1 to 3999.
 *
 * Example 1:
 *
 *
 * Input: "III"
 * Output: 3
 *
 * Example 2:
 *
 *
 * Input: "IV"
 * Output: 4
 *
 * Example 3:
 *
 *
 * Input: "IX"
 * Output: 9
 *
 * Example 4:
 *
 *
 * Input: "LVIII"
 * Output: 58
 * Explanation: C = 100, L = 50, XXX = 30 and III = 3.
 *
 *
 * Example 5:
 *
 *
 * Input: "MCMXCIV"
 * Output: 1994
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 *
 */
//  * I             1
//  * V             5
//  * X             10
//  * L             50
//  * C             100
//  * D             500
//  * M             1000
class Solution {
  public:
    int indexOf(char c) {
        static char tables[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        for (int i = 0; i < 7; i++) {
            if (tables[i] == c) {
                return i;
            }
        }
    }
    int getNumber(char c) {
        static int tables[] = {'I', 1, 'V', 5, 'X', 10, 'L', 50, 'C', 100, 'D', 500, 'M', 1000};
        for (int i = 0; i < 14; i++) {
            if (tables[i] == c) {
                return tables[i + 1];
            }
        }
    }
    int romanToInt(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size() && indexOf(s[i]) < indexOf(s[i + 1])) {
                result += getNumber(s[i + 1]) - getNumber(s[i]);
                i++;
            } else {
                result += getNumber(s[i]);
            }
        }
        return result;
    }
};
