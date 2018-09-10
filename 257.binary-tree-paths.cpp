/*
 * [257] Binary Tree Paths
 *
 * https://leetcode-cn.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (51.47%)
 * Total Accepted:    2.4K
 * Total Submissions: 4.7K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给定一个二叉树，返回所有从根节点到叶子节点的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 输入:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * 输出: ["1->2->5", "1->3"]
 * 
 * 解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
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
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (!root) return result;
        string current = "";
        if (!root->left && !root->right) {
            result.push_back(to_string(root->val));
            return result;
        }
        vector<string> leftv = binaryTreePaths(root->left);
        vector<string> rightv = binaryTreePaths(root->right);
        for (int i = 0; i < leftv.size(); i++) {
            result.push_back(to_string(root->val) + "->" + leftv[i]);
        }
        for (int i = 0; i < rightv.size(); i++) {
            result.push_back(to_string(root->val) + "->" + rightv[i]);
        }
        return result;
    }
};
