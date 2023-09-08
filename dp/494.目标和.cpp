/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
vector<vector<int>> dp;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = std::accumulate(nums.begin(),nums.end(),0);
        if(sum-target<0 || (sum-target)%2!=0) return 0;
        int new_target = (sum-target)/2;
        dp = vector<vector<int>>(n+1,vector<int>(new_target+1));
        //base case 
        for(int i=0;i<n+1;i++){
            dp[i][0] = 1;
        }
        //dp
        for(int i=1;i<n+1;i++){
            for(int j=0;j<new_target+1;j++){
                if(j-nums[i-1] < 0)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][new_target];
    }
};
// @lc code=end

