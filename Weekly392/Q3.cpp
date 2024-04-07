class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        long long res = 0;
        sort(begin(nums), end(nums));
        int n = nums.size();
        
        int mid = n / 2;
        
        if(nums[mid] == k) return 0;
        else if(nums[mid] < k) {
            for(int i=mid; i<n; i++) {
                if(nums[i] < k) {
                    res += k - nums[i];
                } else break;
            }
        } else {
            for(int i=mid; i>=0; i--) {
                if(nums[i] > k) res += nums[i] - k;
                else break;
            }
            
        }
        return res;
    }
};
