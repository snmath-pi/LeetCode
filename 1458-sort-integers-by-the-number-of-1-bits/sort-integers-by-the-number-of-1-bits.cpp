class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = (int) arr.size();
        vector<int> c(n);
        for (int i = 0; i < n; i++) {
            c[i] = __builtin_popcount(arr[i]);
        }

        vector<int> id(n, 0);
        iota(begin(id), end(id), 0);

        sort(begin(id), end(id), [&](int x, int y) -> bool {
            return c[x] == c[y] ? arr[x] < arr[y] : c[x] < c[y];
        });

        for (int i = 0; i < n; i++) {
            id[i] = arr[id[i]];
        }
        return id;
    }
};