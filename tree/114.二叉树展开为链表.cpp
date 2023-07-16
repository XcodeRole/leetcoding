/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
//先序非递归遍历
//分解子问题
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* cur=root->left;
        if (cur){
            TreeNode* tmp=root->right;
            root->right=cur;
            while( cur->right){
                cur=cur->right;
            }
            cur->right=tmp;
            root->left=nullptr;
        }
    }
};
// @lc code=end

