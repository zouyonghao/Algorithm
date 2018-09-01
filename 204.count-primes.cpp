/*
 * [204] Count Primes
 *
 * https://leetcode-cn.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (21.53%)
 * Total Accepted:    5.3K
 * Total Submissions: 23.9K
 * Testcase Example:  '10'
 *
 * 统计所有小于非负整数 n 的质数的数量。
 * 
 * 示例:
 * 
 * 输入: 10
 * 输出: 4
 * 解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 * 
 * 
 */
class Solution {
public:
    bool isPrime(int n) {
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
    int countPrimes(int n) {
        if (n < 2) return 0;
        // 1 for prime, 0 for init, -1 for non prime
        int* flags = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            flags[i] = 0;
        }
        flags[1] = -1;
        for (int i = 2; i <= n; i++) {
            if (flags[i] == -1) {
                // pass
            } else if (flags[i] == 0) {
                if (isPrime(i)) {
                    flags[i] = 1;
                    int tmp = 2 * i;
                    while (tmp <= n) {
                        flags[tmp] = -1;
                        tmp += tmp;
                    }
                }
            } else {
                // no possible
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (flags[i] == 1) {
                count++;
            }
        }
        return count;
    }
};
