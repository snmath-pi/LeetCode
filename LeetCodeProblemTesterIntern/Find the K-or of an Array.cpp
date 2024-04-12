class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int res = 0;
        int bit[32] = {0};
        for(auto &x: nums) {
            for(int i=0; i<31; i++) {
                bit[i] += ((x >> i & 1) != 0);
                if(bit[i] >= k) res |= 1<<i;
            }
        }
        return res;
    }
};
