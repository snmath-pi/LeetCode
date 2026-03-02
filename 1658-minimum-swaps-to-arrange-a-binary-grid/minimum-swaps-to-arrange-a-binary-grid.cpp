class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = n - 1; j >= 0 && grid[i][j] == 0; j--) {
                cnt++;
            }
            a[i] = cnt;
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            int target = n - 1 - i; 
            int found_idx = -1;

            for (int j = i; j < n; j++) {
                if (a[j] >= target) {
                    found_idx = j;
                    break;
                }
            }

            if (found_idx == -1) return -1;

            
            res += (found_idx - i);
            while (found_idx > i) {
                swap(a[found_idx], a[found_idx - 1]);
                found_idx--;
            }
        }

        return res;
    }
};