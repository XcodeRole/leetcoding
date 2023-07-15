/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
//首先一定是叶子节点之间的长度，一定有公共祖先节点，所以就是两个叶子节点到公共祖先的路径和最大
//考虑分治法，当前节点的子树最大=max(leftres,rightres,leftdepth+rightdepth+1),考虑后序遍历
class Solution {
pair<int,int> depth_res;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        auto res = traverse(root);
        return res.second-1;
    }
    pair<int,int> traverse(TreeNode* root){
        if (!root)
            return make_pair(0,0);
        auto left_res=traverse(root->left);
        auto right_res=traverse(root->right);
        int res = max(max(left_res.second,right_res.second),left_res.first+right_res.first+1);
        int depth = max(left_res.first,right_res.first)+1;
        return make_pair(depth,res);
    }
};
// @lc code=end

