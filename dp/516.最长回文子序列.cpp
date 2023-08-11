/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
class Solution {
//dp[i][j]代表s[(i-1)->(j-1)]的最长回文子序列长度
vector<vector<int>> dp;
public:
    int longestPalindromeSubseq(string s) {
        dp=vector<vector<int>>(s.size()+1,vector<int>(s.size()+1));
        // base case
        for(int i=1;i<s.size()+1;i++){
            dp[i][i]=1;
        }
        //dp
        //这里有一个坑，要注意dp[i][j]=dp[i+1][j-1]+2，这种递推公式是从i+1推i，所以遍历i要倒着遍历，然后j是从j-1->j，所以j正序遍历
        for(int i=s.size();i>0;i--){
            for(int j=i+1;j<s.size()+1;j++){
                if(s[i-1]==s[j-1]) dp[i][j]=dp[i+1][j-1]+2;
                else dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
            }
        }
        return dp[1][s.size()];
    }
};
//暴力递归算法的剪枝
/*
Memory Limit Exceeded
71/86 cases passed (N/A)
*/

// class Solution {
// vector<vector<int>> memo;
// public:
//     int longestPalindromeSubseq(string s) {
//         memo=vector<vector<int>>(s.size(),vector<int>(s.size(),-1));
//         return dp(s,0,s.size()-1);
//     }

//     int dp(string s,int i,int j){
//         if(i>j) return 0;
//         if(i==j) return 1;
//         if(memo[i][j]!=-1) return memo[i][j];
//         int res;
//         if(s[i]==s[j]) res = dp(s,i+1,j-1)+2;
//         else res = max(dp(s,i,j-1),dp(s,i+1,j));
//         memo[i][j]=res;
//         return res;
//     }
// };
// @lc code=end

