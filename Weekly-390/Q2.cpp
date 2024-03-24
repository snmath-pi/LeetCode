class Solution {
public:
    int minOperations(int k) {
        // x * 1 + y * (x) = k -> x * (y + 1) = k -> k / x
        int res = k - 1;
        for(int i=0; i<=k; i++) {
            int cur = 1 + i;
            
            int ops = (k + cur - 1) / cur - 1;
            res = min(res, i + ops);
        }
        return res;
    }
};
