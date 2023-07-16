/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root =  traverse(nums,0,nums.size());
        return root;
    }
    TreeNode* traverse(vector<int>& nums,int beg,int end){
        if (beg >= end) return nullptr;
        auto maxiter = max_element(nums.begin()+beg,nums.begin()+end);
        int maxnum = *maxiter;
        int pos = distance(nums.begin(),maxiter);
        TreeNode* root = new TreeNode(maxnum);
        root->left = traverse(nums,beg,pos);
        root->right = traverse(nums,pos+1,end);
        return root;
    }
};
// @lc code=end

