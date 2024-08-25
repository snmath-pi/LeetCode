class Solution {
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                string s1 = to_string(nums[i]), s2 = to_string(nums[j]);
                int ok = (nums[i]==nums[j]);

                for(int l = 0; l < s1.size(); l++) {
                    for(int m = l + 1; m < s1.size(); m++) {
                        swap(s1[l], s1[m]);
                        if(stoi(s1) == nums[j]) ok = 1;
                        swap(s1[l], s1[m]);
                    }
                }
                for(int l = 0; l < s2.size(); l++) {
                    for(int m = l + 1; m < s2.size(); m++) {
                        swap(s2[l], s2[m]);
                        if(stoi(s2) == nums[i]) ok = 1;
                        swap(s2[l], s2[m]);
                    }
                }
                ans += ok;
            }
        }
        return ans;
    }
};
