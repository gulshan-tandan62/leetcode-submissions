class Solution {
    void solve(int open,int close,string temp,vector<string>& res,int n)
    {
        if(open+close == 2*n && open==close){
            res.push_back(temp);
            return;
        }
        if(open<n)
        {
            solve(open+1,close,temp+'(',res,n);
        }
        if(close<open){
            solve(open,close+1,temp+')',res,n);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        solve(0,0,"",res,n);
        return res;
    }
};
