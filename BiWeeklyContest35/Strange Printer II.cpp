class Solution {
public:
    bool isPrintable(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();

        vector<set<int>> g(61);
        for(int i=1; i<=60; i++) {
            int mnx = n, mny = m, mxx = -1, mxy = -1;
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < m; k++) {
                    if(a[j][k] == i) {
                        mnx = min(mnx, j);
                        mny = min(mny, k);
                        mxx = max(mxx, j);
                        mxy = max(mxy, k);
                    }
                }
            }
            for(int u = mnx; u <= mxx; u++) {
                for(int v = mny; v <= mxy; v++) {
                    if(a[u][v] == i) continue;
                    g[i].insert(a[u][v]);
                }
            }
        }

        vector<int> vis(61), isvis(61);
        auto dfs = [&](int i, auto &&dfs)->bool {
            vis[i] = 1;
            isvis[i] = 1;
            for( auto j : g[i]) {
                if(!vis[j]) {
                    if(dfs(j, dfs)) return true;
                }
                else if(vis[j] && isvis[j]) return true;
            }
            isvis[i] = 0;
            return false;
        }; 

        for(int i=1; i<=60; i++){
            if(!vis[i] && dfs(i, dfs)) return false;
        }
        return true;
        
    }
};
