class Solution {
public:
    int minOperations(string s, int k) {
        int n = (int) s.size();
        int startZero = 0;

        for (char c: s) startZero += (c == '0');
        queue<int> q;
        vector<int> dis(n + 1, -1);
        vector<set<int>> unvisited(2);

        for (int i = 0; i <= n; i++) {
            unvisited[i % 2].insert(i);
        }

        dis[startZero] = 0;
        q.push(startZero);
        unvisited[startZero % 2].erase(startZero);


        while (!q.empty()) {
            int v = q.front();
            q.pop();
            if (v == 0) {
                return dis[v];
            }

            int parity = (v + k) % 2;

            int max_ones_to_zeros = v + min(n - v, k) - (k - min(n - v, k));
            int max_zeros_to_ones = v - min(k, v) + k - min(v, k);

            auto& s_ref = unvisited[parity];
            auto it = s_ref.lower_bound(max_zeros_to_ones);
            while (it != s_ref.end() && *it <= max_ones_to_zeros) {
                int nextV = *it;
                dis[nextV] = dis[v] + 1;
                q.push(nextV);
                it = s_ref.erase(it);
            }
        }
        return -1;


    }
};