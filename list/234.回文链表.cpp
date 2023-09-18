/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        vector<int> data;
        while(fast && fast->next){
            data.push_back(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast) slow = slow->next;
        int i = data.size()-1;
        while(slow){
            if(slow->val!=data[i--]) return false;
            slow = slow->next;
        }
        return true;
    }
};
// @lc code=end

