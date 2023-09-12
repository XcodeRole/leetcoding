/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
unordered_map<int,ListNode*> visited;
public:
    ListNode* middleNode(ListNode* head) {
        int nodeId = 0;
        while(head){
            visited[nodeId] = head;
            head = head->next;
            nodeId++;
        }
        return visited[nodeId/2];
    }
};
// @lc code=end

