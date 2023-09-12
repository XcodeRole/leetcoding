/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
unordered_set<ListNode*> visited;
public:
    bool hasCycle(ListNode *head) {
        while(head){
            if(visited.find(head)!=visited.end()) return true;
            visited.insert(head);
            head = head->next;
        }
        return false;
    }
};
// @lc code=end

