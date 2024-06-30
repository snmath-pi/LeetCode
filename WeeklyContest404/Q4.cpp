
class Solution {
public:
    pair<int, int> dfs(const vector<vector<int>> &tree, int node = 0,
                  int previous = -1, int length = 0) {
        pair<int, int> max_path = {node, length};
        for (const int &i : tree[node]) {
            if (i == previous) { continue; }
            pair<int, int> other = dfs(tree, i, node, length + 1);
            if (other.second > max_path.second) { max_path = other; }
        }
        return max_path;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size()+1, m = edges2.size()+1;
        vector<vector<int>> g(n), gg(m);
        
        for(auto x: edges1) {
            g[x[0]].push_back(x[1]);           
            g[x[1]].push_back(x[0]);

        }
        for(auto x: edges2) {
            gg[x[0]].push_back(x[1]);            
            gg[x[1]].push_back(x[0]);

        }
        
        int s1 = dfs(g).first, s2 = dfs(gg).first;
        int x1 = dfs(g, s1).second, x2 =dfs(gg, s2).second;
        return max({x1, x2, (x1+1)/2+(x2+1)/2+1});
        
        
    }
};
