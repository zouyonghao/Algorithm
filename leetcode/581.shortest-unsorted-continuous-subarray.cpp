/*
 * [581] Shortest Unsorted Continuous Subarray
 *
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Easy (29.36%)
 * Total Accepted:    40.7K
 * Total Submissions: 138.6K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * Given an integer array, you need to find one continuous subarray that if you
 * only sort this subarray in ascending order, then the whole array will be
 * sorted in ascending order, too.
 *
 * You need to find the shortest such subarray and output its length.
 *
 * Example 1:
 *
 * Input: [2, 6, 4, 8, 10, 9, 15]
 * Output: 5
 * Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make
 * the whole array sorted in ascending order.
 *
 *
 *
 * Note:
 *
 * Then length of the input array is in range [1, 10,000].
 * The input array may contain duplicates, so ascending order here means .
 *
 *
 */
class Solution {
  public:
    // 这个思路有点像 unimodal 的解法
    int findUnsortedSubarray(vector<int> &nums) {
        int l = 0, r = nums.size() - 1, min = INT_MAX, max = INT_MIN;

        while (l < r && nums[l] <= nums[l + 1])
            l++;

        if (l == r)
            return 0;

        while (nums[r] >= nums[r - 1])
            r--;

        for (int k = l; k <= r; k++) {
            max = max > nums[k] ? max : nums[k];
            min = min < nums[k] ? min : nums[k];
        }

        while (l >= 0 && min < nums[l])
            l--;
        while (r <= nums.size() - 1 && max > nums[r])
            r++;

        return r - l - 1;
    }
};
