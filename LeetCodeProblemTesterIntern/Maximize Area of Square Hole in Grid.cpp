class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int cur1 = 1, cur2 = 1;
        sort(begin(hBars), end(hBars));
        sort(begin(vBars), end(vBars));
        for(int i=1, j = 1, k = 1; i<hBars.size(); i++) {
            if(hBars[i] == hBars[i-1]+1) j++, cur1 = max(cur1, j);
            else j = 1;
        }

        for(int i=1, k=1; i < vBars.size(); i++) {
            if(vBars[i] == vBars[i-1]+1)k++,cur2=max(cur2,k);
            else k=1;
        }
        return pow(min(cur1,cur2) + 1, 2);
    }
};
