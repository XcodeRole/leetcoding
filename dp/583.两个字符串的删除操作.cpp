/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
//经典暴力递归求解的剪枝，使用备忘录memo记录状态
class Solution {
vector<vector<int>> memo;
public:
    int minDistance(string word1, string word2) {
        memo = vector<vector<int>>(word1.size(),vector<int>(word2.size(),-1));
        return dp(word1,word1.size()-1,word2,word2.size()-1);
    }

    int dp(string word1,int i, string word2,int j){
        if(i==-1) return j+1;
        if(j==-1) return i+1;
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        int res;
        if(word1[i]==word2[j]){
            res = dp(word1,i-1,word2,j-1);
        }else{
            res = min(dp(word1,i,word2,j-1),dp(word1,i-1,word2,j))+1;
        }
        memo[i][j]=res;
        return res;
    }
};
// @lc code=end

