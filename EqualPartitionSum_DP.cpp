// bottom-up
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


// top down (not working)
class Solution{
public:
    bool helper(int n,int arr[],int sum,int dp[][1001]){
        if (sum==0){
            return true;
        }
        if(n==0){
            return false;
        }
        if(dp[n][sum]!=NULL){
            return dp[n][sum];
        }
        if(sum-arr[n-1]>=0){
            dp[n][sum] = helper(n-1,arr,sum,dp) or helper(n-1,arr,sum-arr[n-1],dp);
        }
        else{
             dp[n][sum] = helper(n-1,arr,sum,dp);
        }
        return dp[n][sum];

    }

    int equalPartition(int N, int arr[]){
        int sum = accumulate(arr,arr+N,0);
        if (sum%2!=0){
            return false;
        }
        int dp[1001][1001];
        memset(dp,NULL,sizeof(dp));
        helper(N,arr,sum/2,dp);
        return dp[N][sum/2];
        
    }
};
