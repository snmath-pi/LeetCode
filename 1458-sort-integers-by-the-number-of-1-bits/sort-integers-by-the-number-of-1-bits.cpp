class Solution {
public:

    static int hammingWeight(int num) {
        int wei = 0, mask = 1;
        while (num) {
            wei++;
            num &= (num - 1);
        }
        return wei;
    }

    static bool comp(int a, int b) {
        int x = hammingWeight(a);
        int y = hammingWeight(b);

        return (x == y ? a < b : x < y);
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(begin(arr), end(arr), comp);
        return arr;
    }
};