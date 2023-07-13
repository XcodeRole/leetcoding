/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (root->val==key){
            if(!root->left&&!root->right){
                delete root;
                return nullptr;
            }else if (root->right && root->left){
                TreeNode* maxNode = findmax(root->left);
                root->val=maxNode->val;
                root->left = deleteNode(root->left,maxNode->val);
                return root;
            }else{
                if( root->left)
                    return root->left;
                if (root->right)
                    return root->right;
            }
        }
        if (key < root->val){
            root->left = deleteNode(root->left,key);
        }else{
            root->right = deleteNode(root->right,key);
        }
        return root;
    }
    TreeNode* findmax(TreeNode* root){
        while(root->right){
            root=root->right;
        }
        return root;
    }
};
// @lc code=end

