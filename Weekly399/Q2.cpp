class Solution {
public:
    string compressedString(string word) {
        string res = "";
        
        int n = word.size();
        for(int i=0; i<n; i++) {
            char c = word[i]; int cnt = 0;
            for(;i < n && c == word[i];) cnt++, i++;
            string tmp1 = "9"; tmp1 += c;
            string tmp2 = ""; tmp2 += (char)(cnt%9+'0'); tmp2 += c;
            for(int j=0; j<cnt/9; j++) res += tmp1;
            if(cnt%9) res += tmp2;
            i--;
        }
        return res;
    }
};
