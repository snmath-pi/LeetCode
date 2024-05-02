class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        int dp[n + 1][k]; 
        const int inf = 1e9;
        for(int i=0;i<=n;i++)for(int j=0;j<k;j++)dp[i][j]=inf;
        dp[0][0] = 0;

        for(int i=1;i<=n;i++) {
            dp[i][0]=dp[i-1][0]+cookies[i-1];
            for(int j=1;j<k;j++) {
                int sm = cookies[i-1];
                for(int l=i-1;l>=1;l--){
                    dp[i][j]=min(dp[i][j], max(sm, dp[l][j-1]));
                    sm+=cookies[l-1];
                }
            }
        }
        return dp[n][k-1];
    }
};
