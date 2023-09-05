/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
class Solution {
vector<vector<int>> dp;
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp = vector<vector<int>>(n+1,vector<int>(amount+1));
        //base case
        for(int i=0;i<n+1;i++){
            dp[i][0]=1;
        }
        // for(int j=0;j<amount+1;j++){
        //     dp[0][j]=0; 
        // }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<amount+1;j++){
                int pre_a = j-coins[i-1];
                if(pre_a >= 0){
                    dp[i][j]=dp[i][pre_a]+dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][amount];
    }
};
// @lc code=end

