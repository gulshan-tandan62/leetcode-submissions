class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int  n =nums.size();
        int r = 0;
        int sum = 0;
        int maxSum =INT_MIN;
        while(r<n)
        {
            sum += nums[r];
            maxSum = max(sum,maxSum);

            if(sum<0)
            {
                sum = 0;
            }
            r++;
        }
        return maxSum;
    }
};
