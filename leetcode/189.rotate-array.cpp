/*
 * [189] Rotate Array
 *
 * https://leetcode-cn.com/problems/rotate-array/description/
 *
 * algorithms
 * Easy (31.80%)
 * Total Accepted:    18.3K
 * Total Submissions: 57.1K
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3,4,5,6,7] 和 k = 3
 * 输出: [5,6,7,1,2,3,4]
 * 解释:
 * 向右旋转 1 步: [7,1,2,3,4,5,6]
 * 向右旋转 2 步: [6,7,1,2,3,4,5]
 * 向右旋转 3 步: [5,6,7,1,2,3,4]
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-1,-100,3,99] 和 k = 2
 * 输出: [3,99,-1,-100]
 * 解释: 
 * 向右旋转 1 步: [99,-1,-100,3]
 * 向右旋转 2 步: [3,99,-1,-100]
 * 
 * 说明:
 * 
 * 
 * 尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
 * 要求使用空间复杂度为 O(1) 的原地算法。
 * 
 * 
 */
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k > nums.size()) {
            k = k % nums.size();
        }
        for (int i = 0; i < nums.size() / 2; i++) {
            swap(nums[i], nums[nums.size() - 1 - i]);
        }
        for (int i = 0; i < k / 2; i++) {
            swap(nums[i], nums[k - 1 - i]);
        }
        for (int i = k; i < k + (nums.size() - k) / 2; i++) {
            swap(nums[i], nums[nums.size() - 1 - (i - k)]);
        }
    }
};
