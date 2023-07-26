/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        vector<int> fibnum(n+1);
        return dp(fibnum,n);
    }
    int dp(vector<int> &fibnum,int n){
        if(n==0) return 0;
        if(n==1) return 1;
        if (fibnum[n]!=0) return fibnum[n];
        return dp(fibnum,n-1)+dp(fibnum,n-2);
    }
};
// @lc code=end

