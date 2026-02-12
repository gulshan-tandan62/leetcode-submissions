class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;
        vector<string> words;
        while (ss >> word) {
            words.push_back(word);
        }
        if (pattern.size() != words.size())
            return false;
        unordered_map<char, string> mpp1;
        unordered_map<string, char> mpp2;
        for (int i = 0; i < pattern.size(); i++) {
            if (mpp1.find(pattern[i]) != mpp1.end()) {
                if (mpp1[pattern[i]] != words[i])
                    return false;

            } else if (mpp2.find(words[i]) != mpp2.end()) {
                if (mpp2[words[i]] != pattern[i])
                    return false;
            } else {
                mpp1[pattern[i]] = words[i];
                mpp2[words[i]] = pattern[i];
            }
        }
        return true;
    }
};
