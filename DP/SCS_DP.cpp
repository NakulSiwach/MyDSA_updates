// length of shortest common supersequence.
// return n+m-(length of LCS of both).

class Solution
{
    public:
    int shortestCommonSupersequence(string x, string y, int n, int m){
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i = 1; i <=n ; i++ ){
            for(int j = 1;j<=m;j++){
                if(x[i-1]==y[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        int lcs = dp[n][m];
        int ans = m+n-lcs;
        return ans;
        
    }
};
