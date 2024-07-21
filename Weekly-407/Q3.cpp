class Solution {
public:
    int maxOperations(string s) {
        int res = 0, cnt=0;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='1')cnt++;
            else{
                res+=cnt;
                while(i<s.size()&&s[i]=='0')i++;
                i--;
            }
        }
        return res;
    }
};
