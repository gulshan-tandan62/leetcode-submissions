class Solution {
    vector<int> NSE(vector<int>& heights) {
        int n = heights.size();
        vector<int>nse(n);
        stack<int> st;
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (st.empty())
                nse[i] = heights.size();
            else {nse[i] =st.top();}
            st.push(i);
        }
        return nse;
    }

    vector<int>PSE(vector<int>& heights)
    {
        int n = heights.size();

        vector<int>pse(n);
        stack<int>st;
        for(int i=0;i<heights.size();i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])st.pop();
            if(st.empty()) pse[i] = -1;
            else pse[i] = st.top();
            st.push(i);
        }
        return pse;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = NSE(heights);
        vector<int> pse = PSE(heights);
        int maxRec = 0;
        for(int i=0;i<heights.size();i++)
        {
            int wd = (nse[i]-pse[i]-1);
            maxRec = max(maxRec,wd*heights[i]);
        }
        return maxRec;



    }
};
