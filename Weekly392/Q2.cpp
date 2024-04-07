class Solution {
public:
    string getSmallestString(string s, int k) {
        string res = "";
        
        for(int i=0;i<s.size(); i++) {
            if(!k) {
                res += s[i]; continue;
            }
            int back = (s[i]-'a');
            int front = (26-(s[i]-'a'));
            int mn = min(back, front);
            if(mn<=k) {
                res += 'a';
                k-=mn;
            } else {
                char back = (char) ((int) (s[i] - 'a' - k) + 'a');
                char front = (char)((int)((s[i]-'a' + k)%26)+'a');
                char mn = min(back, front); res += mn;
                k = 0;
            }
        }
        return res;
    }
};
