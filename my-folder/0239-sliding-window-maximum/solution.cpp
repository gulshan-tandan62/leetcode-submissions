class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int r = 0;
        int n = nums.size();
        vector<int> res;
        while (r < n) {
            if (!dq.empty() &&  dq.front()==r-k)
                dq.pop_front();
            while (!dq.empty() &&( nums[dq.back()] <= nums[r]))
                dq.pop_back();
            
            dq.push_back(r);
            if (r >= k - 1)
                res.push_back(nums[dq.front()]);
            r++;
        }
        return res;
    }
};
