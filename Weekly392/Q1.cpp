class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int res = 0;
        
        for(int i=0; i<nums.size(); i++) {
            int cnt = 1;
            for(int j=i + 1; j<nums.size(); j++) {
                if(nums[j] > nums[j-1]) cnt++;
                else break;
            }
            res = max(res, cnt); cnt = 1;
            for(int j=i + 1; j<nums.size(); j++) {
                if(nums[j] < nums[j-1]) cnt++;
                else break;
            }
            res = max(res, cnt);
        }
        return res;
    }
};
