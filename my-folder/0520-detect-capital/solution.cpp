class Solution {
public:
    bool detectCapitalUse(string word) {
    int cntupper = 0;
    for(int i=0;i<word.size();i++)
    {
        if(isupper(word[i])) cntupper++;
        
    }
    if(cntupper==word.size() || cntupper==0) return true;
    if(cntupper==1 && isupper(word[0])) return true;
    return false;
    }
};
