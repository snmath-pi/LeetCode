class Solution {
public:
    int dp[5050][5050][50];
    int maximumLength(vector<int>& a, int k) {
        int n = a.size();

        vector<pair<int, int>> ita;

        ita.push_back({0, 0});
        for(int i=0; i<n; i++) {
            int cnt = 0;
            int val = a[i];
            while(i<n&&val==a[i])i++,cnt++;
            ita.push_back({val, cnt});
            i--;
        }
        int m = ita.size();
        memset(dp, -1, sizeof(dp));
        auto dfs = [&](int i, int j, int cnt, auto &&dfs)->int {
            if(i==m) return 0;
            if(~dp[i][j][cnt]) return dp[i][j][cnt];

            int take = 0, inc=0;
            if(j!=0) inc = (ita[i].first != ita[j].first);
            if(cnt + inc <= k) take += ita[i].second + dfs(i+1, i, cnt+inc, dfs);
            int ntake = dfs(i+1, j, cnt, dfs);
            return dp[i][j][cnt] = max(take, ntake);
        };
        return dfs(1, 0, 0, dfs);
    }
};
