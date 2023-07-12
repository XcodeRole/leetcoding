/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    vector<TreeNode *> stack;
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        TreeNode *curNode=root;
        while(curNode || stack.size()!=0){
            while(curNode){
                stack.push_back(curNode);
                curNode=curNode->left;
            }
            //visit
            curNode=stack.back();
            stack.pop_back();
            if(++count==k)
                return curNode->val;
            curNode=curNode->right;
        }
        return -1;
    }
};
// @lc code=end

