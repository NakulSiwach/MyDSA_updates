
class Solution
{
    public:
    

    int helper(int W, int wt[], int val[], int n, int dp[][1001]){
        if (n==0 or W==0){
            return 0;
        }
        
        if (dp[n][W] != -1){
            return dp[n][W];
        }
        if (wt[n-1]<=W){
            dp[n][W] = max(helper(W,wt,val,n-1,dp),val[n-1]+helper(W-wt[n-1],wt,val,n-1,dp));
        }
        else{
            dp[n][W] = helper(W,wt,val,n-1,dp);
        }
        return dp[n][W];

    }

    int knapSack(int W, int wt[], int val[], int n) 
    {   
        int dp[1001][1001];
        memset(dp,-1,sizeof(dp));
        return helper(W,wt,val,n,dp);
    }
};
