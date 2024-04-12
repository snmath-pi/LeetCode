class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        auto calc = [&](string x, string y, string z)->int {
            if(x.size() > y.size() or x.size() > z.size()) return 1e9;

            int j = 0, k = 0;
            for(int i=0; i < x.size(); i++, j++) {
                if(y[j] != x[i]) break;
            }
            for(int i=0; i < x.size(); i++, k++) {
                if(z[k] != x[i]) break;
            }
            int val = min(j, k);
            int i = x.size() - val;
            j = y.size() - val;
            k = z.size() - val;
            if(j == y.size() or k == z.size()) return 1e9;
            return j + k + i;
        };
        int a = calc(s1, s2, s3);
        int b = calc(s2, s1, s3);
        int c = calc(s3, s1, s2);
        a = min({a, b, c});
        return a == 1e9 ? -1 : a;

        
    }
};
