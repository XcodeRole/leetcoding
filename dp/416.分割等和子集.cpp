/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
//突然想到，分割成等和的子集就相当于知道每一个子集的和，也就转化成了01背包问题
class Solution {
vector<vector<bool>> dp;
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = std::accumulate(nums.begin(),nums.end(),0);
        if (sum%2!=0) return false;
        sum = sum/2; 
        dp = vector<vector<bool>>(n+1,vector<bool>(sum+1,false));
        //base case
        //空集总是算作一种
        for(int i=0;i<n+1;i++){
            dp[i][0]=true;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(j-nums[i-1]>=0){
                    dp[i][j]=dp[i-1][j-nums[i-1]]||dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};
// @lc code=end

