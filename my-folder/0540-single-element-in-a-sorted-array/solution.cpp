class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int hi = n-1;
        int lo = 0;
        while(lo<hi)
        {
            int mid = lo+(hi-lo)/2;
            if(mid%2!=0)
            {
                mid = mid-1;

            }
            if(nums[mid]==nums[mid+1]){
                lo = mid+2;
            }
            else {
                hi = mid;
            }
        }
        return nums[lo];
    }
};
