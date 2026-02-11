class Solution {
public:
    int compress(vector<char>& chars) {
        string res ="";
        int n = chars.size();
        int i=0;
        int write = 0;
        while(i<n)
        {
            char ch = chars[i];
            int cnt  = 0;
            while(i<n && ch==chars[i]){
                cnt++;
                i++;
            }

            chars[write] = ch;
            write++;

            if(cnt>1)
            {
                string cn = to_string(cnt);
                for(auto d : cn)
                {
                    chars[write] = d;
                    write++;
                }
            }
        }
        return write;

    }
};
