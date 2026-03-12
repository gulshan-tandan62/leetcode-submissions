class Solution {
    void solve(int i,int k,int n, vector<int>temp,vector<vector<int>>& res)
    {
        if(temp.size()==k && n==0) {
            res.push_back(temp);
            return;
        }
        if(i>9 || n<0 || temp.size()==k) return;
        temp.push_back(i);
        solve(i+1,k,n-i,temp,res);
        temp.pop_back();
        solve(i+1,k,n,temp,res);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        vector<vector<int>>res;
        solve(1,k,n,temp,res);
        return res;
    }
};
