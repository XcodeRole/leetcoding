/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
class Solution {
map<int,int> value_index;
public:
    vector<int> countSmaller(vector<int>& nums) {
        // vector<int> res(nums.size());
        // for(int i=nums.size();i>0;i--){
        //     for(int j=0;j<i-1;j++){
        //         if (nums[j]>nums[i-1]){
        //             res[j]++;
        //         }
        //     }
        // }
        // return res;
        vector<int> res(nums.size());
        for(int i=0;i<nums.size();i++){
            value_index[nums[i]]=0;
        }
        vector<int> count(value_index.size());
        int i=0;
        for(auto it=value_index.begin();it!=value_index.end();it++,i++){
            it->second=i;
        }
        for(int i=nums.size();i>0;i--){
            count[value_index[nums[i-1]]]++;
            res[i-1]=prefix(count,value_index[nums[i-1]]);
        }
        return res;
    }
    int prefix(vector<int>& array,int k){
        int res=0;
        for(int i=0;i<k;i++){
            res+=array[i];
        }
        return res;
    }

};
// @lc code=end

