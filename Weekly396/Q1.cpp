class Solution {
public:
    bool isValid(string word) {
        set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        bool ok = (word.size() >= 3);
        bool ok1 = 0, ok2 = 0;
        for(int i=0; i<word.size(); i++) {
            if(!(word[i]>='a'&&word[i]<='z'||word[i]>='A'&&word[i]<='Z'||word[i]>='0'&&word[i]<='9')) return false;
            if(vowels.find(word[i])!=vowels.end()) ok1 = 1;
            else if(word[i]>='a'&&word[i]<='z'||word[i]>='A'&&word[i]<='Z') {
                if(vowels.count(word[i]) == 0) ok2 = 1;
            }
        }
        return ok && ok1 && ok2;
    }
};
