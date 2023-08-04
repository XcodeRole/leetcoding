/*
 * @lc app=leetcode.cn id=712 lang=cpp
 *
 * [712] 两个字符串的最小ASCII删除和
 */

// @lc code=start
//使用dp数组，自底向上
class Solution {
vector<vector<int>> dp;
public:
    int minimumDeleteSum(string s1, string s2) {
        dp = vector<vector<int>>(s1.size()+1,vector<int>(s2.size()+1));
        //dp[0][0]=0;
        //base case
        for(int i=1;i<=s1.size();i++){
            dp[i][0]=dp[i-1][0]+int(s1[i-1]);
        }
        for(int j=1;j<=s2.size();j++){
            dp[0][j]=dp[0][j-1]+int(s2[j-1]);
        }
        //自底向上填充dp
        for(int i=1;i<=s1.size();i++){
            for(int j=1;j<=s2.size();j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=min(dp[i-1][j]+int(s1[i-1]),dp[i][j-1]+int(s2[j-1]));
            }
        }
        return dp[s1.size()][s2.size()];
    }
};
//(其实和1143.最长公共子序列，583.两个字符串的删除操作是一个题)
//使用暴力递归的剪枝法（自顶向下），超时
/*
Time Limit Exceeded
78/93 cases passed (N/A)
*/
// class Solution {
// vector<vector<int>> memo;
// public:
//     int minimumDeleteSum(string s1, string s2) {
//         memo = vector<vector<int>>(s1.size(),vector<int>(s2.size(),-1));
//         return dp(s1,s1.size()-1,s2,s2.size()-1);
//     }
//     int dp(string s1,int i, string s2,int j){
//         if(i==-1){
//             int res = 0;
//             for(;j>-1;j--){
//                 res+=int(s2[j]);
//             }
//             return res;
//         }
//         if(j==-1){
//             int res = 0;
//             for(;i>-1;i--){
//                 res+=int(s1[i]);
//             }
//             return res;
//         }
//         if(memo[i][j]!=-1){
//             return memo[i][j];
//         }
//         int res;
//         if(s1[i]==s2[j]){
//             res = dp(s1,i-1,s2,j-1);
//         }else{
//             res = min(dp(s1,i,s2,j-1)+int(s2[j]),dp(s1,i-1,s2,j)+int(s1[i]));
//         }
//         memo[i][j]=res;
//         return res;
//     }
// };
// @lc code=end

