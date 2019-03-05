/*
 * @lc app=leetcode.cn id=63 lang=java
 *
 * [63] 不同路径 II
 *
 * https://leetcode-cn.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (31.26%)
 * Total Accepted:    7.5K
 * Total Submissions: 24.3K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 * 
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 * 
 * 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
 * 
 * 
 * 
 * 网格中的障碍物和空位置分别用 1 和 0 来表示。
 * 
 * 说明：m 和 n 的值均不超过 100。
 * 
 * 示例 1:
 * 
 * 输入:
 * [
 * [0,0,0],
 * [0,1,0],
 * [0,0,0]
 * ]
 * 输出: 2
 * 解释:
 * 3x3 网格的正中间有一个障碍物。
 * 从左上角到右下角一共有 2 条不同的路径：
 * 1. 向右 -> 向右 -> 向下 -> 向下
 * 2. 向下 -> 向下 -> 向右 -> 向右
 * 
 * 
 */
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if (obstacleGrid.length < 1)
            return 0;
        int a = obstacleGrid.length;
        int b = obstacleGrid[0].length;
        int[][] results = new int[a][b];
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                results[i][j] = -1;
            }
        }
        solve(results, 0, 0, a, b, obstacleGrid);
        return results[0][0];
    }

    private int solve(int[][] results, int i, int j, int a, int b, int[][] obstacleGrid) {
        if (i == a - 1 && j == b - 1) {
            return results[i][j] = obstacleGrid[i][j] == 0 ? 1 : 0;
        }
        if (i >= a || j >= b) {
            return 0;
        } else if (results[i][j] >= 0) {
            return results[i][j];
        } else {
            if (obstacleGrid[i][j] == 1) {
                return results[i][j] = 0;
            }
            return results[i][j] = solve(results, i + 1, j, a, b, obstacleGrid)
                    + solve(results, i, j + 1, a, b, obstacleGrid);
        }
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int[][] obstacleGrid1 = {};
        System.out.println(s.uniquePathsWithObstacles(obstacleGrid1));
        int[][] obstacleGrid2 = { { 0, 0, 0 }, { 0, 1, 0 }, { 0, 0, 0 } };
        System.out.println(s.uniquePathsWithObstacles(obstacleGrid2));
        int[][] obstacleGrid3 = { { 1 } };
        System.out.println(s.uniquePathsWithObstacles(obstacleGrid3));
        int[][] obstacleGrid4 = { { 1, 0 } };
        System.out.println(s.uniquePathsWithObstacles(obstacleGrid4));
    }
}
