/*
 * [99] Recover Binary Search Tree
 *
 * https://leetcode-cn.com/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Hard (43.09%)
 * Total Accepted:    873
 * Total Submissions: 2K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * 二叉搜索树中的两个节点被错误地交换。
 * 
 * 请在不改变其结构的情况下，恢复这棵树。
 * 
 * 示例 1:
 * 
 * 输入: [1,3,null,null,2]
 * 
 *   1
 *  /
 * 3
 *  \
 *   2
 * 
 * 输出: [3,1,null,null,2]
 * 
 *   3
 *  /
 * 1
 *  \
 *   2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,1,4,null,null,2]
 * 
 * ⁠  3
 *  ⁠/ \
 * 1   4
 *    /
 *   2
 * 
 * 输出: [2,1,4,null,null,3]
 * 
 * ⁠  2
 *  ⁠/ \
 * 1   4
 *    /
 *  ⁠ 3
 * 
 * 进阶:
 * 
 * 
 * 使用 O(n) 空间复杂度的解法很容易实现。
 * 你能想出一个只使用常数空间的解决方案吗？
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
class Solution
{
  public:
    TreeNode *pre = new TreeNode(0x80000000), *p1 = NULL, *p2 = NULL;
    void In_Traver(TreeNode *root)
    {
        if (root->left)
            In_Traver(root->left);
        if (root->val < pre->val && !p1)
            p1 = pre;
        if (p1 && root->val < p1->val)
            p2 = root;
        pre = root;
        if (root->right)
            In_Traver(root->right);
    }
    void recoverTree(TreeNode *root)
    {
        In_Traver(root);
        swap(p1->val, p2->val);
    }
};
