class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        long long res = 0;
        int n = grid.size(), m = grid[0].size();
        vector<long long> row(n), col(m);
        for(int i=0; i<n; i++) {
            row[i] = count(begin(grid[i]), end(grid[i]), 1);
        }
        for(int j=0; j<m; j++) {
            int cnt = 0;
            for(int i=0; i<n; i++) {
                cnt += (grid[i][j]==1);
            }
            col[j] = cnt;
        }
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
            if(grid[i][j] == 1) {
                res += (row[i]-1)*(col[j]-1);
            }
        }
        return res;
    }
};
