/*
 * @lc app=leetcode.cn id=300 lang=java
 *
 * [300] 最长上升子序列
 *
 * https://leetcode-cn.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (38.58%)
 * Total Accepted:    7.8K
 * Total Submissions: 20K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * 给定一个无序的整数数组，找到其中最长上升子序列的长度。
 * 
 * 示例:
 * 
 * 输入: [10,9,2,5,3,7,101,18]
 * 输出: 4 
 * 解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
 * 
 * 说明:
 * 
 * 
 * 可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
 * 你算法的时间复杂度应该为 O(n^2) 。
 * 
 * 
 * 进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
 * 
 */
class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        if (n < 1) {
            return 0;
        }
        int[] dp = new int[n];
        dp[0] = 1;
        int max = 1;
        for (int i = 1; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                dp[i] = Math.max(dp[i], nums[j] < nums[i] ? dp[j] + 1 : 0);
            }
            max = Math.max(max, dp[i]);
        }
        return max;
    }

    // public static void main(String[] args) {
    //     Solution s = new Solution();
    //     System.out.println(s.lengthOfLIS(new int[] { 1, 6, 2, 3, 7, 5 }));
    //     System.out.println(s.lengthOfLIS(new int[] { 10, 9, 2, 5, 3, 7, 101, 18 }));
    //     System.out.println(s.lengthOfLIS(new int[] { 0 }));
    // }
}
