/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=0;i<n;i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int rowid = i-1;
                int colid_left = max(0,j-1);
                int colid_right = min(n-1,j+1);
                dp[i][j]=min(min(dp[rowid][colid_left],dp[rowid][j]),dp[rowid][colid_right])+matrix[i][j];
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};
// @lc code=end

