/*
 * [110] Balanced Binary Tree
 *
 * https://leetcode-cn.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (42.87%)
 * Total Accepted:    3.1K
 * Total Submissions: 7.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。
 * 
 * 本题中，一棵高度平衡二叉树定义为：
 * 
 * 
 * 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
 * 
 * 
 * 示例 1:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7]
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回 true 。
 * 
 * 示例 2:
 * 
 * 给定二叉树 [1,2,2,3,3,null,null,4,4]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   2
 * ⁠   / \
 * ⁠  3   3
 * ⁠ / \
 * ⁠4   4
 * 
 * 
 * 返回 false 。
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int heightLeft = getHeight(root->left);
        int heightRight = getHeight(root->right);
        if (heightLeft >= 0 && heightRight >= 0 && abs(heightLeft - heightRight) < 2) {
            return true;
        }
        return false;
    }

    int getHeight(TreeNode* root) {
        if (!root) return 0;
        int heightLeft = getHeight(root->left);
        int heightRight = getHeight(root->right);
        if (heightLeft >= 0 && heightRight >= 0 && abs(heightLeft - heightRight) < 2) {
            return 1 + max(heightLeft, heightRight);
        }
        return -1;
    }

};
