/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA;
        ListNode *curB = headB;
        while(curA!=curB){
            if(curA)
                curA = curA->next;
            else
                curA = headB;
            if(curB)
                curB = curB->next;
            else
                curB = headA;
        }
        return curA;
    }
};
// @lc code=end

