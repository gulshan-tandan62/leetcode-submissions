class Solution {
    void solve(vector<int>temp,vector<vector<int>>& res, vector<bool>& used,vector<int>&nums)
    {
        if(temp.size()==nums.size()){
            res.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(used[i]) continue;
            if(i>0 && nums[i]==nums[i-1] && !used[i-1]) continue;

            used[i] = true;
            temp.push_back(nums[i]);
            solve(temp,res,used,nums);
            used[i] = false;
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        vector<bool>used(nums.size(),false);
        vector<vector<int>>res;
        solve(temp,res,used,nums);
        return res;
    }
};
