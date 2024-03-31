class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        
        int res = 2e9;
        
        multiset<int> sum, diff;
        
        for(auto x: points) {
            sum.insert(x[0] + x[1]);
            diff.insert(x[0] - x[1]);
        }
        
        
        for(auto x: points) {
            sum.erase(sum.lower_bound(x[0] + x[1]));
            diff.erase(diff.lower_bound(x[0] - x[1]));
            auto itr = sum.end(); --itr; 
            auto itr3 = sum.begin();
            // A[N] - A[1]
            
            int val = *itr - *itr3;
            itr = diff.end(); --itr;
            itr3 = diff.begin();
            
            val = max(val, *itr-*itr3);
            
            
            res = min(res, val);
            sum.insert(x[0] + x[1]);
            diff.insert(x[0] - x[1]);
        }
        
        
        return res;
    }
};
