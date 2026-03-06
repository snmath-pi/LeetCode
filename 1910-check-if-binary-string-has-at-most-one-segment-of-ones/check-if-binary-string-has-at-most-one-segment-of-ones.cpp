class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt = 0, res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                cnt++;
            } else {
                if (cnt) {
                    res++;
                }
                cnt = 0;
            }
        }
        return res + (cnt ? 1 : 0) <= 1;
    }
};