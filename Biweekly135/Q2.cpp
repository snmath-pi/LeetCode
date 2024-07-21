class Solution {
public:
    int minimumLength(string s) {
        map<char, int>mp;
        for(auto c: s) ++mp[c];
        int res = 0;
        for(auto [x, y]: mp) {
            if(y%2)res++;
            else res+=2;
        }
        return res;
    }
};
