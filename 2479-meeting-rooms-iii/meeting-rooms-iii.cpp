class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(begin(meetings), end(meetings));
        priority_queue<int, vector<int>, greater<int>> free;
        for (int i = 0; i < n; i++) free.push(i);

        vector<int> fr(n, 0);

        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> book;
        for (auto& x: meetings) {
            int a = x[0], b = x[1];
            while (!book.empty() && book.top().first <= x[0]) {
                free.push(book.top().second);
                book.pop();
            }

            if (!free.empty()) {
                int room = free.top(); free.pop();
                book.push({x[1], room});
                fr[room]++;
            } else {
                auto [u, v]  = book.top(); book.pop();
                auto s = max(u*1ll, 1ll*x[0]);
                auto e = s + x[1] - x[0];
                book.push({e, v});
                fr[v]++;
            }
        }
        int mx = 0, res = -1;
        for (int i = 0; i < n; i++) {
            if (mx < fr[i]) {
                mx = fr[i];
                res = i;
            }
        }

        return res;
    }
};