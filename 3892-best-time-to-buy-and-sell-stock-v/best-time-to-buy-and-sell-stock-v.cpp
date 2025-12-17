#include <algorithm>
#include <stack>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define per(i, n) for (int i = n - 1; i >= 0; --i)
#define repn(i, n) for (int i = 1; i <= n; ++i)
#define rng(i, a, b) for (int i = a; i < b; i++)
#define gnr(i, a, b) for (int i = b - 1; i >= a; --i)
#define vb vector<bool>
#define vi vector<int>
#define vl vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vvb vector<vb>
#define vvi vector<vi>
#define vvl vector<vl>
#define vvc vector<vc>
#define si unordered_set<int>
#define sl unordered_set<ll>
#define tsi set<int>
#define tsl set<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define tmii map<int, int>
#define tmll map<ll, ll>
#define mii unordered_map<int, int>
#define mll unordered_map<ll, ll>
#define pqi priority_queue<int>
#define pqig priority_queue<int, vi, greater<int>>
#define pql priority_queue<ll>
#define pqlg priority_queue<ll, vl, greater<ll>>
#define pqpii priority_queue<pii>
#define pqpll priority_queue<pll>
#define pqip priority_queue<pair<int, pair<int, int>>>
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()
#define lb lower_bound
#define ub upper_bound
#define ll long long
#define ull unsigned long long
#define ld long double
#define nl '\n'
#define sp ' '
#define fi first
#define inf 8e18;
#define sinf 2e9;
#define se second
#define mpr make_pair
#define lg __lg
#define sum(a) (accumulate((a).begin(), (a).end(), 0ll))
#define mine(a) (*min_element((a).begin(), (a).end()))
#define maxe(a) (*max_element((a).begin(), (a).end()))
#define mini(a) (min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a) (max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) (lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) (upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

using namespace std;
/* ありがとう、神様、あなたはとても素晴らしく 、とても優しいです！*/
#ifndef ONLINE_JUDGE
#define dbg(x)        \
    cerr << #x << sp; \
    use_(x);          \
    cerr << nl;
#else
#define dbg(x)
#endif

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
typedef tree<pii, null_type, less<pii>, rb_tree_tag,
             tree_order_statistics_node_update>
    mordered_set;

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// customHash working with UMP
struct hsh
{
    size_t operator()(const pair<ll, ll> &p) const
    {
        return p.first * 239 + p.second; // you could change 239 to 1e9+1
    }
};

template <typename T, typename U>
void umin(T &a, U b)
{
    if (a > b)
        a = b;
}
template <typename T, typename U>
void umax(T &a, U b)
{
    if (a < b)
        a = b;
}

template <typename T, typename V>
T rangeBitwiseAnd(T left, V right)
{
    T res = 0;
    int cnt = 0;
    for (; left >= (1ll << cnt); cnt++)
    {
    }
    if (1ll << cnt <= right)
        return 0;
    if (left == right)
        return left;

    res += 1ll << (--cnt);
    left -= 1ll << (cnt);
    right -= 1ll << cnt;
    return res + rangeBitwiseAnd(left, right);
}

template <typename T>
T MSB(T n)
{
    T ans = -1;
    while (n)
        n /= 2, ans++;
    return ans;
}
template <typename T>
T rangeBitwiseOr(T l, T r)
{
    ll res = 0;
    ll u = MSB(l), v = MSB(r);
    while (u == v && u >= 0 && v >= 0)
    {
        ll val = (1ll << u);
        l -= val, r -= val;
        res += val;
        u = MSB(l), v = MSB(l);
    }
    u = max(MSB(l), MSB(r));
    res += (1ll << (u + 1)) - 1;
    return res;
}

template <typename T>
T XOR1(T n)
{
    ll md = n % 4;
    if (!md)
        return n;
    else if (md == 1)
        return 1;
    else if (md == 2)
        return n + 1;
    return 0;
}
template <typename T>
T rangeBitwiseXor(T l, T r) { return XOR1(r) ^ XOR1(l - 1); }

int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
int kx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int ky[] = {2, -2, 2, -2, 1, -1, 1, -1};
set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

bool chkpalin(string s)
{
    rep(i, sz(s) / 2)
    {
        if (s[i] != s[sz(s) - i - 1])
            return false;
    }
    return true;
}
map<char, vector<char>> phone_keypad{
    {'2', {'a', 'b', 'c'}},
    {'3', {'d', 'e', 'f'}},
    {'4', {'g', 'h', 'i'}},
    {'5', {'j', 'k', 'l'}},
    {'6', {'m', 'n', 'o'}},
    {'7', {'p', 'q', 'r', 's'}},
    {'8', {'t', 'u', 'v'}},
    {'9', {'w', 'x', 'y', 'z'}}};
