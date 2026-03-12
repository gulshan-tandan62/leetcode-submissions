class Solution {
    void solve(int i,vector<int>temp, vector<vector<int>>& res,vector<int>& nums,int target)
    {
        if(target==0){
            res.push_back(temp);
            return;
        }
        if(i==nums.size()|| target<0) return;
        temp.push_back(nums[i]);
        solve(i,temp,res,nums,target-nums[i]);
        temp.pop_back();
        solve(i+1,temp,res,nums,target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        solve(0,temp,res,nums,target);
        return res;
    }
};
