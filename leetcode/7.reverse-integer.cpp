/*
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (24.37%)
 * Total Accepted:    443.8K
 * Total Submissions: 1.8M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of
 * this problem, assume that your function returns 0 when the reversed integer
 * overflows.
 * 
 */
class Solution {
public:
    int array[1000];
    int size = 0;
    int reverse(int x) {
        bool negative = false;
        if (x < 0) {
            x = -x;
            negative = true;
        }
        while (x > 0) {
            array[size++] = x % 10;
            x /= 10;
        }
        int result = 0;
        int firstNotZero = false;
        for (int i = 0; i < size; i++) {
            if (array[i] == 0 && !firstNotZero) {
                continue;
            }
            firstNotZero = true;
            int tmp = result * 10 + array[i];
            // 1534236469
            if ((tmp - array[i]) / 10 != result) {
                return 0;
            }
            result = tmp;
        }
        if (negative) {
            result = -result;
        }
        return result;
    }
};
