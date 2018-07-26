/*
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (41.85%)
 * Total Accepted:    232.9K
 * Total Submissions: 556.3K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 *
 * Example 1:
 *
 *
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 *
 *
 * Example 2:
 *
 *
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 *
 */
class Solution {
  public:
    int quickselect(vector<int> &nums, int lo, int hi) {
        if (lo > hi)
            return lo;
        int pivot = nums[lo];
        // cout << pivot << " ";
        int i = lo;
        for (int j = lo + 1; j < hi; j++) {
            if (nums[j] > pivot) {
                swap(nums[j], nums[++i]);
            }
        }
        swap(nums[i], nums[lo]);
        return i;
    }
    int findKthLargest(vector<int> &nums, int k) {
        int i = quickselect(nums, 0, nums.size());
        int lo = 0, hi = nums.size();
        while (true) {
            // cout << i << " ";
            if (i + 1 > k) {
                hi = i;
            } else if (i + 1 < k) {
                lo = i + 1;
                // k = k - (i + 1);
            } else {
                return nums[i];
            }
            i = quickselect(nums, lo, hi);
        }
        // return nums[lo];
    }
};
