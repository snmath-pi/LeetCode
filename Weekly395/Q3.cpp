#define ll long long
class Solution {
public:
    long long minEnd(int n, int x) {
        ll m = x;
        vector<int> a;
        for(int i=0; i<=30; i++) {
            if(x >> i & 1) {
                continue;
            } else {
                a.push_back(i);
            }
        }
        for(int i=31;i<50;i++)a.push_back(i);
        ll k = n-1;
        for(int i=0;i<a.size();i++) {
            if(k>>i&1) m|=(1ll<<a[i]);
        }
        return m;
        
    }
};
