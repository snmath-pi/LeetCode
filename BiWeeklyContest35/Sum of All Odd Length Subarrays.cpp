class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        
        int sum = 0, n = arr.size();
        
        for(int i = 0; i < n; i++) {
            int cur = 0;
            for(int j = i; j < n; j++) {
                cur += arr[j];
                if((j - i + 1) % 2) sum += cur;
            }
        }
        
        return sum;
    }
};
