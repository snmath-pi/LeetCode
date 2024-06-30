
class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int res1 = 0, res2 = 0;
        int ok = 1;
        int cur1 = 1, cur2 = 2;
        int ored = red,oblue=blue;
        while(true) {
            if(ok) {
                if(red>=cur1) {
                    red-=cur1;
                    cur1+=2;
                    
                    res1++;
                } else break;
            } else {
                if(blue>=cur2) {
                    blue-=cur2;
                    cur2+=2;
                    
                    res1++;
                } else break;
            }
            ok^=1;
        }
        cur1=2,cur2=1;
        ok=0;
        red=ored,blue=oblue;
        while(true) {
            if(ok) {
                if(red>=cur1) {
                                        red-=cur1;

                    cur1+=2;
                    res2++;
                } else break;
            } else {
                if(blue>=cur2) {
                                        blue-=cur2;

                    cur2+=2;
                    res2++;
                } else break;
            }
            ok^=1;
        }
        return max(res1, res2);

    }
};
