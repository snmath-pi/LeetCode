class Solution {
public:
    char findKthBit(int n, int k) {
        int inv = 0;
        while (k > 1 && (k & (k - 1)) != 0) {
            int p = (1 << (31 - __builtin_clz(k)));
            k = p - (k - p);
            inv++;
        }

        char res = (k == 1 ? '0': '1');
        return res ^ (inv % 2);
    }
};