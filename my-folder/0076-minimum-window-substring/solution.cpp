class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>need;
        for(auto c : t)
        {
            need[c]++;
        }

        int required = need.size();
       int have = 0;
       unordered_map<char,int>window;
       int l=0;
       int start = 0;
       int minLen = INT_MAX;
       for(int r= 0 ;r<s.size();r++)
        {
            char ch = s[r];
            window[ch]++;
            if(need.count(ch) && window[ch]==need[ch]){
                have++;
            }

            while(have==required)
            {
                if(minLen> r-l+1)
                {
                    minLen = r-l+1;
                    start = l;
                }
                char c = s[l];
                window[c]--;
                if(need.count(c) && window[c]<need[c])
                {
                    have--;
                }
                l++;
            }
        }
        return minLen==INT_MAX?"":s.substr(start,minLen);
    }
};
