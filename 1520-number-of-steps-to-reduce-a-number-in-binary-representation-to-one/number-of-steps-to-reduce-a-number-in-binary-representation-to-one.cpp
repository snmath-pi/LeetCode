class Solution {
public:
    bool chk(string& s) {
        int n = (int) s.size();
        bool ok = 1;
        for (int i = 0; i < n - 1; i++) if (s[i] == '1') ok = 0;
        ok &= (s[n-1]=='1');
        return ok;
    }
    int numSteps(string s) {
        
        int steps = 0, iter = 10;
        while (!chk(s)) {
            int n = (int) s.size();
            steps++;
            if (s.back() == '1') {
                int rem = 1;
                for (int i = n - 1; i >= 0; i--) {
                    if (s[i] == '1') rem++;
                    s[i] = (rem % 2 + '0');
                    rem /= 2;
                    if (!rem) break;
                }
                if (rem) s.insert(0, 1, '1');
                
            } else {
                for (int i = n - 2; i >= 0; i--) {
                    s[i + 1] = s[i];
                }
                s[0] = '0';
            }
        }
        return steps;
    }
};