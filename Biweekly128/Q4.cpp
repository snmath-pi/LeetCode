class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        map<int, int> mp;
        long long res = 0;
        stack<int> st;
        for(int i = 0; i < nums.size(); i++) {
            while(!st.empty() && nums[st.top()] < nums[i]) {
                mp.erase(nums[st.top()]);
                st.pop();
            }
            res += mp[nums[i]];
            st.push(i);
            mp[nums[i]]++;
        }
        return res + nums.size();
    }
};
