class Solution {
    bool isPalindrome(int i,int j,string s)
    {
        while(i<=j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(int i,vector<string>temp,vector<vector<string>>& res,string s)
    {
        if(i==s.size()){
            res.push_back(temp);
            return;
        }
        for(int j=i;j<s.size();j++)
        {
            if(isPalindrome(i,j,s)){
                temp.push_back(s.substr(i,j-i+1));
                solve(j+1,temp,res,s);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        vector<vector<string>>res;
        solve(0,temp,res,s);
        return res;
    }
};
