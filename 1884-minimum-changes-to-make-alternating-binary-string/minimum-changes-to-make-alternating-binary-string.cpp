class Solution {
public:
    int minOperations(string s) {
        int res1 = 0, res2 = 0;
        char c1 = '0', c2 = '1';

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != c1) res1++;
            if (s[i] != c2) res2++;
            c1 ^= 1;
            c2 ^= 1;
        }
        
        return min(res1, res2);
    }
};