/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
string data="";
const char null='#';
const char sep=',';
int index=0;
vector<string> res;
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        traverse(root);
        // cout<<data<<endl;
        return data.substr(1,data.length());
    }

    void traverse(TreeNode* root){
        if (!root){
            data=data+sep+null;
            return ;
        }
        data=data+sep+to_string(root->val);
        traverse(root->left);
        traverse(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        split(data);
        return traverse(res); 
    }

    TreeNode* traverse(vector<string> data){
        string cur_val = data[index++];
        if(cur_val[0]==null){
            return nullptr;
        }
        // cout<<cur_val;
        TreeNode* cur = new TreeNode(stoi(cur_val));
        cur->left=traverse(data);
        cur->right=traverse(data);
        return cur;
    }
    void split(string data){
        // vector<string> res;
        stringstream ss(data);
        string token;
        while(getline(ss,token,sep)){
            res.push_back(token);
            // cout<<token<<endl;
        }
        // cout<<res.size();
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

