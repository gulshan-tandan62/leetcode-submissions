class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string frst = strs[0];
        
        for(int i=0;i<frst.size();i++)
        {
            char c = frst[i];
            for(int j =1;j<strs.size();j++)
            {
                if(i>=strs[j].size() || c!=strs[j][i])return frst.substr(0,i);
            }

        }
        return frst;
    }
};
