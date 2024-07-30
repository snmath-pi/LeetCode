
// bit template @math_pi
#define ll long long
class BIT
{
private:
    int n;
    vector<ll> tree;

public:
    BIT(int size) : n(size)
    {
        tree.resize(n + 1);
    }
    // adds a value 'delta' at index 'x'
    void update(int x, int delta)
    {
        for (; x <= n; x += (x & (-x)))
            tree[x] += delta;
    }
    // returns the sum of first x elements of the array
    ll query(int x)
    {
        ll sum = 0;
        for (; x > 0; x -= (x & (-x)))
            sum += tree[x];
        return sum;
    }
};

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int mx = 0;
        for(int i=0; i<n; i++) mx = max(mx, rating[i]);

        BIT left(mx+1), right(mx+1);
        int ans = 0;

        for(auto val: rating) right.update(val, 1);
        left.update(rating[0], 1);
        for(int i=1; i<n; i++) {
            right.update(rating[i-1], -1);
            int lsmall = left.query(rating[i]-1);
            int rbig = right.query(mx)-right.query(rating[i]);
            ans += lsmall*rbig;
            int lbig = left.query(mx)-left.query(rating[i]);
            int rsmall = right.query(rating[i]-1);
            ans += lbig*rsmall;
            left.update(rating[i], 1);

        }
        return ans;
    }
};
