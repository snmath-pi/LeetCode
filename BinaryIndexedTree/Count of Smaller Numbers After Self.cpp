class BIT {
private:
    int n;
    vector<int> tree;
public:
    BIT(int size) {
        n=size;
        tree.resize(n);
    }
    void update(int x, int delta) {
        for(; x<n; x+=(x&(-x))) tree[x]+=delta;
    }
    int query(int x) {
        int sum = 0;
        for(;x>0;x-=(x&(-x)))sum+=tree[x];
        return sum;
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> a;
        for(auto x: nums)a.push_back(x);
        map<int, int> mp;
        sort(begin(nums), end(nums));
        int num = 1;
        for(auto x: nums){
            if(mp.count(x)==0)mp[x]=num++;
        }
        
        BIT bit(num);
        for(auto &x: a)x=mp[x];
        
        vector<int> ans;
        for(int i=a.size()-1;i>=0; i--) {
            int x = a[i];
            ans.push_back(bit.query(x-1));
            bit.update(x,1);
        }
        reverse(begin(ans),end(ans));
        return ans;

    }
};
