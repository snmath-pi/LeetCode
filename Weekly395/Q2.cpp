class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> ms1, ms2; 
        for(auto x: nums1) ms1.insert(x);
        for(auto y: nums2) ms2.insert(y);
        
        int l = -1e3 - 10, r = 1e3 + 10;
        auto good = [&](int val) {
            multiset<int> tmp = ms2;
            int taken = 0;
            for(auto x: nums1) {
                int cur = x + val;
                if(tmp.count(cur)) {
                    tmp.erase(tmp.lower_bound(cur));
                    taken++;
                } 
            }
            return tmp.empty() && taken == nums1.size()-2;
        };
        for(int x=-1010; x<=1010; x++) {
            if(good(x)) return x;
        }
        return 0;
        
    }
};
