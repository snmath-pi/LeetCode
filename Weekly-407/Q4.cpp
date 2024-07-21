class Solution {
public:
    long long solve(vector<int> &x) {
        long long ans = abs(x[0]);
        for(int i=1;i<x.size();i++){
            ans+=max(abs(x[i])-abs(x[i-1]),0);
        }
        return ans;
    }
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        vector<int> diff(n);
        for(int i=0; i<n; i++)diff[i]=nums[i]-target[i];
        
        vector<vector<int>> neg, pos;
        vector<int> tmp;
        
        for(int i=0; i<n; i++) {
            if(diff[i]<0) {
                tmp.clear();
                while(i<n&&diff[i]<0) tmp.push_back(diff[i++]);
                neg.push_back(tmp);
                i--;
            }else if(diff[i]>0){
                tmp.clear();
                while(i<n&&diff[i]>0) tmp.push_back(diff[i++]);
                pos.push_back(tmp);
                i--;
            }
        }
        long long tot=0;
        for(auto x: pos) {
            // for(auto c: x)cout<<c<<' ';cout<<'\n';
            tot+=solve(x);
        }
        for(auto y: neg){
            // for(auto c: y)cout<<c<<' ';cout<<'\n';
            tot+=solve(y);
        }
        return tot;
        
        
    }
};
