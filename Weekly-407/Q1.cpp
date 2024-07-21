class Solution {
public:
    int minChanges(int n, int k) {
        int res = 0;
        for(int i=30; i>=0; i--) {
            if(!(n>>i&1)&&(k>>i&1)){
                return -1;
            } else if(n>>i&1 && !(k>>i&1))res++;
        }
        return res;
    }
};
