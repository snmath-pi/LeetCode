class Solution {
public:
    const int L = 7;
    int countPairs(vector<int>& nums) {
        sort(begin(nums), end(nums));
        unordered_map<string, int> mp, id;
        int ans = 0;
        int uler = 1;
        for(auto &x: nums) {
            string s;
            for(int j = 0; j < L; j++) {
                s += (x % 10) + '0';
                x /= 10;
            }
            reverse(s.begin(), s.end()); 
            
            ans += mp[s];
            mp[s]++;
            id[s] = uler;
            
            for(int i = 0; i < L; i++) {
                for(int j = i + 1; j < L; j++) {
                    if(s[i] == s[j]) continue;
                    swap(s[i], s[j]);
                    if(id[s] < uler) {
                        id[s] = uler;
                        mp[s]++;
                    }
                    for(int k = i; k < L; k++) {
                        for(int l = k + 1; l < L; l++) {
                            if(s[k] == s[l]) continue;
                            swap(s[k], s[l]);
                            if(id[s] < uler) {
                                id[s] = uler;
                                mp[s]++;
                            }
                            swap(s[k], s[l]);
                        }
                    }
                    swap(s[i], s[j]);
                }
            }
            uler++;
        }
        return ans;
    }
};
