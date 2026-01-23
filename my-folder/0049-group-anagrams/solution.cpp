class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;
        for(auto str : strs)
        {
            string s2 = str;
            sort(str.begin(),str.end());
            mpp[str].push_back(s2);
        }
        vector<vector<string>>res;
        for(auto it : mpp)
        {
            res.push_back(it.second);
        }
        return res;
    }
};
