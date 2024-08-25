class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k--) {
            int mn = min_element(begin(nums),end(nums))-begin(nums);
            nums[mn]*=multiplier;
        }
        return nums;
    }
};