vi GPRM(int N)
{
    vi x(N + 10, 1), primes;
    x[0] = x[1] = 0;
    rng(i, 2, N + 5)
    {
        if (!x[i])
            continue;
        for (int j = i + i; j < N + 5; j += i)
            x[j] = 0;
    }
    rep(i, N + 10)
    {
        if (x[i])
            primes.pb(i);
    }
    return primes;
}
vector<string> slice_fn(string &s, char c)
{
    string tmp = "";
    vector<string> res;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == c)
        {
            if (tmp.empty())
                continue;
            res.push_back(tmp);
            tmp.clear();
        }
        else
            tmp += s[i];
    }
    if (!tmp.empty())
        res.push_back(tmp);
    return res;
}
long long int_sqrt(long long x)
{
    long long ans = 0;
    for (ll k = 1LL << 30; k != 0; k /= 2)
    {
        if ((ans + k) * (ans + k) <= x)
        {
            ans += k;
        }
    }
    return ans;
}

void yesnoc(bool a) { cout << (a ? "YES\n" : "NO\n"); }
void yesnos(bool a) { cout << (a ? "Yes\n" : "No\n"); }

// Debug デバッグ
void use_(ll W) { cerr << W; }
void use_(ld W) { cerr << W; }
void use_(char W) { cerr << W; }
void use_(string W) { cerr << W; }
void use_(int W) { cerr << W; }
void use_(double W) { cerr << W; }
template <typename T, typename V>
void use_(pair<T, V> p)
{
    cerr << "[";
    use_(p.fi);
    cerr << ',';
    use_(p.se);
    cerr << ']';
}
template <typename T>
void use_(vector<T> a)
{
    cerr << '[';
    for (T i : a)
    {
        use_(i);
        cerr << sp;
    }
    cerr << ']';
    cerr << nl;
}
template <typename T>
void use_(set<T> a)
{
    cerr << '[';
    for (T i : a)
    {
        use_(i);
        cerr << sp;
    }
    cerr << ']';
    cerr << nl;
}
template <typename T>
void use_(multiset<T> ms)
{
    cerr << '[';
    for (T i : ms)
    {
        use_(i);
        cerr << sp;
    }
    cerr << ']';
    cerr << nl;
}
template <typename T, typename V>
void use_(map<T, V> mp)
{
    cerr << '[';
    for (auto x : mp)
    {
        use_(x.fi);
        cerr << ',';
        use_(x.se);
        cerr << sp;
    }
    cerr << ']';
    cerr << nl;
}
template <typename T>
void use_(priority_queue<T> pq)
{
    cerr << '[';
    vector<T> tmp;

    while (sz(pq))
    {
        tmp.pb(pq.top());
        pq.pop();
    }
    use_(tmp);
    cerr << ']';
    cerr << nl;
}
template <typename T>
void use_(priority_queue<T, vector<T>, greater<T>> pq)
{
    cerr << '[';
    vector<T> tmp;
    while (sz(pq))
    {
        tmp.pb(pq.top());
        pq.pop();
    }
    use_(tmp);
    cerr << ']';
    cerr << nl;
}
template <typename T>
void use_(queue<T> pq)
{
    cerr << '[';
    vector<T> tmp;
    while (sz(pq))
    {
        tmp.pb(pq.top());
        pq.pop();
    }
    use_(tmp);
    cerr << ']';
    cerr << nl;
}
template <typename T>
void use_(stack<T> pq)
{
    cerr << '[';
    vector<T> tmp;
    while (sz(pq))
    {
        tmp.pb(pq.top());
        pq.pop();
    }
    use_(tmp);
    cerr << ']';
    cerr << nl;
}
#define trace1(x) cerr << #x << ": " << (x) << nl;
#define trace2(x, y) cerr << #x << ": " << (x) << " | " << #y << ": " << (y) << nl;
#define trace3(x, y, z) cerr << #x << ": " << (x) << " | " << #y << ": " << (y) << " | " << #z << ": " << (z) << nl;
#define trace4(a, b, c, d) cerr << #a << ": " << (a) << " | " << #b << ": " << (b) << " | " << #c << ": " << (c) << " | " << #d << ": " << (d) << nl;
#define trace5(a, b, c, d, e) cerr << #a << ": " << (a) << " | " << #b << ": " << (b) << " | " << #c << ": " << (c) << " | " << #d << ": " << (d) << " | " << #e << ": " << (e) << nl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << (a) << " | " << #b << ": " << (b) << " | " << #c << ": " << (c) << " | " << #d << ": " << (d) << " | " << #e << ": " << (e) << " | " << #f << ": " << (f) << nl;

