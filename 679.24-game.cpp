/*
 * [679] 24 Game
 *
 * https://leetcode-cn.com/problems/24-game/description/
 *
 * algorithms
 * Hard (29.73%)
 * Total Accepted:    102
 * Total Submissions: 359
 * Testcase Example:  '[4,1,8,7]'
 *
 * 你有 4 张写有 1 到 9 数字的牌。你需要判断是否能通过 *，/，+，-，(，) 的运算得到 24。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [4, 1, 8, 7]
 * 输出: True
 * 解释: (8-4) * (7-1) = 24
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [1, 2, 1, 2]
 * 输出: False
 * 
 * 
 * 注意:
 * 
 * 
 * 除法运算符 / 表示实数除法，而不是整数除法。例如 4 / (1 - 2/3) = 12 。
 * 每个运算符对两个数进行运算。特别是我们不能用 - 作为一元运算符。例如，[1, 1, 1, 1] 作为输入时，表达式 -1 - 1 - 1 - 1
 * 是不允许的。
 * 你不能将数字连接在一起。例如，输入为 [1, 2, 1, 2] 时，不能写成 12 + 12 。
 * 
 * 
 */
#include <vector>
using namespace std;
class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> a;
        for (int i = 0; i < nums.size(); i++) {
            a.push_back(nums[i]);
        }
        return judgePoint24(a);
    }
    bool judgePoint24(vector<double> nums) {
        if (nums.size() == 1) {
            if (abs(nums[0] - 24) < 1e-9)
                return true;
            else 
                return false;
        }
        vector<double> b;
        b.resize(nums.size() - 1);
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int m = 0;
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j)
                        b[m++] = nums[k];
                }
                b[m] = nums[i] + nums[j];
                if (judgePoint24(b)) return true;
                b[m] = nums[i] - nums[j];
                if (judgePoint24(b)) return true;
                b[m] = nums[j] - nums[i];
                if (judgePoint24(b)) return true;
                b[m] = nums[i] * nums[j];
                if (judgePoint24(b)) return true;
                if (abs(nums[j]) > 0)
                    b[m] = nums[i] / nums[j];
                if (judgePoint24(b)) return true;
                if (abs(nums[i]) > 0)
                    b[m] = nums[j] / nums[i];
                if (judgePoint24(b)) return true;

            }
        }
        return false;
    }
};
