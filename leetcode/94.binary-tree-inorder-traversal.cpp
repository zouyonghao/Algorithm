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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> s;
        vector<int> result;
        if (root) s.push(root);
        while (!s.empty()) {
            TreeNode * tmp = s.top();
            s.pop();
            while(tmp) {
                s.push(tmp);
                tmp = tmp->left;
            }
            if (!s.empty()) {
                result.push_back(s.top()->val);
                tmp = s.top();
                s.pop();
                s.push(tmp->right);
            }
        }
        return result;
    }
};