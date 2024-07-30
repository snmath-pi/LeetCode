class BIT {
private:
    int n;
    vector<int> bit;
public:
    BIT(int size): n(size){bit.resize(n);}
    void update(int x, int delta) {
        for(;x<n;x+=(x&(-x)))bit[x]+=delta;
    }
    int query(int x){
        int sum = 0;
        for(;x>0;x-=(x&(-x))) sum+=bit[x];
        return sum;
    }
};
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        map<int, int> mp, lmao;
        set<int> s; 
        for(auto &x: people) {
            s.insert(x[0]);
        }
        int num = 1;
        for(auto x: s) {
            mp[x]=num++;
            lmao[num-1]=x;
        }
        for(int i=0;i<people.size();i++)people[i][0]=mp[people[i][0]];
        sort(begin(people),end(people), [&](vector<int> &x, 
                vector<int>&y) {
                return x[1]==y[1] ? x[0] < y[0] : x[1] < y[1];
        });

        BIT bit(num+1);

        int n = people.size();
        for(int i=0; i<n; i++) {
            int val = bit.query(num)-bit.query(people[i][0]-1);
            
            if(val == people[i][1]) {
                bit.update(people[i][0], 1);
                continue;
            }
            // cout << people[i][0] << ' ' << people[i][1] << ' ' << val << '\n';
            for(int j=i-1; j>=0; j--) {
                bit.update(people[j][0], -1);
                int val = bit.query(num)-bit.query(people[i][0]-1);
                if(val == people[i][1]) {
                    // cout << "# " << people[i][0] << ' ' << people[i][1] << ' ' << val << '\n';
                    auto x = people[i];
                    for(int k=i;k>j;k--) {
                        people[k]=people[k-1];
                        bit.update(people[k][0], 1);
                    }
                    people[j]=x;
                    bit.update(x[0],1);
                    break;
                }
            }
        }
        for(auto &x: people)x[0]=lmao[x[0]];
        return people;

    }
};
