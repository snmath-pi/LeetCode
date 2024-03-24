class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& a, vector<int>& f) {
        map<int, long long> mp;
        map<long long, long long, greater<long long>> mp2;
        int n = a.size();
        vector<long long> res(n, 0);

        for(int i=0; i<n; i++) {
            if(mp.find(a[i]) == mp.end()) {
                mp[a[i]] = f[i];
                mp2[f[i]]++;
            } else {
                mp2[mp[a[i]]]--; // prev freq
                if(mp2[mp[a[i]]] == 0) mp2.erase(mp[a[i]]);
                mp[a[i]] += f[i]; // changed here
                mp2[mp[a[i]]]++; // then we just update the new freq in freq map
            }
            if(mp2.empty()) continue;
            auto itr = mp2.begin();
            res[i] = itr->first;
        }
        return res;
    }
};
