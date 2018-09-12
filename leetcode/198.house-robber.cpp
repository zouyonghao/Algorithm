/*
 * [198] House Robber
 *
 * https://leetcode-cn.com/problems/house-robber/description/
 *
 * algorithms
 * Easy (37.14%)
 * Total Accepted:    7K
 * Total Submissions: 18.7K
 * Testcase Example:  '[1,2,3,1]'
 *
 * 
 * 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 * 
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3,1]
 * 输出: 4
 * 解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
 * 偷窃到的最高金额 = 1 + 3 = 4 。
 * 
 * 示例 2:
 * 
 * 输入: [2,7,9,3,1]
 * 输出: 12
 * 解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
 * 偷窃到的最高金额 = 2 + 9 + 1 = 12 。
 * 
 * 
 */
class Solution {
public:
    // method1 recurrence, too slow.
    // int rob(vector<int>& nums) {
    //     if (nums.size() < 1) return 0;
    //     vector<int> nums1;
    //     vector<int> nums2;
    //     int first = nums[0];
    //     for (int i = 1; i < nums.size(); i++) {
    //         nums1.push_back(nums[i]);
    //     }
    //     for (int i = 2; i < nums.size(); i++) {
    //         nums2.push_back(nums[i]);
    //     }
    //     return max(first + rob(nums2), rob(nums1));
    // }

    // recurrence version2, also too slow.
    // int rob(vector<int>& nums) {
    //     return rob(nums, 0);
    // }
    // int rob(vector<int>& nums, int first) {
    //     if (first >= nums.size()) {
    //         return 0;
    //     }
    //     int firstNum = nums[first];
    //     return max(firstNum + rob(nums, first + 2), rob(nums, first + 1));
    // }

    int rob(vector<int>& nums) {
        if (nums.size() < 1) return 0;
        // use dp
        vector<int> result;
        result.push_back(nums[0]);
        result.push_back(0);
        for (int i = 1; i < nums.size(); i++) {
            // use current
            result.push_back(result[i * 2 - 1] + nums[i]);
            // do not use current
            result.push_back(max(result[i * 2 - 2], result[i * 2 - 1]));
        }
        return max(result[result.size() - 2], result[result.size() - 1]);
    }
};
