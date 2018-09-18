/*
 * [374] Guess Number Higher or Lower
 *
 * https://leetcode-cn.com/problems/guess-number-higher-or-lower/description/
 *
 * algorithms
 * Easy (31.91%)
 * Total Accepted:    1.9K
 * Total Submissions: 6K
 * Testcase Example:  '10\n6'
 *
 * 我们正在玩一个猜数字游戏。 游戏规则如下：
 * 我从 1 到 n 选择一个数字。 你需要猜我选择了哪个数字。
 * 每次你猜错了，我会告诉你这个数字是大了还是小了。
 * 你调用一个预先定义好的接口 guess(int num)，它会返回 3 个可能的结果（-1，1 或 0）：
 * 
 * -1 : 我的数字比较小
 * ⁠1 : 我的数字比较大
 * ⁠0 : 恭喜！你猜对了！
 * 
 * 
 * 示例 :
 * 
 * 输入: n = 10, pick = 6
 * 输出: 6
 * 
 */
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 0, right = n;
        int guessN = left + (right - left) / 2;
        int tmp = guess(guessN); 
        while (1) {
            if (tmp == 1) {
                left = guessN + 1;
            } else if (tmp == -1) {
                right = guessN - 1;
            } else {
                return guessN;
            }
            guessN = left + (right - left) / 2;
            tmp = guess(guessN);
        }
    }
};
