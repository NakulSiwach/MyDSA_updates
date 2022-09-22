class Solution
{
    public:
    bool helper(int W, int wt[], int val[], int n){
        if(W==0){
            return true;
        }
        if(n==0){
            return false;
        }

        if(W-wt[n-1]>=0){
            return helper(W-wt[n-1],wt,val,n-1) or helper(W,wt,val,n-1) ;
        }
        else{
            return helper(W,wt,val,n-1);
        }
    }

    bool subset(int W, int wt[], int val[], int n){ 
        return helper(W,wt,val,n);
    }
};
