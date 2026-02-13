class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if(n<m) return -1;
        int i=0;
    
        while(i<=n-m){
            if(haystack[i]==needle[0])
            {
                if(haystack.substr(i,m)==needle) return i;
            }
            i++;
        }
        return -1;

    }
};
