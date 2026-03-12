class Solution {
    void solve(int i,vector<int>temp,vector<vector<int>>& res,vector<int>& nums,int target)
    {
        if(target==0){
            res.push_back(temp);
            return;
        }
        if(i==nums.size() ||target<0)return;
        temp.push_back(nums[i]);
        solve(i+1,temp,res,nums,target-nums[i]);
        temp.pop_back();
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[i]!=nums[j]){
                solve(j,temp,res,nums,target);
                return;
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        vector<vector<int>>res;
        solve(0,temp,res,candidates,target);
        return res;
    }
};
