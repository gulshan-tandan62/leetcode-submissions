class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>prefixSum;
        prefixSum[0]=1;
        int i = 0;
        int count=0;
        int sum =0;
        while(i<nums.size())
        {
            sum += nums[i];
            if(prefixSum.find(sum-k)!=prefixSum.end())
            {
                count += prefixSum[sum-k];
            }
            prefixSum[sum]++;
            i++;

        }
        return count;
    }
};
