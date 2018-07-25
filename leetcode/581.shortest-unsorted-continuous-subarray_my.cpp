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
    void quicksort(vector<int> &nums, int left, int right) {
        if (left > right)
            return;
        int pivot = nums[left];
        int i = left;
        for (int k = left + 1; k < right; k++) {
            // 此处需要注意，因为有重复元素，所以不能用<=
            if (nums[k] < pivot) {
                i++;
                swap(nums[i], nums[k]);
            }
        }
        swap(nums[left], nums[i]);
        quicksort(nums, left, i - 1);
        quicksort(nums, i + 1, right);
    }
    int findUnsortedSubarray(vector<int> &nums) {
        int n = nums.size();
        if (n == 1)
            return 0;
        vector<int> copy;
        copy.resize(n);
        for (int i = 0; i < nums.size(); i++) {
            copy[i] = nums[i];
        }
        // for (int i = 0; i < n; i++) {
        //     cout << copy[i] << " ";
        // }
        // cout << endl;
        quicksort(copy, 0, copy.size());
        // for (int i = 0; i < n; i++) {
        //     cout << copy[i] << " ";
        // }
        int i = 0;
        for (; i < n; i++) {
            if (copy[i] != nums[i])
                break;
        }
        int j = n - 1;
        for (; j > 0; j--) {
            if (copy[j] != nums[j])
                break;
        }
        return j > i ? j - i + 1 : 0;
    }
};
