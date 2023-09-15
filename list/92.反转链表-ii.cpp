/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
vector<ListNode*> stack;
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* cur = head;
        ListNode* pre = nullptr;
        for(int i=1;i<=right;i++){
            if(i==left-1) pre = cur;
            if(i>=left){
                stack.push_back(cur);
            }
            cur = cur->next;
        }
        ListNode* ne = cur;
        ListNode* fakehead = new ListNode(0);
        cur = fakehead;
        while(!stack.empty()){
            cur->next = stack.back();
            stack.pop_back();
            cur = cur->next;
        }
        cur->next = ne;
        if(pre) {
            pre->next = fakehead->next;
            delete (fakehead);
            return head;
        }else{
            return fakehead->next;
        }
    }
};
// @lc code=end

