class Solution {
    int solve(int i,vector<int>& nums,int sum,vector<vector<int>>& dp)
    {
        if(sum==0) return 1;
        if(i>=nums.size()||sum<0) return 0;
        if(dp[i][sum]!=-1) return dp[i][sum];
        return dp[i][sum] = solve(i+1,nums,sum-nums[i],dp) || solve(i+1,nums,sum,dp);
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto num : nums)
        {
            sum+=num;
        }
        if(sum%2!=0) return false;
        int half = sum/2;
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(0,nums,half,dp);
    }
};
