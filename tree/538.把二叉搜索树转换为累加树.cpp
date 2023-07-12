/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
//同230题，使用栈非递归遍历runtime应该会更优
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        inorder(root,sum);
        return root;
    }
    void inorder(TreeNode* root,int& sum){
        if (root){
            inorder(root->right,sum);
            sum+=root->val;
            root->val=sum;
            inorder(root->left,sum);
        }
    }

};
// @lc code=end

