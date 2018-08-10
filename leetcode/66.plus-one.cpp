/*
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (39.91%)
 * Total Accepted:    272.5K
 * Total Submissions: 682.4K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 * 
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * 
 * 
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size() - 1]++;
        int proceeding = digits[digits.size() - 1] / 10;
        int j = digits.size() - 2;
        while (proceeding != 0) {
            if (j >= 0) {
                digits[j] = digits[j] + proceeding;
                digits[j + 1] = digits[j + 1] % 10;
                proceeding = digits[j] / 10;
                j--;
            } else {
                digits[j + 1] = digits[j + 1] % 10;
                digits.insert(digits.begin(), proceeding);
                proceeding = 0;
            }
        }
        return digits;
    }
};
