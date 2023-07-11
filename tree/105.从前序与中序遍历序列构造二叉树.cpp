/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int rootval = preorder.front();
		TreeNode *root = new TreeNode(rootval);
		auto target = find(inorder.begin(),inorder.end(),rootval);
		int leftcount = target - inorder.begin();
		int rightcount = inorder.end() - target -1 ;
		if (leftcount){
			vector<int> leftvector(preorder.begin()+1,preorder.end()-rightcount);
			vector<int> rightvector(inorder.begin(),target);
			root->left = buildTree(leftvector,rightvector);
		}
 			
		if (rightcount){
			vector<int> leftvector(preorder.end()-rightcount,preorder.end());
			vector<int> rightvector(target+1,inorder.end());
			root->right = buildTree(leftvector,rightvector);
		}
		return root;
    }
};
// @lc code=end

