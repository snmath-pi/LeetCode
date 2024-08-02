class BIT {
    private:
        int n;
        vector<int> tree;
    public:
        BIT(int size):n(size){
            tree.resize(n+1);
        }
        void update(int x, int delta) {
            for(;x<=n;x+=(x&(-x)))tree[x]=max(tree[x], delta);
        }
        int query(int x){
            int sum=0;
            for(;x>0;x-=(x&(-x)))sum=max(sum,tree[x]);
            return sum;
        }
};
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& a) {
        set<int> s(begin(a),end(a));
        int num=1;map<int,int> mp;
        for(auto x: s)mp[x]=num++;
        for(auto &x: a)x=mp[x];

        BIT bit(num);
        int n = a.size();
        vector<int> dp(n);
        for(int i=0;i<n;i++){
            dp[i]=max(1,bit.query(a[i])+1);
            bit.update(a[i], dp[i]);
        }
        return dp;

    }
};
