class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> dp(n, vector<int> (4, 0));

        for(int i=1; i<=3; i++) dp[0][i] = (nums[0] == i);

        for(int i=1; i<n; i++) {
            for(auto j: {1, 2, 3}) {
                for(auto k: {1, 2, 3}) {
                    if(k <= j) {
                        dp[i][j] = max(dp[i][j], dp[i-1][k] + (j == nums[i]));
                    }
                }
            }
        }
        return n - max({dp[n-1][1], dp[n-1][2], dp[n-1][3]});

    }
};
