/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        //dp数组表示从左上角到当前格子的路径数，显然dp[i][j]=dp[i-1][j]+dp[i][j-1]
        vector<vector<int>> dp(m,vector<int>(n));
        //dp base，这个题中就是dp的边界
        int i;
        for(i=0;i<n;i++){
            if(obstacleGrid[0][i]==1) break;
            dp[0][i]=1;
        }
        for(;i<n;i++){
            dp[0][i]=0;
        }
        for(i=0;i<m;i++){
            if(obstacleGrid[i][0]==1) break;
            dp[i][0]=1;
        }
        for(;i<m;i++){
            dp[i][0]=0;
        }
        //自底向上更新dp数组
        for(i=1;i<m;i++){
            for(int j=1;j<n;j++){
                //无障碍物的时候dp[i][j]=dp[i-1][j]+dp[i][j-1]
                if(!obstacleGrid[i][j]){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                //有障碍物直接就是0，因为此路不通
                }else
                    dp[i][j]=0;
            }
        }
        return dp[m-1][n-1];
    }
};
// @lc code=end

