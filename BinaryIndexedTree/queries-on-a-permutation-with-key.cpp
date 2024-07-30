class BIT {
private:
    int n;
    vector<int> tree;
public:
    BIT(int size): n(size) {
        tree.resize(n);
    }
    void update(int x, int delta) {
        for(; x<=n; x+=(x&(-x)))tree[x]+=delta;
    }
    int query(int x) {
        int sum = 0;
        for(;x>0;x-=(x&(-x)))sum+=tree[x];
        return sum;
    }
};
class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        // 1 2 3 4 5 
        // (3) (5) 1 2 4
        // 1 2 3 4 5
        // (3) 1 2 4 5 
        // (1) (3) 2 4 5   
        BIT b(2*m+1);
        map<int, int> mp;
        for(int i=1;i<=m;i++){
            b.update(i+m, 1);
            mp[i]=i+m;
        }
        int nval=m;
        vector<int> ans;
        for(auto x: queries) {
            int i = mp[x];
            ans.push_back(b.query(i-1));
            mp[x]=nval;
            b.update(i, -1);
            b.update(nval, 1);
            nval--;
        }
        return ans;
    }
};
