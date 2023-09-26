/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
//动态规划法
// class Solution {
// vector<vector<bool>> dp;
// public:
//     string longestPalindrome(string s) {
//         int n = s.size();
//         if(n==0|| n==1){
//             return s;
//         }
//         int maxLen = 0;
//         string res ;
//         dp = vector<vector<bool>>(n,vector<bool>(n,false));
//         //base case 
//         for(int i=0;i<n;i++){
//             dp[i][i]=true;
//         }
//         //dp
//         for(int i=n-1;i>=0;i--){
//             for(int j=i;j<n;j++){
//                 if(i<j){
//                     if(i+1<j-1)
//                         dp[i][j] = dp[i+1][j-1]&&(s[i]==s[j]);
//                     else
//                         dp[i][j] = (s[i]==s[j]);
//                 } 
//                 if(dp[i][j]&&j-i+1>maxLen){
//                     maxLen = j-i+1;
//                     res = s.substr(i,maxLen);
//                 }
//             }
//         }
//         return res;
//     }
// };

//暴力双指针法
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==0 || s.size()==1) return s;
        string res=""; 
        for(int i=0;i<s.size()-1;i++){
            string s1 = Palindrome(i,i,s);
            string s2 = Palindrome(i,i+1,s);
            res = s1.size()>res.size()?s1:res;
            res = s2.size()>res.size()?s2:res;
        }
        return res;
    }

    string Palindrome(int l,int r,string s){
        while(l>=0 && r<s.size() &&s[l]==s[r]){
            l--;
            r++;
        }
        return s.substr(l+1,r-l-1);
    }
};
// @lc code=end

