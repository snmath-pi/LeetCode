#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

#define ll long long
// bit template @math_pi

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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> a{1, 2, 3, 4, 5};
    BIT bit(a.size());

    for (int i = 1; i <= a.size(); i++)
        bit.update(i, a[i - 1]);

    cout << bit.query(3) << '\n';
    cout << bit.query(4) - bit.query(2) << '\n';

    bit.update(5, 10);
    for (int i = 1; i <= a.size(); i++)
    {
        cout << bit.query(i) << '\n';
    }
}
