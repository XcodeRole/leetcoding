/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//最直观的方法是直接用栈非递归中序遍历，判断是不是递增即可
//这里尝试用递归的方式，参照的labuladong解法
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root,nullptr,nullptr);
    }
    //先序遍历，思路是将当前数的根节点以上界或下界的方式传递给子树，
    //比如当前root是左子树的上界，是右子树的下界
    bool isValid(TreeNode* root,TreeNode* min,TreeNode* max){
        if (!root) return true;
        if (max && root->val >= max->val) return false;
        if (min && root->val <= min->val) return false;
        return isValid(root->left,min,root)&&isValid(root->right,root,max);
    }
};
// @lc code=end

