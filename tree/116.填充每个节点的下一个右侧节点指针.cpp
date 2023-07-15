/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
//层序遍历
class Solution {
list<Node*> layerqueue;
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        layerqueue.push_back(root);
        while(layerqueue.size()!=0){
            int len = layerqueue.size();
            //先出队列第一个节点,然后把左右节点入队列
            Node* cur = layerqueue.back();
            Node *nextNode=nullptr;
            layerqueue.pop_back();
            if(cur->left)
                layerqueue.push_front(cur->left);
            if(cur->right)
                layerqueue.push_front(cur->right);
            for(int i=0;i<len-1;i++){
            // while(layerqueue.size()!=0){
                nextNode = layerqueue.back();
                layerqueue.pop_back();
                if(nextNode->left)
                    layerqueue.push_front(nextNode->left);
                if(nextNode->right)
                    layerqueue.push_front(nextNode->right);
                cur->next=nextNode;
                cur=nextNode;
            // }
            }
            cur->next=nullptr;
        }
        return root;
    }
};
// @lc code=end

