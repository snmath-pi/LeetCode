class DetectSquares {
public:
    map<pair<int, int>, int> mp;
    int dx[4] = {1, 1, -1, -1};
    int dy[4] = {1, -1, 1, -1};
    bool chk(int x, int y) {
        return x >= 0 && y >= 0 && x <= 1000 && y <= 1000;
    }
    DetectSquares() {
        mp.clear();
    }
    
    void add(vector<int> point) {
        mp[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int x = point[0], y = point[1], res = 0;
        
        for(auto Y: mp) {
            auto [u, v] = Y.first;
            if(abs(x-u) == abs(y-v) && abs(x-u) != 0) {
                res += Y.second * mp[{u, y}] * mp[{x, v}];
            }
        }
        return res;
        
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
