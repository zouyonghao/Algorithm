/*
 * @lc app=leetcode.cn id=427 lang=java
 *
 * [427] Construct Quad Tree
 *
 * https://leetcode-cn.com/problems/construct-quad-tree/description/
 *
 * algorithms
 * Easy (53.45%)
 * Total Accepted:    860
 * Total Submissions: 1.6K
 * Testcase Example:  '[[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]'
 *
 * 我们想要使用一棵四叉树来储存一个 N x N 的布尔值网络。网络中每一格的值只会是真或假。树的根结点代表整个网络。对于每个结点,
 * 它将被分等成四个孩子结点直到这个区域内的值都是相同的.
 * 
 * 每个结点还有另外两个布尔变量: isLeaf 和 val。isLeaf 当这个节点是一个叶子结点时为真。val 变量储存叶子结点所代表的区域的值。
 * 
 * 你的任务是使用一个四叉树表示给定的网络。下面的例子将有助于你理解这个问题：
 * 
 * 给定下面这个8 x 8 网络，我们将这样建立一个对应的四叉树：
 * 
 * 
 * 
 * 由上文的定义，它能被这样分割：
 * 
 * 
 * 
 * 
 * 
 * 对应的四叉树应该像下面这样，每个结点由一对 (isLeaf, val) 所代表.
 * 
 * 对于非叶子结点，val 可以是任意的，所以使用 * 代替。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * N 将小于 1000 且确保是 2 的整次幂。
 * 如果你想了解更多关于四叉树的知识，你可以参考这个 wiki 页面。
 * 
 * 
 */
/*
// Definition for a QuadTree node.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;

    public Node() {}

    public Node(boolean _val,boolean _isLeaf,Node _topLeft,Node _topRight,Node _bottomLeft,Node _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    public Node construct(int[][] grid) {
        if (grid.length < 1) {
            return new Node();
        }
        return construct(grid, 0, 0, grid.length - 1, grid.length - 1);
    }

    private Node construct(int[][] grid, int x1, int y1, int x2, int y2) {
        Node topLeft;
        Node topRight;
        Node bottomLeft;
        Node bottomRight;
        if (x2 - x1 == 1) {
            topLeft = new Node(grid[x1][y1] == 1, true, null, null, null, null);
            topRight = new Node(grid[x1][y2] == 1, true, null, null, null, null);
            bottomLeft = new Node(grid[x2][y1] == 1, true, null, null, null, null);
            bottomRight = new Node(grid[x2][y2] == 1, true, null, null, null, null);
        } else {
            topLeft = construct(grid, x1, y1, x1 + (x2 - x1) / 2, y1 + (y2 - y1) / 2);
            topRight = construct(grid, x1, y1 + (y2 - y1) / 2 + 1, x1 + (x2 - x1) / 2, y2);
            bottomLeft = construct(grid, x1 + (x2 - x1) / 2 + 1, y1, x2, y1 + (y2 - y1) / 2);
            bottomRight = construct(grid, (x1 + (x2 - x1) / 2) + 1, y1 + (y2 - y1) / 2 + 1, x2, y2);
        }

        if (topLeft.val && topRight.val && bottomLeft.val && bottomRight.val && topLeft.isLeaf && topRight.isLeaf
                && bottomLeft.isLeaf && bottomRight.isLeaf) {
            return new Node(true, true, null, null, null, null);
        } else if (!topLeft.val && !topRight.val && !bottomLeft.val && !bottomRight.val && topLeft.isLeaf
                && topRight.isLeaf && bottomLeft.isLeaf && bottomRight.isLeaf) {
            return new Node(false, true, null, null, null, null);
        } else {
            return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
        }
    }

    // public static void main(String[] args) {
    //     Solution s = new Solution();
    //     Node n = s.construct(new int[][] { { 1, 1, 1, 1, 0, 0, 0, 0 }, { 1, 1, 1, 1, 0, 0, 0, 0 },
    //             { 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 0, 0, 0, 0 },
    //             { 1, 1, 1, 1, 0, 0, 0, 0 }, { 1, 1, 1, 1, 0, 0, 0, 0 }, { 1, 1, 1, 1, 0, 0, 0, 0 } });
    // }

}

// class Node {
//     public boolean val;
//     public boolean isLeaf;
//     public Node topLeft;
//     public Node topRight;
//     public Node bottomLeft;
//     public Node bottomRight;

//     public Node() {
//     }

//     public Node(boolean _val, boolean _isLeaf, Node _topLeft, Node _topRight, Node _bottomLeft, Node _bottomRight) {
//         val = _val;
//         isLeaf = _isLeaf;
//         topLeft = _topLeft;
//         topRight = _topRight;
//         bottomLeft = _bottomLeft;
//         bottomRight = _bottomRight;
//     }
// };
