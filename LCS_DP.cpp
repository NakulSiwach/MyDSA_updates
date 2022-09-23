// recursion
class Solution {
public:
    int helper(string s1, string s2, int n, int m){
        if(m==0 or n == 0){
            return 0;
        }
        if (s1[n-1]==s2[m-1]){
            return 1 + helper(s1,s2,n-1,m-1);
        }
        else{
            return max(helper(s1,s2,n-1,m),helper(s1,s2,n,m-1));
        }
    }
    int longestCommonSubsequence(string s1, string s2) {
        
        return helper(s1,s2,s1.size(),s2.size());
    }
};


// memoized
