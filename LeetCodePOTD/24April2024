class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> S;
        for(auto x: deadends) S.insert(x);

        unordered_map<string, vector<string>> g;
        unordered_map<string, int> mp;

        for(char a = '0'; a <= '9'; a++) for(char b = '0'; b <= '9'; b++) {
            for(char c = '0'; c <= '9'; c++) for(char d = '0'; d <= '9'; d++) {
                string X = ""; X+=a, X+=b,X+=c,X+=d;
                mp[X] = 1e9;
                for(int i=0;i<4;i++) {
                    int val = (X[i]-'0');
                    val = (val + 1) % 10;
                    string Y = X;
                    Y[i] = (char)(val + '0');
                    if(S.find(Y) == S.end())
                        g[X].push_back(Y);
                    val = (X[i]-'0'); val = (val - 1 + 10) % 10;
                    Y = X; Y[i] = (val + '0');
                    if(S.find(Y) == S.end()) 
                        g[X].push_back(Y); 
                }
            }
        }
        queue<string> pq;
        if(S.count("0000")) return -1;
        pq.push("0000");
        mp["0000"] = 0;
        unordered_map<string, bool> vis;
        vis["0000"] = 1;
        while(!pq.empty()) {
            auto v = pq.front(); pq.pop();
            for(auto u: g[v]) {
                if(!vis[u]) {
                    mp[u] = mp[v] + 1;
                    vis[u] = 1;
                    pq.push(u);
                }
            }
        }
        return !S.count(target) && mp[target] == 1e9 ? -1 : mp[target];
    }
};
