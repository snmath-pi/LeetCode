class Solution {
public:
    int waysToReachStair(int k) {
        
        map<array<int, 3>, int> mp;
        int ans = 0;
        auto dfs = [&](int i, int state, int jump, auto&&dfs) {
            if(i<0) return 0;
            if(i-k>1) {
                return 0;
            }
            if(i==k){
                // cout << i << ' ' << state << ' ' << jump << '\n';
                int val = 1;
                if(jump==0) {
                    val += dfs(i+1,1,jump+1,dfs);
                }
                if(state) {

                    val += dfs(i-1,0,jump,dfs);
                }
                return mp[{i, state, jump}] = val;
            }
            

            if(mp.find({i, state, jump}) !=mp.end()) return mp[{i, state, jump}];

            int res = 0;
            if(state == 1) res += dfs(i-1, 0, jump,dfs);

            res += dfs(i+(1<<jump),1,jump+1,dfs);
            
            return mp[{i, state, jump}] = res;
            
        }; 
        return dfs(1, 1, 0,dfs);
    }
};
