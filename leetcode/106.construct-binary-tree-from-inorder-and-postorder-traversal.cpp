/*
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (34.91%)
 * Total Accepted:    116.6K
 * Total Submissions: 333.5K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() < 1) return NULL;
        TreeNode * root = new TreeNode(postorder[postorder.size() - 1]);
        int i = 0;
        for (; i < inorder.size(); i++) {
            if (inorder[i] == root->val) {
                break;
            }
        }
        TreeNode * left = buildSubTree(inorder, 0, i, postorder, 0, i);
        TreeNode * right = buildSubTree(inorder, i + 1, inorder.size(), postorder, i, postorder.size() - 1);
        root->left = left;
        root->right = right;
        return root;
    }
    TreeNode * buildSubTree(vector<int>& inorder, int ileft, int iright, vector<int> & postorder, int pleft, int pright) {
        if (ileft >= iright) return NULL;
        TreeNode * root = new TreeNode(postorder[pright - 1]);
        if (ileft == iright - 1) return root;
        int i = ileft;
        for (; i < iright; i++) {
            if (inorder[i] == root->val) {
                break;
            }
        }
        int length = i - ileft;
        TreeNode * left = buildSubTree(inorder, ileft, i, postorder, pleft, pleft + length);
        TreeNode * right = buildSubTree(inorder, i + 1, iright, postorder, pleft + length, pright - 1);
        root->left = left;
        root->right = right;
        return root;
    }
};
