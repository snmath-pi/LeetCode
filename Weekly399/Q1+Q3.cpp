class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        map<int, long long> mp;
        for(auto x: nums2) mp[x]++;
        
        long long res = 0;
        
        for(int i=0; i<nums1.size(); i++) {
            if(nums1[i]%k)continue;
            long long val = nums1[i] / k;
            
            for(int j=1; j*j <= val; j++) {
                if(val%j==0) {
                    res += mp[j];
                    if(j*j==val)continue;
                    res += mp[val/j];
                }
            }
        }
        return res;
    }
    
};
