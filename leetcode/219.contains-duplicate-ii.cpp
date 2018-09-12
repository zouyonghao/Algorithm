/*
 * [219] Contains Duplicate II
 *
 * https://leetcode-cn.com/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (26.68%)
 * Total Accepted:    3K
 * Total Submissions: 10.9K
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * 给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j
 * 的差的绝对值最大为 k。
 * 
 * 示例 1:
 * 
 * 输入: nums = [1,2,3,1], k = 3
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入: nums = [1,0,1,1], k = 1
 * 输出: true
 * 
 * 示例 3:
 * 
 * 输入: nums = [1,2,3,1,2,3], k = 2
 * 输出: false
 * 
 */

#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> numMap;
        for (int i = 0; i < nums.size(); i++) {
            if (numMap.find(nums[i]) != numMap.end()) {
                if (i - numMap[nums[i]] <= k) {
                    return true;
                } else {
                    numMap[nums[i]] = i;
                }
            } else {
                numMap[nums[i]] = i;
            }
        }
        return false;
    }
};
