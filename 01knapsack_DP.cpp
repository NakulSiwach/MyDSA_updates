
// top-down (memoized)
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


// bottom-up (tabulation)

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       int dp[n+1][W+1];
       for(int i =0 ; i<n+1;i++){
        for(int j =0 ;j<W+1;j++){
            if(i==0 or j==0){
                dp[i][j] = 0;
            }
        }
       }

       for(int i =1 ; i<n+1;i++){
        for(int j =1 ;j<W+1;j++){
            if(wt[i-1]-j<=0){
                dp[i][j] = max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
       }
       return dp[n][W];

    }
};



