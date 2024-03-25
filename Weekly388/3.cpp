
class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        vector<string> res(n);
        vector<set<string>> all(n);
        int iter = 0;
        for(auto &u: arr) {
            
            for(int i=0; i<u.size(); i++) {
                string res;
                for(int j=i; j < u.size(); j++) {
                    res += u[j];
                    all[iter].insert(res);
                }
            }
            iter++;
            
        }
        
        for(int i=0; i<n; i++) {
            string ret = "";
            for(auto &str: all[i]) {
                bool ok = 1;
                for(int j=0;j<n;j++) {
                    if(i!=j && all[j].count(str)) {
                        ok = 0; break;
                    }
                }
                if(ok) {
                    if(ret == "") ret = str;
                    else {
                        if(str.size() < ret.size()) ret = str;
                        else if(str.size() == ret.size()) {
                            ret = min(ret, str);
                        }
                    }
                }
            }
            res[i] = ret;
        }
        return res;
    }
};
