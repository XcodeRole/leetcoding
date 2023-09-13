/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
int NthFromEnd=1;
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node_pre;
        ListNode* node_next;
        getNthFromEnd(head,node_pre,node_next,n+1,n-1);
        if(NthFromEnd==n+1) return node_next;
        ListNode* cur = node_pre->next;
        node_pre->next = cur->next;
        delete(cur);
        return head;
    }
    void getNthFromEnd(ListNode* head,ListNode* &node_pre,ListNode* &node_next,int n1,int n2){
        if(n2==0) node_next=nullptr;
        if(!head) return;
        getNthFromEnd(head->next,node_pre,node_next,n1,n2);
        if(NthFromEnd==n1) node_pre = head;
        if(NthFromEnd==n2) node_next = head;
        NthFromEnd++;
    }
};
// @lc code=end

