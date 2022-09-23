// this is Longest Common Substring (not subsequence)
 
class Solution {
public:
    int longestCommonSubstr(string s1, string s2, int n, int m) {
        int dp[n+1][m+1];
        for(int i = 0 ; i < n;i++){
            dp[i][0] = 0;
            dp[0][i] = 0;
        }
        memset(dp,0,sizeof(dp));
        int totalmax=0;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 0;
                }
                totalmax = max(totalmax,dp[i][j]);
            }
        }

        return totalmax;
    }
};
