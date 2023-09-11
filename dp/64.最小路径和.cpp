/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
vector<vector<int>> memo;
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memo = vector<vector<int>>(m,vector<int>(n,-1));
        memo[0][0]=grid[0][0];
        return dp(m-1,n-1,grid);
    }
    int dp(int i,int j,vector<vector<int>>& grid){
        //memo[0][0] & history
        if(memo[i][j]!=-1) return memo[i][j];
        //base case
        if(i==0){
            return dp(0,j-1,grid)+grid[0][j];
        }
        if(j==0){
            return dp(i-1,0,grid)+grid[i][0];
        }
        int res = min(dp(i-1,j,grid),dp(i,j-1,grid))+grid[i][j];
        memo[i][j]=res;
        return res;
    }
};
// @lc code=end

