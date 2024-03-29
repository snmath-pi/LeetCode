class Solution {
public:
    
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& b) {
        int n = nums.size();
        const int mod = 1e9 + 7;
        sort(rbegin(nums), rend(nums));
        
        sort(begin(b), end(b));
        
        vector<int> diff(n + 2);
        
        
        
        for(int i = 0; i < b.size(); i++) {
            diff[b[i][0]]++; diff[b[i][1] + 1]--;
        }
        
        for(int i=1; i<=n; i++) {diff[i] += diff[i-1];}
        
        sort(rbegin(diff), rend(diff));
        
        long long  ret = 0;
        
       
        for(int j = 0, i = 0; i < n; i++, j++) {
            ret = (ret % mod + (nums[j] % mod *1ll* diff[i] % mod) % mod) % mod;
        }
        return ret;
        
    }
};
