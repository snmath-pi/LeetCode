class Solution {
public:
    int minFlips(string s) {
        int n = (int) s.length();

        int o1 = 0, e1 = 0;
        int o0 = 0, e0 = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                e1 += (s[i] == '1');
                e0 += (s[i] == '0');
            } else {
                o1 += (s[i] == '1');
                o0 += (s[i] == '0');
            }
        }

        int res = n - max(o0 + e1, o1 + e0);

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                e1 -= (s[i] == '1');
                e0 -= (s[i] == '0');
            } else {
                o1 -= (s[i] == '1');
                o0 -= (s[i] == '0');
            }
            if ((n + i) % 2 == 0) {
                e1 += (s[i] == '1');
                e0 += (s[i] == '0');
            } else {
                o1 += (s[i] == '1');
                o0 += (s[i] == '0');
            }

            res = min(res,  n - max(o0 + e1, o1 + e0));
        }


        return res;
    }
};