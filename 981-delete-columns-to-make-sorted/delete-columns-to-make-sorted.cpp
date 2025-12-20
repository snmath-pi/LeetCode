class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        if (strs.empty()) return 0;
        int n = (int) strs.size();
        int m = (int) strs[0].length();

        int res = 0;
        for (int j = 0; j < m; j++) {
            int ok = 1;
            for (int i = 1; i < n; i++) {
                if (strs[i][j] < strs[i - 1][j]) {
                    ok = false;
                    break;
                }
            }
            res += ok;
        }
        return m - res;
    }
};