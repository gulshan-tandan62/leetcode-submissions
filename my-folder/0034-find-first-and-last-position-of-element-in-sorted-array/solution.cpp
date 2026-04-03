class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        vector<int>res = {-1,-1};
        while(lo<=hi)
        {
            int mid = lo+(hi-lo)/2;
            if(nums[mid]==target){
                res[0] = mid;
                hi = mid-1;
            }
            else if(nums[mid]<target) lo = mid+1;
            else hi =mid-1;
        }
        
        lo = 0;
        hi = n-1;
        while(lo<=hi)
        {
            int mid = lo+(hi-lo)/2;
            if(nums[mid]==target){
                res[1] = mid;
                lo =mid+1;
            }
           else if(nums[mid]<target)lo = mid+1;
            else hi = mid-1;
        }
    
        return res;

    }
};
