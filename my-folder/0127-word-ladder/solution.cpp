class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        if(!st.count(endWord)) return 0;
        if(beginWord==endWord) return 1;

        queue<pair<int,string>>q;
        q.push({1,beginWord});
        if(st.count(beginWord))st.erase(beginWord);
       
        while(!q.empty())
        {
            string word = q.front().second;
            int step = q.front().first;

            q.pop();
            
            if(word==endWord) return step;
            for(int i=0;i<word.size();i++)
            {
                char c = word[i];
                for(char ch = 'a';ch<='z';ch++)
                {
                    word[i]  =ch;
                    if(st.count(word)){
                        q.push({step+1,word});
                        st.erase(word);
                    }
                }
                word[i] = c;
            }
        }
        return 0;
    }
};
