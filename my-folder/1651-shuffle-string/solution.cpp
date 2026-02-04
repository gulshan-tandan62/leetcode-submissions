class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
     int n = s.size();
     for(int i=0;i<n;i++)
     {
        while(indices[i]!=i)
        {
            int corrPos = indices[i];
            swap(indices[corrPos],indices[i]);
            swap(s[i],s[corrPos]);
        }

     }   
     return s;
    }
};
