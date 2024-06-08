class Solution {
public:
    string clearDigits(string s) {
        
        string res = "";
        int cnt = 0;
        for(int i=s.size()-1;i>=0; i--) {
            if(s[i]>='a'&&s[i]<='z') {
                if(!cnt) res += s[i];
                else cnt--;
            }
            else cnt++;
        }
        reverse(begin(res),end(res));
        return res;
    }
};
