class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
        int ans = 0;
        int n = (int) mat.size(), m = (int) mat[0].size();
        for (int i = 0; i < n; i++) {
            int xr = 0, id = -1;
            for (int j = 0; j < m; j++) {
                if (mat[i][j]) id = j;
                xr += mat[i][j];
            }
            if (xr != 1) continue;
            xr = 0;
            for (int j = 0; j < n; j++) {
                xr += mat[j][id];
            }
            if (xr != 1) continue;
            ans++;
        }

        return ans;
    }
};