class Solution {
public:
    void helper(vector<int>nums,vector<vector<int>>&ans,int n){
        if (n==nums.size()){
            ans.push_back(nums);
        }
        for (int i = n ; i < nums.size();i++){
            swap(nums[i],nums[n]);
            helper(nums,ans,n+1);
            swap(nums[i],nums[n]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        helper(nums,ans,0);
        return ans;
    }
};
