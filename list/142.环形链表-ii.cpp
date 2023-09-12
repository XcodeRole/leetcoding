/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        while(head){
            if(visited.find(head)!=visited.end()) return head;
            visited.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};
// @lc code=end

