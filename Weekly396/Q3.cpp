class Solution {
public:
    int minAnagramLength(string s) {
        
        int l = 0, r = s.size() + 1;
        int n = s.size();
        auto good= [&](int val) {
            vector<int> freq(26, 0);
            
            for(int i=0; i<val; i++) freq[s[i]-'a']++;
            set<vector<int>> S;
            S.insert(freq);
            for(int i=val; i<n-val+1;i+=val) {
                freq.assign(26, 0);
                for(int j=i;j<i+val;j++) {
                    freq[s[j]-'a']++;
                }
                S.insert(freq);
                
            }
            return S.size()==1;
        };
        int res = s.size();
        for(int i=1; i*i<=s.size();i++) {
            if(s.size()%i==0) {
                if(good(i)) res = min(res, i);
                if(i!=n/i && good(n/i)) res = min(res, n / i);
            }
        }
        return res;
    }
};