// Read 読む
template <typename T>
vector<vector<T>> RG(T n, T m)
{
    vector<vector<T>> g(n);
    rep(i, m)
    {
        int u, v;
        cin >> u >> v;
        g[--u].pb(--v);
        g[v].pb(u);
    }
    return g;
}
template <typename T>
vector<vector<T>> RDG(T n, T m)
{
    vector<vector<T>> g(n);
    rep(i, m)
    {
        int u, v;
        cin >> u >> v;
        g[--u].pb(--v);
    }
    return g;
}
template <typename T>
vector<vector<pair<T, T>>> RGW(T n, T m)
{
    vector<vector<pair<T, T>>> g(n);
    rep(i, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[--u].pb({--v, w});
        g[v].pb({u, w});
    }
    return g;
}
template <typename T>
vector<T> R(T n)
{
    vector<T> a(n);
    rep(i, n) cin >> a[i];
    return a;
}

// Print 印刷する debuggers for standard output
template <typename T>
void print(T x) { cout << x << '\n'; }
template <typename T, typename... Args>
void print(T first, Args... args)
{
    std::cout << first;
    if constexpr (sizeof...(args) > 0)
    {
        std::cout << ' ';
        print(args...);
    }
    else
    {
        std::cout << '\n';
    }
}
template <typename T>
void printA(vector<T> &A)
{
    for (auto &x : A)
    {
        cout << x << ' ';
    }
    cout << '\n';
}
template <typename T>
void printA2(vector<vector<T>> &A)
{
    for (auto x : A)
    {
        for (auto y : x)
        {
            cout << y << ' ';
        }
        cout << '\n';
    }
}
template <typename T>
void printS(set<T> &S)
{
    for (auto &x : S)
        cout << x << ' ';
    cout << '\n';
}
template <typename T>
void printmulS(multiset<T> &MS)
{
    for (auto &x : MS)
        cout << x << ' ';
    cout << '\n';
}
template <typename T>
void printQueue(queue<T> &Q)
{
    queue<T> tempQ = Q;
    while (!tempQ.empty())
    {
        cout << tempQ.front() << ' ';
        tempQ.pop();
    }
    cout << '\n';
}
template <typename T>
void printStack(stack<T> &ST)
{
    stack<T> tempStack = ST;
    while (!tempStack.empty())
    {
        cout << tempStack.top() << ' ';
        tempStack.pop();
    }
    cout << '\n';
}
template <typename T>
void printPQ(priority_queue<T> &PQ)
{
    priority_queue<T> tempPQ = PQ;
    while (!tempPQ.empty())
    {
        cout << tempPQ.top() << ' ';
        tempPQ.pop();
    }
    cout << '\n';
}
template <typename T>
void printPQG(priority_queue<T, vector<T>, greater<T>> &PQG)
{
    priority_queue<T, vector<T>, greater<T>> tempPQ = PQG;
    while (!tempPQ.empty())
    {
        cout << tempPQ.top() << ' ';
        tempPQ.pop();
    }
    cout << '\n';
}

ll n, k, m, q;
// const ll mod = 998244353;
const ll mod = 1000000007;
const int N = 1e3 + 10;
ll dp[N][N][2][2];
class Solution
{
public:
    long long maximumProfit(vector<int> &prices, int k)
    {
        n = sz(prices);
        memset(dp, -1, sizeof(dp));
        function<ll(int, int, int, int)> dfs = [&](int i, int k, int md, int prest) -> ll
        {
            if (i == n)
                return prest ? LLONG_MIN / 4 : 0;
            if (k == 0 && prest)
                return LLONG_MIN / 4;

            ll &res = dp[i][k][md][prest];
            if (res != -1)
                return res;

            res = dfs(i + 1, k, md, prest);

            if (prest == 0)
            {
                res = max(res, -prices[i] + dfs(i + 1, k, 0, 1)); 
                res = max(res, prices[i] + dfs(i + 1, k, 1, 1)); 
            }
            else
            {
                if (md == 0)
                    res = max(res, prices[i] + dfs(i + 1, k - 1, 0, 0));
                else
                    res = max(res, -prices[i] + dfs(i + 1, k - 1, 0, 0));
            }

            return res;
        };

        return dfs(0, k, 0, 0);
    }
};