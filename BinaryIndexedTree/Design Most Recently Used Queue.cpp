#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second

class BIT
{
private:
    int n;
    vector<int> bit;

public:
    BIT(int size) : n(size) { bit.resize(n); }
    void update(int x, int delta)
    {
        for (; x <= n; x += (x & (-x)))
            bit[x] += delta;
    }
    int query(int x)
    {
        int sum = 0;
        for (; x > 0; x -= (x & (-x)))
            sum += bit[x];
        return sum;
    }
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    BIT bit(17);
    map<int, int> mp;
    for (int i = 1; i <= 8; i++)
        bit.update(i, 1), mp[i] = i;
    int num = 9;
    for (int i = 0; i < 4; i++)
    {
        int x;
        cin >> x;
        int l = 0, r = 17;
        while (r > l + 1)
        {
            int mid = l + (r - l) / 2;
            int val = bit.query(mid);
            if (val >= x)
                r = mid;
            else
                l = mid;
        }
        cout << mp[r] << '\n';
        mp[num] = mp[r];
        bit.update(x, -1);
        bit.update(num++, 1);
    }
}
