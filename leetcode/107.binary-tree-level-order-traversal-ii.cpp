/*
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (51.34%)
 * Total Accepted:    2.9K
 * Total Submissions: 5.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其自底向上的层次遍历为：
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 * 
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
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        vector<TreeNode*> level;
        level.push_back(root);
        while(!level.empty()) {
            vector<int> tmp_result;
            vector<TreeNode *> tmp_level;
            for (int i = 0; i < level.size(); i++) {
                if (level[i]->left) {
                    tmp_level.push_back(level[i]->left);
                }
                if (level[i]->right) {
                    tmp_level.push_back(level[i]->right);
                }
                tmp_result.push_back(level[i]->val);
            }
            level = tmp_level;
            result.insert(result.begin(), tmp_result);
        }
        return result;
    }
};
