struct dsu {
	vector<int> p, sz;
	vector<pair<int, int>> query;
	int comp;
	dsu(int n) {
		comp = n;
		query.resize(n);
		p.resize(n); sz.resize(n, 1);
		for(int i=0; i<n; i++) {
			p[i] = i;
			query[i] = {i, i};
		}
	}

	int get(int a) {
		return p[a] = (p[a]==a?a:get(p[a]));
	}

	void unite(int a, int b) {
		a = get(a), b = get(b);
		if(a==b) return;
		if(sz[a] < sz[b]) swap(a, b);
		p[b] = a;
		sz[a] += sz[b];
		query[a].first = max(query[a].first, query[b].first);
		query[a].second = min(query[a].second, query[b].second);
		comp--;
	}
};
// 5
// [[0,1,7],[1,3,7],[1,2,1]]
// [[0,3],[3,4]]
// 3
// [[0,2,7],[0,1,15],[1,2,6],[1,2,1]]
// [[1,2]]
// 9
// [[0,4,7],[3,5,1],[1,3,5],[1,5,1]]
// [[0,4],[1,5],[3,0],[3,3],[3,2],[2,0],[7,7],[7,0]]
class Solution {
public:
    
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        dsu d(n + 1);
        vector<vector<pair<int, int>>> g(n);
        map<pair<int, int>, int> M;
        for(auto &x: edges) {
            if(x[0] > x[1]) swap(x[0], x[1]);
            if(M.count({x[0], x[1]})) {
                M[{x[0], x[1]}] &= x[2];
            } else {
                M[{x[0], x[1]}] = x[2];
            }
        }
        // keep min edges
        
        for(auto &x: M) {
            int u = x.first.first, v = x.first.second, w = x.second;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
            d.unite(v, u);
        }
        
        for(int i=0; i<n; i++) {
            sort(begin(g[i]), end(g[i]), [&](pair<int, int> p, pair<int, int> q) {
                return p.second < q.second;
            });
        }
        
        cout << "*" << M[{0, 3}] << '\n';
        map<int, int> mp;
        vector<int> vis(n, 0);
        int val = (1<<17)-1;
        auto dfs = [&](int i, auto &&dfs)->void {
            vis[i] = 1;
            for(auto [j, w]: g[i]) {
                if(!vis[j]) {
                    val &= w;
                    dfs(j, dfs);
                }
                val &= w;
            }
        };
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                val = (1 << 17) - 1;
                dfs(i, dfs);
                if(val != (1<<17)-1) mp[d.get(i)] = val;
                else mp[d.get(i)] = 0;
            }
        }
        vector<int> res;
        for(auto u: query) {
            int x = u[0], y = u[1];
            if(x == y) {
                res.push_back(0); continue;
            }
            if(d.get(x) != d.get(y)) {
                res.push_back(-1);
            } else {
                res.push_back(mp[d.get(x)]);
            }
        }
        return res;
    }
};
