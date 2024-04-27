
class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for(int i=0; i<grid.size(); i++) for(int j=0; j<grid[0].size(); j++) {
            int cnt = (grid[i][j]=='W');
            if(i+1<grid.size()&&j+1<grid[0].size()) {
                if(i+1&&grid[i+1][j]=='W')cnt++;
            if(j+1&&grid[i][j+1]=='W')cnt++;
            if(i+1&&j+1&&grid[i+1][j+1]=='W')cnt++;
            if(cnt>=3||cnt<=1)return true;
            }
        }
        return false;
    }
};
