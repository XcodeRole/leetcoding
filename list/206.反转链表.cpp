/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
ListNode* newhead;
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next=nullptr;
        return last;
    }
};
// 我的笨拙实现
// class Solution {
// ListNode* newhead;
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(!head) return head;
//         reverseOp(head);
//         return newhead;
//     }
//     ListNode* reverseOp(ListNode* head){
//         if(!head->next){
//             newhead = head;
//             return head;
//         }
//         ListNode* pre = reverseOp(head->next);
//         pre->next = head;
//         head->next =nullptr;
//         return head;
//     }
// };
// @lc code=end

