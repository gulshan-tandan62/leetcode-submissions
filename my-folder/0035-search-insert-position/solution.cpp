class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if(nums[n-1]<target) return n;
        int lo = 0;
        int hi = n-1;
        while(lo<hi)
        {
            int mid = lo+(hi-lo)/2;
            if(nums[mid]>=target) hi = mid;
            else lo = mid+1;
        }
        return hi;
    }
};
