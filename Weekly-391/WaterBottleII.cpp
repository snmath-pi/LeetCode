class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int res = numBottles;
        int cnt = 0;
        while(true) {
            bool ok = 0;
            while(numBottles - numExchange >= 0) {
                numBottles -= numExchange;
                cnt++;
                numExchange++;
                ok = 1;
            }
            if(!ok) break;
            res += cnt;
            numBottles += cnt;
            cnt = 0;

        }
        return res;
    }
};
