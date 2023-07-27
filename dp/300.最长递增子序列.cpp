/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
//https://labuladong.github.io/algo/di-er-zhan-a01c6/dong-tai-g-a223e/dong-tai-g-6ea57/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            int curnum = nums[i];
            int res=1;
            for(int j=i-1;j>=0;j--){
                if (nums[j]<nums[i])
                    res=max(res,dp[j]+1);
            }
            dp[i]=res;
        }
        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end

