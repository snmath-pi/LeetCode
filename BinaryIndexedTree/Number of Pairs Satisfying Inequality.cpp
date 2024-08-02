class Solution {
public:
    vector<long long> tree;
    void update(int x, int delta) {
        for(;x<1000010;x+=(x&(-x)))tree[x]+=delta;
    }
    int query(int x){
        long long val=0;
        for(;x>0;x-=(x&(-x)))val+=tree[x];
        return val;
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        tree.resize(1e6+10);
        int n = nums1.size();
        vector<int> A(n);
        for(int i=0; i<n; i++) {
            A[i]=nums1[i]-nums2[i]+100000;
        }
        diff+=100000;

        long long ans = 0;
        for(int i=0;i<n;i++) {
            ans+=query(A[i]+diff);
            update(A[i]+100000,1);
        }
        return ans;
    }
};
