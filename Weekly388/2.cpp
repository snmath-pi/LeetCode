
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long res = 0;
        sort(all(happiness));
        int taken = 0;
        int n = sz(happiness);
        for(int i=n-1; i>=n-k; i--) {
            res += max(0ll, (long long) happiness[i] - taken);
            taken++;
            
        }
        return res;
    }
};
