/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
vector<int> memo;
int min_int = std::numeric_limits<int>::min();
public:
    int maxSubArray(vector<int>& nums) {
        memo = vector<int>(nums.size(),min_int);
        dp(nums,nums.size()-1);
        return *max_element(memo.begin(),memo.end());
    }
    void dp(vector<int>& nums,int i){
        if(i==0) {memo[i] = nums[0]; return;}
        if(memo[i]!=min_int) return;
        dp(nums,i-1);
        int premax = memo[i-1];
        if (premax<0){
            memo[i] = nums[i];
        }else{
            memo[i] = nums[i]+ premax;
        }
    }
};
// @lc code=end

