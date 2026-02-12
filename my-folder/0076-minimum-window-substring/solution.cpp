class Solution {
public:
    string minWindow(string s, string t) {
        int n= s.size();
        unordered_map<char,int>need;
        for(auto c : t)
        {
            need[c]++;
        }
        int required =need.size();

        int l = 0;
        int start = 0 ;
        int minLen = INT_MAX;
        int have =0;
        unordered_map<char,int>window;
        for(int r = 0;r<n;r++)
        {
            char ch  = s[r];
            window[ch]++;
            if(need[ch]==window[ch])
            {
                have++;
            }
            while(have==required)
            {
                if(minLen>r-l+1)
                {
                    minLen = r-l+1;
                    start =l;
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
