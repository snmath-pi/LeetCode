class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        set<int> s; for(auto x: points) s.insert(x[0]);
        int now = *s.begin(), res = 1;
        for(auto x: s) {
            if(x-now<=w) continue;
            else {
                res++;
                now = x;
            }
        }
        return res;
    }
};
