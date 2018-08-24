/*
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (41.90%)
 * Total Accepted:    991
 * Total Submissions: 2.4K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * 解释:
 * 以上的输出对应以下 5 种不同结构的二叉搜索树：
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
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
// #include <vector>
// using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return getTreeNode(1, n);
    }
    vector<TreeNode*> getTreeNode(int min, int max) {
        vector<TreeNode*> result;
        if (min > max) return result;
        
        for (int i = min; i <= max; i++) {
            vector<TreeNode*> left = getTreeNode(min, i - 1);
            vector<TreeNode*> right = getTreeNode(i + 1, max);
            if (left.size() < 1 && right.size() < 1) {
                TreeNode* root = new TreeNode(i);
                result.push_back(root);
            } else if (left.size() < 1 && right.size() > 0) {
                for (int k = 0; k < right.size(); k++) {
                    TreeNode* root = new TreeNode(i);
                    root->right = right[k];
                    result.push_back(root);
                }
            } else if (left.size() > 0 && right.size() < 1) {
                for (int j = 0; j < left.size(); j++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    result.push_back(root);
                }
            } else {
                for (int j = 0; j < left.size(); j++) {
                    for (int k = 0; k < right.size(); k++) {
                        TreeNode* root = new TreeNode(i);
                        root->left = left[j];
                        root->right = right[k];
                        result.push_back(root);
                    }
                }
            }
        }
        return result;
    }
};
