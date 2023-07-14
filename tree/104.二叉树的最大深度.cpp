/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
//1.层序遍历记录深度
//2.非递归后序遍历栈的最大深度
//3.先序遍历，记录每个节点深度
//4.后续遍历，max(left+right)+1
class Solution {
int depth=0;//当前节点深度
int res=0;//最大深度
public:
    int maxDepth(TreeNode* root) {
        tranverse(root);
        return res;
    }

    void tranverse(TreeNode* root){
        if (!root) return;
        depth++;
        if (!root->left && !root->right){
            res=max(res,depth);
        }
        tranverse(root->left);
        tranverse(root->right);
        depth--;
    }
};
// @lc code=end

