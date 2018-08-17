/*
 * [119] Pascal's Triangle II
 *
 * https://leetcode-cn.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (49.78%)
 * Total Accepted:    3.1K
 * Total Submissions: 6.2K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: [1,3,3,1]
 * 
 * 
 * 进阶：
 * 
 * 你可以优化你的算法到 O(k) 空间复杂度吗？
 * 
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> last;
        if (rowIndex < 0) return last;
        last.push_back(1);
        for (int i = 1; i <= rowIndex; i++) {
            vector<int> tmp;
            tmp.push_back(1);
            for (int j = 1; j < i; j++) {
                tmp.push_back(last[j - 1] + last[j]);
            }
            tmp.push_back(1);
            last = tmp;
        }
        return last;
    }
};
