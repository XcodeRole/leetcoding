/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

// @lc code=start
class Solution {
vector<vector<int>> memo;
int maxInt = std::numeric_limits<int>::max();
int m,n;
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();
        memo = vector<vector<int>>(m,vector<int>(n,maxInt));
        memo[m-1][n-1]=dungeon[m-1][n-1]>=0?1:1-dungeon[m-1][n-1];
        return dp(0,0,dungeon);
    }
    int dp(int i,int j,vector<vector<int>>& dungeon){
        if(memo[i][j]!=maxInt)
            return memo[i][j];
        if(i==m-1){
            int res = dp(i,j+1,dungeon)-dungeon[i][j]<=0?1:dp(i,j+1,dungeon)-dungeon[i][j];
            memo[i][j]=res;
            return res;
        }
        if(j==n-1){
            int res = dp(i+1,j,dungeon)-dungeon[i][j]<=0?1:dp(i+1,j,dungeon)-dungeon[i][j];
            memo[i][j]=res;
            return res;
        }
        int res = min(dp(i,j+1,dungeon)-dungeon[i][j]<=0?1:dp(i,j+1,dungeon)-dungeon[i][j],dp(i+1,j,dungeon)-dungeon[i][j]<=0?1:dp(i+1,j,dungeon)-dungeon[i][j]);
        memo[i][j]=res;
        return res;
    }
};
// class Solution {
// vector<vector<pair<int,int>>> memo;
// int maxInt = std::numeric_limits<int>::max();
// pair<int,int> maxPair = make_pair(maxInt,maxInt);
// public:
//     int calculateMinimumHP(vector<vector<int>>& dungeon) {
//         int m = dungeon.size();
//         int n = dungeon[0].size();
//         memo = vector<vector<pair<int,int>>>(m,vector<pair<int,int>>(n,maxPair));
//         memo[0][0] = make_pair(dungeon[0][0],dungeon[0][0]);
//         pair<int,int> res = dp(m-1,n-1,dungeon);
//         return 1+abs(res.second);
//     }
//     pair<int,int> dp(int i,int j,vector<vector<int>>& dungeon){
//         if(memo[i][j]!=maxPair) return memo[i][j];
//         //base case
//         if(i==0){
//             pair<int,int> tmp = dp(0,j-1,dungeon);
//             int f_p = tmp.first;
//             int s_p = tmp.second;
//             int f_c = f_p + dungeon[i][j];
//             int s_c = min(s_p,f_c);
//             return make_pair(f_c,s_c);

//         }
//         if(j==0){
//             pair<int,int> tmp = dp(i-1,0,dungeon);
//             int f_p = tmp.first;
//             int s_p = tmp.second;
//             int f_c = f_p + dungeon[i][j];
//             int s_c = min(s_p,f_c);
//             return make_pair(f_c,s_c);
//         }
//         // int res = min(dp(i-1,j,grid),dp(i,j-1,grid))+grid[i][j];
//         pair<int,int> up = dp(i-1,j,dungeon);
//         pair<int,int> left = dp(i,j-1,dungeon);
//         pair<int,int> res;
//         if (up.first > left.first){
//             res = make_pair(up.first+dungeon[i][j],min(up.first+dungeon[i][j],up.second));
//         }else{
//             res = make_pair(left.first+dungeon[i][j],min(left.first+dungeon[i][j],left.second));
//         }
//         memo[i][j]=res;
//         return res;
//     }
// };
// @lc code=end

