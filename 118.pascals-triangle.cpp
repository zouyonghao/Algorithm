/*
 * [118] Pascal's Triangle
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (54.81%)
 * Total Accepted:    5.3K
 * Total Submissions: 9.7K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 5
 * 输出:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (numRows < 1) return result;
        vector<int> tmp;
        tmp.push_back(1);
        result.push_back(tmp);
        for (int i = 1; i < numRows; i++) {
            vector<int> tmp;
            tmp.push_back(1);
            vector<int> last = result[i-1];
            for (int j = 1; j < i; j++) {
                tmp.push_back(last[j - 1] + last[j]);
            }
            tmp.push_back(1);
            result.push_back(tmp);
        }
        return result;
    }
};
