class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res = {-1, -1};
        int lo = 0;
        int hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                if (mid>0 && nums[mid - 1] == target)
                    hi = mid - 1;
                else {
                    res[0] = mid;
                    break;
                }
            }
            else if (nums[mid]>target) hi = mid -  1;
            else  lo = mid+1;
        }
         lo = 0;
         hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                if (mid<n-1 && nums[mid + 1] == target)
                    lo = mid + 1;
                else {
                    res[1] = mid;
                    break;
                }
            }
            else if (nums[mid]>target) hi = mid -  1;
            else  lo = mid+1;
        }
        return res;
    }
};
