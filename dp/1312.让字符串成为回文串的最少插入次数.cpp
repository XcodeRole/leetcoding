/*
 * @lc app=leetcode.cn id=1312 lang=cpp
 *
 * [1312] 让字符串成为回文串的最少插入次数
 */

// @lc code=start
class Solution {
//dp[i][j]代表s[(i-1)->(j-1)]成为回文串的最小操作次数
vector<vector<int>> dp;
public:
    int minInsertions(string s) {
        dp=vector<vector<int>>(s.size()+1,vector<int>(s.size()+1));
        //base case
        //这里就是i==j以及i>j都是0，由于vector初始化为0，所以base case已经设置好了

        //遍历dp数组，同516，dp[i]需要dp[i+1],所以i倒叙，j正序
        for(int i=s.size();i>0;i--){
            for(int j=i+1;j<s.size()+1;j++){
                if(s[i-1]==s[j-1]) dp[i][j]=dp[i+1][j-1];
                else dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;
            }
        }
        return dp[1][s.size()];
    }
};
//同516题
//暴力递归的剪枝算法
// class Solution {
// vector<vector<int>> memo;
// public:
//     int minInsertions(string s) {
//         memo=vector<vector<int>>(s.size(),vector<int>(s.size(),-1));
//         return dp(s,0,s.size()-1);
//     }
//     int dp(string s,int i,int j){
//         if(i>=j){
//             return 0;
//         }
//         if(memo[i][j]!=-1) return memo[i][j];
//         int res;
//         if(s[i]==s[j]){
//             res = dp(s,i+1,j-1);
//         }else{
//             res = min(dp(s,i+1,j),dp(s,i,j-1))+1;
//         }
//         memo[i][j]=res;
//         return res;
//     }
// };
// @lc code=end

