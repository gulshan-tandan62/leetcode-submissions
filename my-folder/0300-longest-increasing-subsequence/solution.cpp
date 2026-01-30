class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>seq;

        for(auto x : nums)
        {
            int idx = 0;
            while(idx<seq.size() && seq[idx]<x)
            {
                idx++;
            }
            if(idx==seq.size()) seq.push_back(x);
            else seq[idx] = x;
        }
        return seq.size();

    }
};
