/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* less_head = nullptr;
        ListNode* less_tail = nullptr;
        ListNode* bigger_head = nullptr;
        ListNode* bigger_tail = nullptr;
        ListNode* cur = head;
        while(cur){
            if(cur->val<x){
                if(less_tail){
                    less_tail->next=cur;
                    less_tail = cur;
                }else{
                    less_tail=cur;
                    less_head=cur;
                }
            }else{
                if(bigger_tail){
                    bigger_tail->next=cur;
                    bigger_tail = cur;
                }else{
                    bigger_tail=cur;
                    bigger_head=cur;
                }
            }
            cur = cur->next;
        }
        if(less_tail)
            less_tail->next = bigger_head;
        if(bigger_tail)
            bigger_tail->next = nullptr;
        return less_head==nullptr?bigger_head:less_head;
    }
};
// @lc code=end

