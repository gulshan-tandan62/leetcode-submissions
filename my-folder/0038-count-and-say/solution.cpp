class Solution {
public:
    string countAndSay(int n) {
        if(n==0) return "";
        string str = "1";
        for(int i=1;i<n;i++)
        {
            int count= 1;
            char c = str[0];
            string res = "";
            int j=1;
            while(j<str.size())
            {
                if(str[j]==c)
                {
                    count++;
                    
                }
                else{
                    res+= to_string(count)+c;
                    count=1;
                    c=str[j];
                }
                j++;
            }
            str = res +to_string(count) +c;
        }
        return str;
    }
};
