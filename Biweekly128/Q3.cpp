class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int, int>>> g(n);
        for(auto x: edges) {
            g[x[0]].push_back({x[1], x[2]});
            g[x[1]].push_back({x[0], x[2]});
        }
        priority_queue<pair<int, int>> pq;
        pq.push({0, 0});
        vector<int64_t> dis(n, 1e12);
        dis[0] = 0;
        vector<bool> processed(n, false);
        while(!pq.empty()) {
            auto [w, x] = pq.top(); pq.pop();
            if(processed[x]) continue;
            processed[x] = true;
            for(auto [y, v]: g[x]) {
                if(v + dis[x] < dis[y] && v + dis[x] < disappear[y]) {
                    dis[y] = v + dis[x];
                    pq.push({-dis[y], y});
                }
            }
        }
        vector<int> res(n, -1);
        for(int i=0; i<n; i++) {
            if(dis[i] < disappear[i]) {
                res[i] = dis[i];
            }
        }
        return res;
    }
};
