class Solution {
public:
    int minPartitions(string n) {
        char c = *max_element(begin(n), end(n));
        return (c - '0');
    }
};