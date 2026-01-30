class Solution {
public:
    int firstUniqChar(string s) {
       unordered_map<int,int>freq;
       for(auto c : s)
       {
        freq[c]++;
       }
       for(int i=0;i<s.size();i++)
       {
        if(freq[s[i]]==1) return i;
       }
       return -1;
    }
};
