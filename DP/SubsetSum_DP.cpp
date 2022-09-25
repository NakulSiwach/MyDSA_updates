//this below code is of equal partition (this uses subset sum)
class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int sum = accumulate(arr.begin(),arr.end(),0);
        if (sum%2!=0){
            return false;
        }
        int N = arr.size();
        
        bool dp[1001][(sum)+1];
        sum = sum/2;

        for(int i = 0 ; i <= sum;i++){
            dp[0][i] = false;
        }
        for(int i =0 ; i <= N;i++){
            dp[i][0] = true;
        }

        for(int i = 1 ; i <=N;i++){
            for(int j = 1 ; j <= sum;j++){
                if(j-arr[i-1]>=0){
                    dp[i][j] = dp[i-1][j] or dp[i-1][j-arr[i-1]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[N][sum];
    }
};



// recursion

// wrong codeeee

class Solution
{
    public:
    bool helper(int W,int val[], int n){
        if(W==0){
            return true;
        }
        if(n==0){
            return false;
        }

        if(W-val[n-1]>=0){
            return helper(W-val[n-1],val,n-1) or helper(W,val,n-1) ;
        }
        else{
            return helper(W,val,n-1);
        }
    }

    bool subset(int W,int val[], int n){ 
        return helper(W,wt,val,n);
    }
};

// memoized
class Solution
{
    public:
    bool helper(int W, int wt[], int val[], int n, int dp[1001][1001]){
        if(W==0){
            return true;
        }
        if(n==0){
            return false;
        }

        if(dp[n][W]!=-1){
            return dp[n][W];
        }

        if(W-wt[n-1]>=0){
            dp[n][W] =  helper(W-wt[n-1],wt,val,n-1,dp) or helper(W,wt,val,n-1,dp) ;
        }
        else{
            dp[n][W] =  helper(W,wt,val,n-1,dp);
        }
        return dp[n][W];
    }

    bool subset(int W, int wt[], int val[], int n){ 
        int dp[1001][1001];
        memset(dp,false,sizeof(dp));
        helper(W,wt,val,n,dp);
        return dp[n][W];
    }
};
