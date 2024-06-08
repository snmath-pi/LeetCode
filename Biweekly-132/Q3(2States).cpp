class Solution {
public:
    int dp[5005][55];
    int maximumLength(vector<int>& a, int k) {
        int n = a.size();

        vector<pair<int, int>> ita;

        for(int i=0; i<n; i++) {
            int cnt = 0;
            int val = a[i];
            while(i<n&&val==a[i])i++,cnt++;
            ita.push_back({val, cnt});
            i--;
        }
        int m = ita.size();
        memset(dp, 0, sizeof(dp));

        dp[0][0] = ita[0].second;
        for(int i=1; i<m; i++) {
            dp[i][0] = ita[i].second;
            for(int l=0; l<=k; l++) {
                // how to make this fast
                for(int j=0;j<i; j++) {
                    if(ita[j].first == ita[i].first && dp[j][l]) dp[i][l] = max(dp[i][l], dp[j][l]+ita[i].second);
                    if(l) {
                        if(ita[j].first != ita[i].first && dp[j][l-1]) dp[i][l] = max(dp[i][l], dp[j][l-1]+ita[i].second);
                    }
                }
            }
        }
       
        int res = 0;
        for(int j=0;j<m;j++) for(int i=0; i<=k; i++) res = max(res, dp[j][i]);
        return res;
    }
};
