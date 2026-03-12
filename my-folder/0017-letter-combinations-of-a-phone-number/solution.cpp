class Solution {
    void solve(int i,string temp,string digits,vector<string>& combinations,vector<string>& res)
    {
        if(i==digits.size()){
            res.push_back(temp);
            return;
        }
        int digit = digits[i]-'0';
        for(int j= 0;j<combinations[digit].size();j++)
        {
           
            solve(i+1,temp+combinations[digit][j],digits,combinations,res);
           
            
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string>combinations = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>res;
        solve(0,"",digits,combinations,res);
        return res;
    }
};
