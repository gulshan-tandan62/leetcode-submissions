class Solution {
    void solve(int idx, int parts,string path,vector<string>& res,string s)
    {
        if(parts==4 && idx==s.size()){
            path.pop_back();
            res.push_back(path);
            return;
        }
        if(parts==4)return;
        for(int len = 1;len<=3 && idx+len<=s.size();len++)
        {
            string segments = s.substr(idx,len);
            if((segments[0]=='0' && segments.size()>1) || stoi(segments)>255) continue;
            solve(idx+len,parts+1,path+segments+".",res,s);
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string>res;
        solve(0,0,"",res,s);
        return res;
    }
};
