class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;
        for(int i=0; i<n/2; i++) {
            if(nums[i]>nums[n-i-1]) {
                swap(nums[i], nums[n-i-1]);
            }
            mp[nums[n-i-1]-nums[i]]++;
        }
        // for(auto x: nums)cout<<x<< ' ';cout<<'\n';
        int cnt = 0, val = -1, cnt2=0,val2=-1;
        for(auto [x, y]: mp) {
            if(y>cnt) {
                cnt=y;
                val=x;
            } 
        }
        for(auto [x, y]: mp) {
            if(y<cnt) {
                if(y>cnt2){
                    cnt2=y;
                    val2=x;
                }
            } 
        }
        
        // for(auto [x, y]: mp) {
        //     cout << "x: " << x << "y: "<<y<<' ';
        // }
        // cout<<'\n';
        // cout<<val<< '#' << val2 << '\n';
        int res=0;
        for(int i=0; i<n/2;i++) {
            if(nums[n-i-1]-nums[i]==val)continue;
            if(val+nums[i]<=k)res++;
            else if(nums[n-i-1]-val>=0)res++;
            else res+=2;
        }
        int res2=0;
        if(val2==-1)return res;
        for(int i=0; i<n/2;i++) {
            if(nums[n-i-1]-nums[i]==val2)continue;
            if(val2+nums[i]<=k)res2++;
            else if(nums[n-i-1]-val2>=0)res2++;
            else res2+=2;
        }
        
        return min(res2,res);
        
        
    }
};
