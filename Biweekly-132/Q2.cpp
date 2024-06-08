class Solution {
public:
    int findWinningPlayer(vector<int>& a, int k) {
        int n = a.size();
        int mx = 0;
        for(int i=0; i<n; i++) mx = max(mx, a[i]);
        
        deque<int> dq;
        for(int i=0; i<n; i++) dq.push_back(a[i]);
        map<int, int> id;
        for(int i=0; i<n; i++) {
            id[a[i]] = i;
        }
        map<int, int> mp;
        while(true) {
            int v = dq.front(); dq.pop_front();
            int u = dq.front(); dq.pop_front();
            if(v<u)swap(v, u);
            dq.push_back(u);
            dq.push_front(v);
            mp[v]++;
            if(mp[v]==k) {
                return id[v];
            }
            if(v == mx) return id[mx];
        }
        return -1;
    }
};
