/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
//一开始我还想着用冒泡的办法，时间复杂度是O(n^2)，但是看了眼题解
// 原来可以直接将删除元素的办法应用过来，将数组中0删除，其他数移动到前面，然后后面全部赋值0就可以了
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int slow = 0;
        int fast = 0;
        while(fast<n){
            if(nums[fast]!=0){
                nums[slow++]=nums[fast++];
            }else{
                fast++;
            }
        }
        memset(nums.data()+slow,0,(n-slow)*sizeof(int));
    }
};
// @lc code=end

