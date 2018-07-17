// 给定一个矩阵 A， 返回 A 的转置矩阵。
// 矩阵的转置是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。
// 示例 1：
// 输入：[[1,2,3],[4,5,6],[7,8,9]]
// 输出：[[1,4,7],[2,5,8],[3,6,9]]
// 示例 2：
// 输入：[[1,2,3],[4,5,6]]
// 输出：[[1,4],[2,5],[3,6]]

#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> transpose(vector<vector<int>> &A) {
        vector<vector<int>> AT;
        int rowSize = A[0].size();
        for (int i = 0; i < rowSize; i++) {
            vector<int> t;
            AT.push_back(t);
        }
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                AT[j].push_back(A[i][j]);
            }
        }
        return AT;
    }
};