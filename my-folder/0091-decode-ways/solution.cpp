class Solution {
    int solve(int i,string s,vector<int>& dp)

    {
        int n = s.size();
        if(i==n) return 1;
        if( s[i]=='0') return 0;
        
        if(dp[i]!=-1) return dp[i];
        int next = solve(i+1,s,dp);
        if(i<s.size()-1 && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))) next += solve(i+2,s,dp);
        return dp[i] = next;
    }
public:
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        vector<int>dp(s.size()+1,-1);
        return solve(0,s,dp);
    }
};
