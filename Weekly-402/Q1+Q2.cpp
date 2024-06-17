class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        for(int i=0; i<hours.size(); i++) {
            hours[i]%=24;
        }
        // 12 12 6 0 0
        map<int, int> mp;
        long long ans = 0;
        for(int i=0; i<(int) hours.size(); i++) {
            int req = (24-hours[i]+24)%24;
            ans += mp[req];
            mp[hours[i]]++;
        }
        return ans;
    }
};
