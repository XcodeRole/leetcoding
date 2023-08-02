/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
vector<vector<int>> memo;
public:
    int minDistance(string word1, string word2) {
        memo = vector<vector<int>>(word1.size()+1,vector<int>(word2.size()+1,-1));
        return dp(word1,0,word2,0);

    }

    int dp(string word1,int i,string word2,int j){
        if(memo[i][j]!=-1) return memo[i][j];
        if(i==word1.size()&&j==word2.size())
            return 0;
        int res;
        //word1到头，但是word2没到头，只能向word1中插入
        if (i==word1.size()){
            res=dp(word1,i,word2,j+1)+1;
        //word2到头，但是word1没到头，只能从word1中删除
        }else if(j==word2.size()){
            res=dp(word1,i+1,word2,j)+1;
        //word1，word2都没到头
        }else{
            if(word1[i]==word2[j]){
                res = dp(word1,i+1,word2,j+1);
            }else{
                res = min(
                    min(
                        //替换
                        dp(word1,i+1,word2,j+1)+1,
                        //删除
                        dp(word1,i+1,word2,j)+1
                    ),
                    //插入
                    dp(word1,i,word2,j+1)+1
                );
            }
        }
        memo[i][j]=res;
        return res;
    }
};
// @lc code=end

