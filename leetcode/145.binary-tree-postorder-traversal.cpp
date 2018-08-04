/*
 * [145] Binary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (43.57%)
 * Total Accepted:    193.3K
 * Total Submissions: 443.3K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [3,2,1]
 * 
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> result;
    stack<TreeNode *> s;
    void gotoHLVF() {
        TreeNode * x;
        while ((x = s.top())) {
            if (x->left) {
                if (x->right) {
                    s.push(x->right);
                }
                s.push(x->left);
            } else {
                s.push(x->right);
            }
        }
        s.pop();
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return result;
        s.push(root);
        TreeNode * x = s.top();
        while(!s.empty()) {
            if (s.top()->left != x && s.top()->right != x) {
                gotoHLVF();
            }
            x = s.top();
            result.push_back(x->val);
            s.pop();
        }
        return result;
    }
};
