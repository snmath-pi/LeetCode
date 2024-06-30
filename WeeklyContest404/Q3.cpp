class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        int dp[n][k];
        memset(dp, 0, sizeof(dp));
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                int md = (nums[i]+nums[j])%k;
                // cout << i << ' ' << j << ' ' << md << '\n';
                dp[i][md]=max(dp[i][md], (dp[j][md] == 0 ? 1 : dp[j][md])+1);
            }
        }
        int mx = 0;
        for(int i=0;i<n;i++)for(int j=0;j<k;j++)mx=max(mx,dp[i][j]);
        return mx;
    }
};
