
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0;
        for(int i=0; i<n; i++) {
        cnt1 += (nums[i]%2); cnt2 += (nums[i]%2==0);}
        int res = max(cnt1, cnt2);
        // odd even odd ...
        // even odd even...
        
        int ok = 0;
        cnt1 = 0, cnt2 = 0;
        for(int i=0; i<n; i++) {
            if(!ok) {
                if(nums[i]%2){
                    cnt1++;
                    ok^=1;
                }
            } else {
                if(nums[i]%2==0) {
                    cnt1++;
                    ok^=1;
                }
            }
        }
        ok=0;
        for(int i=0; i<n; i++) {
            if(!ok) {
                if(nums[i]%2==0){
                    cnt2++;
                    ok^=1;
                }
            } else {
                if(nums[i]%2) {
                    cnt2++;
                    ok^=1;
                }
            }
        }
        return max({res, cnt1, cnt2});
    }
};
