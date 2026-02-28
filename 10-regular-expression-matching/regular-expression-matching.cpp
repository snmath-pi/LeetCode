class Solution {
public:
    

    bool dfs(int i, int j, int& n, int& m, string& s, string& p, vector<vector<int>>& dp) {
        if (i == n) {
            if (j == m) return true;
            if (j + 1 < m && p[j + 1] == '*') return dfs(i, j + 2, n, m, s, p, dp);
            return false;
        }

        if (j == m) return false;

        if (~dp[i][j]) return dp[i][j];

        bool match = (i < n && (p[j] == s[i] || p[j] == '.'));

        if (j + 1 < m && p[j + 1] == '*') {
            return dp[i][j] = dfs(i, j + 2, n, m, s, p, dp) || (match && dfs(i + 1, j, n, m, s, p, dp));
        }
        if (match) {
            return dp[i][j] = dfs(i + 1, j + 1, n, m, s, p, dp);
        } 
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = (int) s.size();
        int m = (int) p.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return dfs(0, 0, n, m, s, p, dp);
    }
};