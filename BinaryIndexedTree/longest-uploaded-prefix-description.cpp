int m;
vector<int> bit;
void update(int x) {
    for(;x<=m;x+=(x&(-x)))bit[x]+=1;
}
int query(int x){
    int sum=0;
    for(;x>0;x-=(x&(-x)))sum+=bit[x];
    return sum;
}
class LUPrefix {
public:
    LUPrefix(int n) {
        m=n;
        bit.clear();
        bit.resize(n+1);
    }
    
    void upload(int video) {
        update(video);
    }
    
    int longest() {
        int l = -1, r = m+1;
        for(int mid; r>l+1;){
            mid=(l+r)/2;
            int val = query(mid);
            if(val==mid) l=mid;
            else r=mid;
        }
        return l;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
