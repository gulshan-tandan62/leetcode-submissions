class Solution {
    void solve(int i,vector<int>temp,vector<vector<int>>& res, vector<int>& nums){
        if(i==nums.size()) {
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(i+1,temp,res,nums);
        temp.pop_back();
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[i]!=nums[j])
            {
                solve(j,temp,res,nums);
                return;
            }
        }
        solve(nums.size(),temp,res,nums);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        vector<int>temp;
        solve(0,temp,res,nums);
        return res;
    }
};
