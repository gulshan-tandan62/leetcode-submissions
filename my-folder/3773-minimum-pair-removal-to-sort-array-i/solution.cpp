class Solution {
    bool isSorted(vector<int>& nums)
    {
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]>nums[i]) return false;
        }
        return true;
    }
public:
    int minimumPairRemoval(vector<int>& nums) {
        int operations =0;
        while(!isSorted(nums))
        {
            int minSum = INT_MAX;
            int idx = -1;
            for(int i=0;i<nums.size()-1;i++)
            {
                int currSum = nums[i]+nums[i+1];
                if(currSum<minSum)
                {
                    minSum = currSum;
                    idx = i;
                }
            }

            nums[idx] = nums[idx]+nums[idx+1];
            nums.erase(nums.begin()+idx+1);
            operations++;
        }
        return operations;
    }
};
