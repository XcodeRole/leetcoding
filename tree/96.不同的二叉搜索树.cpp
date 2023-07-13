/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
/*
动态规划
Accepted
19/19 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 5.21 % of cpp submissions (6.2 MB)
*/
class Solution {
public:
    int numTrees(int n) {
        vector<vector<int>> count(n+2,vector<int>(n+2,1));
        for (int dis=1;dis<=n-1;dis++){
            for(int low=1;low<=n-1;low++){
                int res=0;
                int high=low+dis;
                if (high>n) continue;
                for(int i=low;i<=high;i++){
                    int left=count[low][i-1];
                    int right=count[i+1][high];
                    res+=left*right;
                }
                count[low][high]=res;
            }
        }
        return count[1][n];
    }
};

/*
Time Limit Exceeded
19/19 cases passed (N/A)
*/
// class Solution {
// public:
//     int numTrees(int n) {
//         return buildTrees(1,n);
//     }
//     int buildTrees(int low,int high){
//         if (low >= high)
//             return 1;
//         int res=0;
//         for (int i=low;i<=high;i++){
//             int left = buildTrees(low,i-1);
//             int rigth = buildTrees(i+1,high);
//             res+=left*rigth;
//         }
//         return res;
//     }
// };
// @lc code=end

