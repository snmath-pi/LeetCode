class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long res = 0;
        
        for(int r = 0, l = 0; r < nums.size(); r++) {
            if(r && nums[r] == nums[r-1]) {
                l = r;
            }
            res += r - l +1;
        }
        return res;
    }
};
