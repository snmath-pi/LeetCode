class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long res = 0;
        
        int n = nums.size();
        int val = nums[0];
        int cnt = 0;
        while(val)val/=10,cnt++;
        long long dp[cnt][10];
        memset(dp, 0, sizeof(dp));
        for(auto x: nums) {
            int val = x;
            int cnt = 0;
            while(val) {
                dp[cnt++][val%10]++; val/=10;
            }
        }
        
        for(int i=0; i<cnt; i++) {
            for(int j=0; j<10; j++) {
                for(int k=j+1;k<10; k++) {
                    res += dp[i][j]*dp[i][k];
                }
            }
        }
        
        return res;
        
        
    }
};
