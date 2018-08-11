/*
 * [53] Maximum Subarray
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (36.73%)
 * Total Accepted:    11.2K
 * Total Submissions: 30.4K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 示例:
 * 
 * 输入: [-2,1,-3,4,-1,2,1,-5,4],
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 * 
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = 0;
        bool negative = true;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                negative = false;
                break;
            } else {
                if (result == 0 || nums[i] > result) {
                    result = nums[i];
                }
            }
        }
        if (negative) return result;
        result = 0;
        int tmp = 0;
        for (int i = 0; i < nums.size(); i++) {
            tmp = tmp + nums[i];
            if (tmp > result) {
                result = tmp;
            }
            if (tmp < 0) {
                tmp = 0;
            }
        }
        return result;
    }
};
