/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
private:
    unordered_map<int,int> index_map;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int it=0;it<inorder.size();it++){
            index_map[inorder[it]]=it;
        }
        return build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }

    TreeNode *build(vector<int>& inorder, int startin,int lastin,vector<int>& postorder,int startpost,int lastpost){
        int rootval=postorder[lastpost];
        TreeNode *root=new TreeNode(rootval);
        int index=index_map[rootval];
        int leftcount = index - startin;
        int rightcount = lastin - index;
        if( leftcount )
            root->left=build(inorder,startin,index-1,postorder,startpost,startpost+leftcount-1);
        if (rightcount)
            root->right=build(inorder,index+1,lastin,postorder,startpost+leftcount,lastpost-1);
        return root;
    }
};
// @lc code=end

