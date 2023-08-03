/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
vector<vector<int>> dp;
public:
    int longestCommonSubsequence(string text1, string text2) {
        dp = vector<vector<int>>(text1.size()+1,vector<int>(text2.size()+1));
        for(int i =1;i<=text1.size();i++){
            for(int j =1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};
// 暴力法剪枝
// Time Limit Exceeded
// 42/47 cases passed (N/A)

// class Solution {
// vector<vector<int>> memo;
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         memo = vector<vector<int>>(text1.size(),vector<int>(text2.size(),-1));
//         memo[0][0]=text1[0]==text2[0]?1:0;
//         return dp(text1,text1.size()-1,text2,text2.size()-1);
//     }
//     int dp(string text1,int i, string text2,int j){
//         if (i<0 || j<0) return 0;
//         if(memo[i][j]!=-1) 
//             return memo[i][j];
//         if(text1[i]==text2[j])
//             memo[i][j] = dp(text1,i-1,text2,j-1)+1;
//         else
//             memo[i][j] = max(dp(text1,i-1,text2,j),dp(text1,i,text2,j-1));
//         return memo[i][j];
//     }
// };
// @lc code=end

