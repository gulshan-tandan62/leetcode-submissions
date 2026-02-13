class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        if(n<m) return {};
        vector<int>need(26,0),window(26,0);
        for(auto c : p)
        {
            need[c-'a']++;
        }
        for(int i=0;i<m;i++)
        {
            window[s[i]-'a']++;
        }
        vector<int>res;
        if(need==window)res.push_back(0);
        for(int i=m;i<n;i++)
        {
            window[s[i]-'a']++;
            window[s[i-m]-'a']--;
            if(window==need){
                res.push_back(i-m+1);
            }
        }
        return res;
    }
};
