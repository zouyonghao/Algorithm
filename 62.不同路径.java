/*
 * @lc app=leetcode.cn id=62 lang=java
 *
 * [62] 不同路径
 *
 * https://leetcode-cn.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (51.92%)
 * Total Accepted:    13.7K
 * Total Submissions: 26.2K
 * Testcase Example:  '3\n2'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 * 
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 * 
 * 问总共有多少条不同的路径？
 * 
 * 
 * 
 * 例如，上图是一个7 x 3 的网格。有多少可能的路径？
 * 
 * 说明：m 和 n 的值均不超过 100。
 * 
 * 示例 1:
 * 
 * 输入: m = 3, n = 2
 * 输出: 3
 * 解释:
 * 从左上角开始，总共有 3 条路径可以到达右下角。
 * 1. 向右 -> 向右 -> 向下
 * 2. 向右 -> 向下 -> 向右
 * 3. 向下 -> 向右 -> 向右
 * 
 * 
 * 示例 2:
 * 
 * 输入: m = 7, n = 3
 * 输出: 28
 * 
 */
class Solution {
    public int uniquePaths(int m, int n) {
        // if (m < 1 || n < 1)
        //     return 0;
        int[][] a = new int[m][n];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                a[i][j] = 0;
        solve(a, 0, 0, m, n);
        return a[0][0];

    }

    public int solve(int[][] a, int i, int j, int m, int n) {
        if (i == m - 1 && j == n - 1) {
            return a[i][j] = 1;
        }
        if (i >= m || j >= n) {
            return 0;
        }
        if (a[i][j] > 0) {
            return a[i][j];
        } else {
            return a[i][j] = solve(a, i + 1, j, m, n) + solve(a, i, j + 1, m, n);
        }
    }

    // public static void main(String[] args) {
    //     Solution s = new Solution();
    //     System.out.println(s.uniquePaths(7, 3));
    //     System.out.println(s.uniquePaths(1, 1));
    // }
}
