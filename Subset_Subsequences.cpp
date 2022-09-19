
//Subsets

class Solution {
public:
    void helper(vector<int>&nums, vector<int>output, int n, vector<vector<int>>&ans){
        if(n==nums.size()){
            ans.push_back(output);
            return;
        }
        helper(nums,output,n+1,ans);
        output.push_back(nums[n]);
        helper(nums,output,n+1,ans);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int> output;
        helper(nums,output,0,ans);
        return ans;
    }
};


//Subsequence

#include <bits/stdc++.h> 

void helper(string nums, string output, int n, vector<string>&ans){
        if(n==nums.size()){
            if(output.size()>0){
                ans.push_back(output);
            }
           
            return;
        }
        helper(nums,output,n+1,ans);
        output.push_back(nums[n]);
        helper(nums,output,n+1,ans);
        return;

    }


vector<string> subsequences(string nums){
    vector<string>ans;
    string output="";
    helper(nums,output,0,ans);
    return ans;
    
}
