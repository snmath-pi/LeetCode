class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int val = 0;
        sort(rbegin(capacity), rend(capacity));
        int tot = accumulate(begin(apple), end(apple), 0);
        for(int i=0; i<capacity.size(); i++) {
            val += capacity[i];
            if(val >= tot) return i + 1;
        }
        return capacity.size();
    }
};
