class Solution {
public:
    
    bool doesAliceWin(string s) {
        int cnt = 0;
        set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(auto c: s)if(vowels.count(c))cnt++;
        if(cnt%2)return 1;
        return cnt!=0;
    }
};
