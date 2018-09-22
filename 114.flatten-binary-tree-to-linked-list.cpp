/*
 * [114] Flatten Binary Tree to Linked List
 *
 * https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (52.64%)
 * Total Accepted:    1.7K
 * Total Submissions: 3.3K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * 给定一个二叉树，原地将它展开为链表。
 *
 * 例如，给定二叉树
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 *
 * 将其展开为：
 *
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
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
    void flatten(TreeNode *root) {
        if (!root || (!root->left && !root->right))
            return;
        else if (!root->left && root->right)
            flatten(root->right);
        else if (!root->right && root->left) {
            root->right = root->left;
            root->left = nullptr;
            flatten(root->right);
        } else {
            flatten(root->left);
            flatten(root->right);
            TreeNode *leftAlong = root->left;
            while (leftAlong->right) {
                leftAlong = leftAlong->right;
            }
            leftAlong->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
    }
};
