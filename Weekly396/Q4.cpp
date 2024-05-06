class Solution {
public:
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        cost2 = min(cost2, 2*cost1);
        int64_t sum = 0, mx = *max_element(begin(nums),end(nums)), 
                mn = *min_element(begin(nums),end(nums));
        int n = nums.size();
        for(int i=0; i<n; i++) {
            sum += nums[i];
        }
        int64_t res = cost1*(n*1ll*mx-sum);
        for(int64_t x = mx; x <= 3*mx; x++) {
            int64_t tmp = n*1ll*x-sum;
            int64_t tmx = x-mn;
            if(tmx > (tmp-tmx)) {
                res = min(res, (tmp-tmx)*cost2 + (2*tmx-tmp)*cost1);
            } else {
                res = min(res, tmp/2*cost2+tmp%2*cost1);
            }
        }
        return res%1000000007;
    }
};
