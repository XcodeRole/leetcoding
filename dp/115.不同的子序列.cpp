/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
vector<vector<int>> memo;
public:
    int numDistinct(string s, string t) {
        memo=vector<vector<int>>(s.size(),vector<int>(t.size(),-1));
        return dp(s,0,t,0);
    }

    int dp(string s,int i,string t,int j){
        //base case
        if(j>=t.length()) return 1;
        if(s.length()-i<t.length()-j) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        int res;
        if(s[i]!=t[j]){
            res = dp(s,i+1,t,j);
        }else{
            res = dp(s,i+1,t,j+1)+dp(s,i+1,t,j);
        }
        memo[i][j]=res;
        return res;
    }
};
// @lc code=end

