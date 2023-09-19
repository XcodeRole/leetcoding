/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int i=0;
        for(int j=1;j<nums.size();j++){
            if(nums[i]==nums[j]){
                continue;
            }else{
                nums[++i] = nums[j];
            }
        }
        return i+1;
    }
};
// @lc code=end

