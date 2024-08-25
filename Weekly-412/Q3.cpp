class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        if(multiplier==1)return nums;
        vector<int> ans(n);
        priority_queue<pair<long long , long long>, vector<pair<long long, long long>>, greater<>> pq;
        for(int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }
        
        const int mod = 1e9 + 7;
        long long limit = 1<<30;
        while(k>0) {
            if(pq.top().first >= limit) break;
            auto x = pq.top(); pq.pop();
            x.first = x.first *1ll* multiplier;
            // cout<<x.first<<'\n';
            pq.push(x);
            k--;
        }
        
        vector<pair<long long, long long>> b;
        while(!pq.empty()) {
            b.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }
        
        // for(auto &x: b)cout<<x.first<<' ';
        
        auto qpow = [&](long long x, long long y) {
            long long ans = 1;
            while(y) {
                if(y & 1) ans = ans * x % mod;
                x = x * x % mod;
                y /=2;
            }
            return ans;
        };
        
        for(int i = 0; i < n; i++) {
            b[i].first = (b[i].first %mod * qpow(multiplier, k / n + (i < k % n ? 1 : 0)%mod)) % mod;
        }
        
        for(auto [x, y]: b) {
            ans[y] = x;
        }
        
        return ans;
    }
};
