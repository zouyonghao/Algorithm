/*
 * [349] Intersection of Two Arrays
 *
 * https://leetcode-cn.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (49.55%)
 * Total Accepted:    4.5K
 * Total Submissions: 8.8K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * 给定两个数组，编写一个函数来计算它们的交集。
 * 
 * 示例 1:
 * 
 * 输入: nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出: [2]
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出: [9,4]
 * 
 * 说明:
 * 
 * 
 * 输出结果中的每个元素一定是唯一的。
 * 我们可以不考虑输出结果的顺序。
 * 
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> result;
        for (int i = 0, j = 0; i < nums1.size() && j < nums2.size(); ) {
            if (nums1[i] < nums2[j]) {
                i++;
            }
            else if (nums2[j] < nums1[i]) {
                j++;
            }
            else if (nums1[i] == nums2[j]) {
                if (result.size() == 0 || result[result.size() - 1] != nums1[i])
                    result.push_back(nums1[i]);
                i++;
                j++;
            }
        }

        return result;
        
    }
};
