class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> res;
        int n = nums.size();
        
        vector<int> pre(n);
        pre[0] = 0;
        for(int i=1; i<n; i++) {
            pre[i]=pre[i-1]+(nums[i]%2!=nums[i-1]%2);
        }
        
        for(auto x: queries) {
            int l = x[0], r = x[1];
            int val = pre[r]-(!l?0: pre[l-1]), req = r-l;
            if(l-1>=0 && nums[l]%2!=nums[l-1]%2)val--;
            if(val>=req)res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};
