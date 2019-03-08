/*
 * @lc app=leetcode.cn id=414 lang=java
 *
 * [414] 第三大的数
 *
 * https://leetcode-cn.com/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (30.62%)
 * Total Accepted:    5.8K
 * Total Submissions: 18.9K
 * Testcase Example:  '[3,2,1]'
 *
 * 给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [3, 2, 1]
 * 
 * 输出: 1
 * 
 * 解释: 第三大的数是 1.
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [1, 2]
 * 
 * 输出: 2
 * 
 * 解释: 第三大的数不存在, 所以返回最大的数 2 .
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: [2, 2, 3, 1]
 * 
 * 输出: 1
 * 
 * 解释: 注意，要求返回第三大的数，是指第三大且唯一出现的数。
 * 存在两个值为2的数，它们都排第二。
 * 
 * 
 */
class Solution {
    public int thirdMax(int[] nums) {
        if (nums.length < 1) {
            return -1; // illegal
        }
        if (nums.length < 3) {
            return nums.length == 1 ? nums[0] : Math.max(nums[0], nums[1]);
        }

        long[] max = new long[] { Long.MIN_VALUE, Long.MIN_VALUE, Long.MIN_VALUE };
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > max[0]) {
                max[2] = max[1];
                max[1] = max[0];
                max[0] = nums[i];
            } else if (nums[i] > max[1] && nums[i] != max[0]) {
                max[2] = max[1];
                max[1] = nums[i];
            } else if (nums[i] > max[2] && nums[i] != max[0] && nums[i] != max[1]) {
                max[2] = nums[i];
            }
        }
        return (int) (max[2] == Long.MIN_VALUE ? max[0] : max[2]);
    }
}
