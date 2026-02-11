class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int len;
        for(int i = n-1;i>=0;i--)
        {
            while(i>=0 && s[i]==' ')i--;
            if(i<0)break;
            int j=i;
            while(j>=0 && s[j]!=' ')j--;
            len = i-j;
            break;
        }
        return len;
    }

};
