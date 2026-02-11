class Solution {
    bool isVowel(char ch)
    {
        if(ch=='a' || ch=='e'|| ch=='i'|| ch=='o'|| ch=='u'|| ch=='A'|| ch=='E'|| ch=='I'|| ch=='O'|| ch=='U') return true;
        return false;
        
    }
public:
    string reverseVowels(string s) {
        int n = s.size();
        int l = 0;
        int r = n-1;
        while(l<=r)
        {
            while(l<=r && !isVowel(s[l]))l++;
            if(l>r) break;
            while(l<=r && !isVowel(s[r]))r--;
            if(l>r) break;
            swap(s[l],s[r]);
            l++;r--;
            
        }
        return s;
    }
};
