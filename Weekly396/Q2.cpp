class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int res = word.size() / k - 1;
        map<string, int> mp;
        for(int i=0; i<word.size(); i+=k) {
            string s="";
            for(int j=i; j<i+k; j++) s += word[j]; 
            mp[s]++;
        }
        
        for(auto &x: mp) {
            res = min(res, (int) word.size() / k - x.second);
        }
        return res;
    }
};
