class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prefix = 1;
        int suffix = 1;
        int ans = INT_MIN;
        for(int i=0;i<n;i++)
        {
            prefix = (prefix==0?1:prefix)*nums[i];
            suffix = (suffix==0?1:suffix)*nums[n-1-i];

            ans = max(ans,max(prefix,suffix));
        }
        return ans;
    }
};
