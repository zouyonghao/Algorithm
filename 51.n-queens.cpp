/*
 * [51] N-Queens
 *
 * https://leetcode-cn.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (53.52%)
 * Total Accepted:    1.2K
 * Total Submissions: 2.3K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
 * 
 * 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 示例:
 * 
 * 输入: 4
 * 输出: [
 * ⁠[".Q..",  // 解法 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // 解法 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * 解释: 4 皇后问题存在两个不同的解法。
 * 
 * 
 */

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> queens;
    vector<vector<string>> result;
    int max;
    vector<vector<string>> solveNQueens(int n) {
        if (n < 0) return result;
        max = n - 1;
        for (int i = 0; i < n; i++) 
            queens.push_back(-1);
        putQueen(0);
        return result;
    }
    void putQueen(int i) {
        if (i == max + 1) {
            vector<string> v;
            for (int j = 0; j <= max; j++) {
                string a;
                for (int k = 0; k <= max; k++) {
                    if (k == queens[j]) {
                        a.push_back('Q');
                    } else {
                        a.push_back('.');
                    }
                }
                v.push_back(a);
            }
            result.push_back(v);
            return;
        }
        for (int j = 0; j <= max; j++) {
            bool conflict = false;
            for (int k = 0; k < i; k++) {
                if (j == queens[k] || abs(queens[k] - j) == abs(k - i)) {
                    conflict = true;
                    break;
                }
            }
            if (!conflict) {
                queens[i] = j;
                putQueen(i + 1);
            }
        }
        
    }
};
