class Solution {
    long long solve(int i,int k,vector<int>& nums,vector<int>& mul,vector<vector<long long>>& dp)
    {
        int n = nums.size();
        int m = mul.size();
        if(k==m) return 0;
        if(dp[i][k]!=LLONG_MIN) return dp[i][k];
        int j = n-1-(k-i);
        long long left =(long long )nums[i]*mul[k] + solve(i+1,k+1,nums,mul,dp);
        long long right =(long long )nums[j]*mul[k] + solve(i,k+1,nums,mul,dp);
        return dp[i][k]= max(left,right);
    }
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        if(n<m) return 0;
        vector<vector<long long>>dp(m+1,vector<long long>(m+1,LLONG_MIN));
        return (int)solve(0,0,nums,multipliers,dp);
    }
};
