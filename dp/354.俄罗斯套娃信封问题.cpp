/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[](vector<int>& a,vector<int>& b){
            if(a[0]<b[0])
                return true;
            else if(a[0]==b[0]){
                return a[1]>b[1];
            }else
                return false;
        });
        vector<int> dp(envelopes.size(),1);
        for(int i=1;i<envelopes.size();i++){
            int res=1;
            for(int j=i-1;j>=0;j--){
                if(envelopes[j][1]<envelopes[i][1])
                    res=max(res,dp[j]+1);
            }
            dp[i]=res;
        }
        return *max_element(dp.begin(),dp.end());
    }

};
// @lc code=end

