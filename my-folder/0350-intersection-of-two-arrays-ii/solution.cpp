class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) return intersect(nums2,nums1);
        unordered_map<int,int>freq1;
        for(auto num : nums1)
        {
            freq1[num]++;
        }
        vector<int>res;
        for(int i=0;i<nums2.size();i++)
        {
            if(freq1[nums2[i]]>0)
            {
                res.push_back(nums2[i]);
                freq1[nums2[i]]--;
            }
        }
        return res;
    }
};
