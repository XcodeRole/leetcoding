/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */

// @lc code=start
class Solution {
unordered_map<int,vector<string>> memo;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        return dp(s,0,wordDict);
    }

    vector<string> dp(string s,int i, vector<string>& wordDict){
        if(i>=s.size()) return {""};
        auto it = memo.find(i);
        if(it!=memo.end())
            return memo[i];
        memo[i]={};
        for(string t:wordDict){
            if(s.substr(i,t.size())==t){
                vector<string> res = dp(s,i+t.size(),wordDict);
                for(string &s:res){
                    memo[i].push_back(s.empty()?t:t+" "+s);
                }
            }
        }
        return memo[i];
    }


};
// @lc code=end

