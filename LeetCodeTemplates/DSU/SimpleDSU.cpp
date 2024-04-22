template <typename T> struct dsu {
    vi par, siz;
    T comp;
    dsu(T n) {
        comp = n;
        par.resize(n+1); siz.resize(n+1);
        rep(i,n+1) {par[i]=i,siz[i]=1;}
    }
    int get(int i){
        return par[i] = (i == par[i] ? i : get(par[i]));
    }
    void unite(int i, int j) {
        i=get(i),j=get(j);
        if(i==j)return;
        if(siz[i]<siz[j])swap(i,j);
        siz[i]+=siz[j];
        par[j]=i;
        comp--;
    }
};
