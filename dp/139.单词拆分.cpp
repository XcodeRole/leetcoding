/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
vector<int> memo;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        memo=vector<int>(s.size(),-1);
        return dp(s,0,wordDict);
    }
    bool dp(string s,int i, vector<string>& wordDict){
        if(i==s.size()) return true;
        if(memo[i]!=-1) return memo[i];
        bool isPrefix=false;
        for(string t:wordDict){
            if(s.substr(i,t.size())==t){
                isPrefix = isPrefix || dp(s,i+t.size(),wordDict);
            }
        }
        memo[i]=isPrefix?1:0;
        return isPrefix;
    }
    // bool isPrefix(string s,int i,string t){
    //     return s.substr(i,t.size())==t;
    // }
};
// @lc code=end

