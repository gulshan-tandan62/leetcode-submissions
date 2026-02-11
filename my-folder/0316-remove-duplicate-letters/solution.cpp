class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>freq(256,0);
        vector<bool>inStack(256,false);

        for(auto c : s)
        {
            freq[c]++;
        }
        stack<char>st;
        for(auto c : s)
        {
            freq[c]--;
            if(inStack[c]) continue;

            while(!st.empty() && st.top()>c && freq[st.top()]>0)
            {
                inStack[st.top()]= false;
                st.pop();
            }

            st.push(c);
            inStack[c] = true;
        }

        string res = "";
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
