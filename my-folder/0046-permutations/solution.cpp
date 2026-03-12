class Solution {
    void solve(int i,vector<vector<int>>& res,vector<int>& nums)
    {
        if(i==nums.size()){
            res.push_back(nums);
            return;
        }

        for(int j=i;j<nums.size();j++)
        {
            swap(nums[i],nums[j]);
            solve(i+1,res,nums);
           swap(nums[i],nums[j]);

        }

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        //vector<bool>used(nums.size(),false);
        vector<vector<int>>res;
        
        solve(0,res,nums);
        return res;
    }
};
