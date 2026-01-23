class Solution {
    int palindrome(int l , int r,string s)
    {
        int n = s.size();
        while(l>=0 && r<n)
        {
            if(s[r]!=s[l])
            {
                break;
            }
            l--;
            r++;
        }
        return r-l-1;
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = 0;
        int start = 0;
        for(int i=0;i<n;i++)
        {
            int odd = palindrome(i,i,s);
            int even = palindrome(i,i+1,s);
            int curr = max(odd,even);
            if(maxLen<=curr)
            {
                maxLen = curr;
                start = i-(maxLen-1)/2;
            }
        }
        return s.substr(start,maxLen);
    }
};
