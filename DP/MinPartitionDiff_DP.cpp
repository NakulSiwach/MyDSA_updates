// uses subset sum dp table to find out all possible sums of all subsets.(last row)

class Solution{

  public:
	int minDifference(int nums[],int n) {
        int sum = accumulate(nums,nums+n,0);
        bool dp[n+1][sum+1];
        for(int i =0 ; i < sum+1;i++){
            dp[0][i] = false;
        }
        for(int i =0 ; i < n+1;i++){
            dp[i][0] = true;
        }

        for(int i =1;i <=n ; i++){
            for(int j = 1; j<=sum;j++){
                if(j-nums[i-1]>=0){
                    dp[i][j] = dp[i-1][j] or dp[i-1][j-nums[i-1]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        vector<int>a;
        for(int i = 0 ; i <=sum/2;i++){
            if (dp[n][i] == true){
                a.push_back(i);
            }
        }
        int x = a[a.size()-1];
        return sum-x-x;

    }
};
