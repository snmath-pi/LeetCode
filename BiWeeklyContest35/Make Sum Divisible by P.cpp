class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        
        int n = nums.size();
        long long tot = accumulate(begin(nums), end(nums), 0ll);
        if(tot % p == 0) {
            return 0;
        }
        
        long long tar = tot % p;
        map<long long, long long> mp;
        mp[0] = -1;
        
        long long res = n;
        for(long long sum = 0, i = 0; i < n; i++) {
            sum += nums[i]; sum %= p;
            
            if(mp.find((sum - tar + p) % p) != mp.end()) {
                res = min(res, i - mp[(sum - tar + p) % p]);
            }
            
            mp[sum] = i;
            
        }
        
        return res == n ? -1: res;
    }
};
