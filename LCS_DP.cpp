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
class Solution {
public:
    int helper(string s1, string s2, int n, int m,int dp[1001][1001]){
        if(m==0 or n == 0){
            return 0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if (s1[n-1]==s2[m-1]){
            return dp[n][m] = 1 + helper(s1,s2,n-1,m-1,dp);
        }
        else{
            return dp[n][m] =  max(helper(s1,s2,n-1,m,dp),helper(s1,s2,n,m-1,dp));
        }
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        int dp[1001][1001];
        memset(dp,-1,sizeof(dp));
        return helper(s1,s2,n,m,dp);
    }
};

//tabulation
class Solution {
public:

    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        int dp[n+1][m+1];
        for(int i = 0 ; i <= n;i++){
            dp[i][0] = 0;
        }
        for(int i = 0 ; i <= m;i++){
            dp[0][i] = 0;
        }

        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];   
    }
};
