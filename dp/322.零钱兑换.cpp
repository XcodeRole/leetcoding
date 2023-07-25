/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        dp[0]=0;
        for(int i=1;i<amount+1;i++){
            int res = numeric_limits<int>::max();
            for(int coin: coins){
                int index = i-coin;
                //下标越界或者是前者没有组合
                if (index < 0 || dp[index] == -1) continue;
                res = min(res,dp[index]+1);
            }
            //res还是int_max，那就是for循环中全continue了
            if (res==numeric_limits<int>::max())
                res=-1;
            dp[i]=res;
        }
        return dp[amount];
    }

};

//暴力法
// int dp(vector<int>& coins, int amount){
//     if (amount < 0) return -1;
//     if (amount ==0) return 0;
//     int res = numeric_limits<int>::max();
//     for (int coin : coins){
//         int sub = dp(coins,amount-coin);
//         if (sub == -1 ) continue;
//         res = min(res,sub+1);
//     }
//     return res;
// }
// @lc code=end

