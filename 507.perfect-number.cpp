/*
 * [507] Perfect Number
 *
 * https://leetcode.com/problems/perfect-number/description/
 *
 * algorithms
 * Easy (32.67%)
 * Total Accepted:    27.2K
 * Total Submissions: 83.3K
 * Testcase Example:  '28'
 *
 * We define the Perfect Number is a positive integer that is equal to the sum
 * of all its positive divisors except itself. 
 * 
 * Now, given an integer n, write a function that returns true when it is a
 * perfect number and false when it is not.
 * 
 * 
 * Example:
 * 
 * Input: 28
 * Output: True
 * Explanation: 28 = 1 + 2 + 4 + 7 + 14
 * 
 * 
 * 
 * Note:
 * The input number n will not exceed 100,000,000. (1e8)
 * 
 */
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 0) return false;
        int result = 0;
        for (int i = 1; i <= num / 2; i++) {
            if (num % i == 0) {
                result += i;
            }
        }
        return result == num;
    }
};
