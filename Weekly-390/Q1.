class Solution {
public:
    int maximumLengthSubstring(string s) {
        int res = 0;
        
        for(int i=0; i<s.size(); i++) {
            for(int j=i; j<s.size(); j++) {
                string x = s.substr(i, j - i + 1);
                map<char, int> temp; for(auto y: x)temp[y]++;
                bool ok = 1;
                for(auto &u: temp) {
                    ok &= u.second <= 2;
                }
                if(ok) res = max(res, j - i + 1);
            }
        }
        
        return res;
    }
};
