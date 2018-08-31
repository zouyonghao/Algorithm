/*
 * [202] Happy Number
 *
 * https://leetcode-cn.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (47.03%)
 * Total Accepted:    3.8K
 * Total Submissions: 8K
 * Testcase Example:  '19'
 *
 * 编写一个算法来判断一个数是不是“快乐数”。
 * 
 * 一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到
 * 1。如果可以变为 1，那么这个数就是快乐数。
 * 
 * 示例: 
 * 
 * 输入: 19
 * 输出: true
 * 解释: 
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 * 
 * 
 */
#include <vector>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        if (n <= 0) return false;
        vector<int> process;
        process.push_back(n);
        while (n != 1) {
            int tmp = n;
            n = 0;
            while (tmp > 0) {
                n += (tmp % 10) * (tmp % 10);
                tmp /= 10;
            }
            for (int i = 0; i < process.size(); i++) {
                if (process[i] == n) return false;
            }
            process.push_back(n);
        }
        return true;
    }
};
