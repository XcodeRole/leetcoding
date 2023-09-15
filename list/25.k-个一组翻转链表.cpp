/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur_all = head;
        ListNode* cur_sec = new ListNode();
        ListNode* newhead;
        bool initial = false;
        while(cur_all){
            for(int i=0;i<k && cur_all!=nullptr ;i++){
                if(i==k-1 && !initial) {newhead = cur_all; initial = true;}
                stack.push_back(cur_all);
                cur_all = cur_all->next;
            }
            if(stack.size()<k){
                for(int i=0;i<stack.size();i++){
                    cur_sec->next =stack[i];
                    cur_sec = cur_sec->next;
                }
                break;
            }
            while(!stack.empty()){
                cur_sec->next = stack.back();
                stack.pop_back();
                cur_sec = cur_sec->next;
            }
            cur_sec->next = cur_all;
        }
        return newhead;
    }
};
// @lc code=end

